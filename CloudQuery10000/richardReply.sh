#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/CloudQuery10000/outTempRichard.csv  darren@10.0.0.114:/home/darren/Desktop/Proooooj/LabProject/CloudQuery10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@10.0.0.114's password:"
send "0116166224\r"
