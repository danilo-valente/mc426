#!/bin/sh

if [ -z "$2" ]; then
    PORT="/dev/ttyACM0"
else
    PORT="$2"
fi

if [ -z "$3" ]; then
    BAUD="9600"
else
    BAUD="$3"
fi

/opt/clion/bin/cmake/bin/cmake --build /home/danilo/.clion10/system/cmake/generated/a693b20c/a693b20c/Debug --target $1 -- -j 4

if [ "$1" = "Arduino-upload" ]; then
    stty -F $PORT cs8 $BAUD ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts

    echo 'Reading from' $PORT '('$BAUD' baud)'
    tail -f $PORT
fi
