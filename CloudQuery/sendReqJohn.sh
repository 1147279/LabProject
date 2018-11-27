#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/LabProject/LabProject/CloudQuery/instruct.txt  pi@192.168.1.110:/home/pi/Desktop/LabProject/LabProject/CloudQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.1.110's password:"
send "0116166224\r"
