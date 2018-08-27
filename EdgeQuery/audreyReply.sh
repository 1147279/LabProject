#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/EdgeQuery/outTempAudrey.csv  darren@192.168.43.193:/home/darren/Desktop/Proooooj/LabProject/EdgeQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@192.168.43.193's password:"
send "0116166224\r"
