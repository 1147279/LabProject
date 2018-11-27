#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/EdgeQuery/FinalResultRichard.csv  darren@192.168.1.114:/home/darren/Desktop/Proooooj/LabProject/EdgeQuery
expect "darren@192.168.1.114's password:"
send "0116166224\r"
expect "darren@192.168.1.114's password:"
send "0116166224\r"
expect "darren@192.168.1.114's password:"
send "0116166224\r"
