#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/CloudQuery/reqQuery.txt  pi@192.168.43.164:/home/pi/Desktop/LabProject/LabProject/CloudQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.43.164's password:"
send "0116166224\r"
