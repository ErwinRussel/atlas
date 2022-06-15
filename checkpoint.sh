#!/bin/bash

# send the glxgears process a SIGUSER1
UH_PID=`cat uh_pid`
LH_PID=`cat lh_pid`
kill -10 "$UH_PID"
kill "$LH_PID"

# MOVE STUFF
