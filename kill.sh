#!/bin/bash

# send the glxgears process a SIGUSER1
UH_PID=`cat uh_pid`
LH_PID=`cat lh_pid`
kill "$UH_PID" || echo "No UH process found to kill"
kill "$LH_PID" || echo "No LH process found to kill"
rm calllog.bin || echo ""