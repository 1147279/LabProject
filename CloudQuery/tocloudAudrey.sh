#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/CloudQuery/FinalResultAudrey.csv  darren@192.168.1.114:/home/darren/Desktop/LabProject/LabProject/CloudQuery/
expect "darren@192.168.1.114's password:"
send "0116166224\r"
expect "darren@192.168.1.114's password:"
send "0116166224\r"
expect "darren@192.168.1.114's password:"
send "0116166224\r"
