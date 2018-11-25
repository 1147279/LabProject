#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/EdgeQuery/outTempRalph.csv  pi@192.168.1.112:/home/pi/Desktop/LabProject/LabProject/EdgeQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.1.112's password:"
send "0116166224\r"
