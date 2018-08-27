#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/EdgeQuery10000/reqQuery.txt  pi@192.168.43.14:/home/pi/Desktop/LabProject/LabProject/EdgeQuery10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.43.14's password:"
send "0116166224\r"
