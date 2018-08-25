#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/EdgeQuery10000/outTempAudrey.csv  darren@10.0.0.119:/home/darren/Desktop/Proooooj/LabProject/EdgeQuery10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darre@10.0.0.119's password:"
send "0116166224\r"
