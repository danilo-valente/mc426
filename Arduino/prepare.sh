#!/bin/sh

if [ -z "$2" ]; then
    PORT="/dev/ttyACM0"
else
    PORT="$2"
fi

sudo chmod a+x $PORT
sudo usermod -a -G tty $(whoami)
sudo usermod -a -G dialout $(whoami)

# sudo ip ad add 10.0.0.1/24 dev eth0
# sudo ifconfig eth0 10.0.1.1 netmask 255.255.255.0
