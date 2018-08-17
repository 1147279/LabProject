#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/CloudQuery/outTempAudrey.csv  darren@10.0.0.119:/home/darren/Desktop/Proooooj/LabProject/CloudQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darre@10.0.0.119's password:"
send "0116166224\r"
