#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/EdgeQuery/FinalResultJohn.csv  darren@192.168.1.110:/home/darren/Desktop/Proooooj/LabProject/EdgeQuery/
expect "darren@192.168.1.110's password:"
send "0116166224\r"
expect "darren@192.168.1.110's password:"
send "0116166224\r"
expect "darren@192.168.1.110's password:"
send "0116166224\r"
