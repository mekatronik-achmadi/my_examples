#!/bin/bash

export USBDISK="/dev/sdb1"

yes | sudo multibootusb -c -i ../GNU-Linux/x86_64/manjaro-mate-19.0-200226-linux54.iso -t $USBDISK
yes | sudo multibootusb -c -i ./core-x86_64/coreOS-x86_64.iso -t $USBDISK
yes | sudo multibootusb -c -i ./achmadi-x86_64/achmadiOS-x86_64.iso -t $USBDISK
