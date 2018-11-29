#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/LabProject/LabProject/EdgeQuery/instruct.txt  pi@192.168.1.104:/home/pi/Desktop/LabProject/LabProject/EdgeQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.1.104's password:"
send "0116166224\r"
