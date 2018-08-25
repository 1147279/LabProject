#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/2/LabProject/JoinBusinessNoCompression/bitstringINtemp.txt  pi@10.0.0.110:/home/pi/Desktop/2/LabProject/JoinBusinessNoCompression/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@10.0.0.110's password:"
send "0116166224\r"
