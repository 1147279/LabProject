#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/CloudQuery10000/outTempJohn.csv darren@192.168.43.193:/home/darren/Desktop/Proooooj/LabProject/CloudQuery10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@192.168.43.193's password:"
send "0116166224\r"
