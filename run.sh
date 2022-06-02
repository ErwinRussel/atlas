#!/bin/bash

# todo: check if restore env variable is there
# todo: see where the file is

# RESTORE
echo $ATL_RESTORE
if [ "$ATL_RESTORE" == "TRUE" ]
then
  echo "Restoring atlas"
  nohup test/Glxgears/dev/atl_lh restore calllog.bin &
  sleep 1
  criu restore
# NOT RESTORE
else
  echo "Running atlas"
  nohup test/Glxgears/dev/atl_lh &
  sleep 1
  LD_PRELOAD=$(pwd)/test/Glxgears/dev/atl_lib.so test/Glxgears/dev/glxgears
fi

trap "echo hello" SIGINT
