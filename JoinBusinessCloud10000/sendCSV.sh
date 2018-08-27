#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/2/LabProject/JoinBusinessCloud10000/outTemp.csv  darren@192.168.43.193:/home/darren/Desktop/Proooooj/LabProject/JoinBusinessCloud10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@192.168.43.193's password:"
send "0116166224\r"
