# RESTORE
nohup python3 /opt/strangle/promclient/promclient.py & || echo "Running promclient"
if [ -n "$ATL_RESTORE" ] && [ "$ATL_RESTORE" -eq 1 ]
then
  echo "Restoring atlas"
  nohup strangle 30 test/Glxgears/dev/atl_lh replay checkpoints/calllog.bin >/dev/null 2>&1 &
#  test/Glxgears/dev/atl_lh replay calllog.bin &
  echo "$!" > lh_pid
  sleep 0.3
  criu restore --images-dir ./checkpoints --shell-job -d
# PID should restore the same
#  echo "$!" > uh_pid
## NOT RESTORE
else
  echo "Running atlas"
  nohup strangle 30 test/Glxgears/dev/atl_lh >/dev/null 2>&1 &
#  strangle 30 test/Glxgears/dev/atl_lh &
  echo "$!" > lh_pid
  sleep 0.3
  LD_PRELOAD=$(pwd)/test/Glxgears/dev/atl_lib.so test/Glxgears/dev/glxgears &
  echo "$!" > uh_pid
fi
while :; do
    sleep 5
done