

# todo: check if restore env variable is there
# todo: see where the file is

# RESTORE
#echo $ATL_RESTORE
#if [ "$ATL_RESTORE" == "TRUE" ]
#then
echo "Restoring atlas"
nohup test/Glxgears/dev/atl_lh replay calllog.bin &
echo "$!" > lh_pid
sleep 5
criu restore -v4 --images-dir ./checkpoints --shell-job &
echo "$!" > uh_pid
## NOT RESTORE
#else
#echo "Running atlas"
#nohup strangle 30 test/Glxgears/dev/atl_lh &
#echo "$!" > lh_pid
#sleep 0.5
#LD_PRELOAD=$(pwd)/test/Glxgears/dev/atl_lib.so test/Glxgears/dev/glxgears &
#echo "$!" > uh_pid


