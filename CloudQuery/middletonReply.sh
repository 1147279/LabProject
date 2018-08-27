#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/CloudQuery/outTempMiddleton.csv  darren@192.168.43.193:/home/darren/Desktop/Proooooj/LabProject/CloudQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darre@192.168.43.193's password:"
send "0116166224\r"
