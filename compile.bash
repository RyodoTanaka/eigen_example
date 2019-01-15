#!/bin/bash

CURRENT=`pwd`

    if [ "$1" == "clean" ]; then
        source .build.bash clear
        source .build.bash
    else
        source .build.bash
    fi

return $?
