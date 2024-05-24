#!/bin/sh
source /opt/FriendlyARM/arm-qtopia/qtopia-2.2.0-FriendlyARM/setQpeEnv
qmake -spec qws/linux-arm-g++ -o makefile.target *.pro 
make -f makefile.target clean
make -f makefile.target
