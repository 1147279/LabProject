#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/EdgeQuery/FinalResultJohn.csv  darren@192.168.1.114:/home/darren/Desktop/LabProject/LabProject/EdgeQuery/
expect "darren@192.168.1.114's password:"
send "0116166224\r"
expect "darren@192.168.1.114's password:"
send "0116166224\r"
expect "darren@192.168.1.114's password:"
send "0116166224\r"
