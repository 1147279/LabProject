#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/2/LabProject/JoinBusiness10000/ForJoin2.csv  darren@10.0.0.119:/home/darren/Desktop/Proooooj/LabProject/JoinBusiness10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@10.0.0.119's password:"
send "0116166224\r"
