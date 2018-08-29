#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/CloudQuery/outTempMiddleton.csv  darren@10.0.0.114:/home/darren/Desktop/Proooooj/LabProject/CloudQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darre@10.0.0.114's password:"
send "0116166224\r"
