#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/CloudQuery10000/reqQuery.txt  pi@10.0.0.110:/home/pi/Desktop/LabProject/LabProject/CloudQuery10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@10.0.0.110's password:"
send "0116166224\r"
