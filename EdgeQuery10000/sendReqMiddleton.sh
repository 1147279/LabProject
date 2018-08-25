#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/EdgeQuery10000/reqQuery.txt  pi@10.0.0.109:/home/pi/Desktop/LabProject/LabProject/EdgeQuery10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@10.0.0.109's password:"
send "0116166224\r"
