# RESTORE
#nohup python3 /opt/strangle/promclient/promclient.py &
if [ -n "$ATL_RESTORE" ] && [ "$ATL_RESTORE" -eq 1 ]
then
  echo "Restoring atlas"
  nohup strangle 30 test/Glxgears/dev/atl_lh replay checkpoints/calllog.bin >/dev/null 2>&1 &
#  test/Glxgears/dev/atl_lh replay calllog.bin &
  echo "$!" > lh_pid
  sleep 1
  ps aux
  criu restore --images-dir ./checkpoints --shell-job -d
# PID should restore the same
  echo "19" > uh_pid
## NOT RESTORE
else
  echo "Running atlas"
  nohup strangle 30 test/Glxgears/dev/atl_lh >/dev/null 2>&1 &
#  strangle 30 test/Glxgears/dev/atl_lh &
  echo "$!" > lh_pid
  sleep 1
  LD_PRELOAD=$(pwd)/test/Glxgears/dev/atl_lib.so test/Glxgears/dev/glxgears &
  echo "$!" > uh_pid
  ps aux
fi
while :; do
    sleep 5
done
