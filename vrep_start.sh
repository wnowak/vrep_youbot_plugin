#!/bin/sh

if [ -z "$VREP_DIR" ]; then
	echo "Environment variable VREP_DIR not set, exiting..."
	exit -1
fi

cd ${VREP_DIR}
bash vrep.sh
