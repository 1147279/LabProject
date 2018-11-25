#!/usr/bin/expect -f
spawn scp -r /home/uyanda/Desktop/LabProject/LabProject/EdgeQuery/instruct.txt  pi@192.168.1.113:/home/pi/Desktop/LabProject/LabProject/EdgeQuery/
expect "password:"
send "heavens1\r"
expect "password:"
send "heavens1\r"
expect "password:"
send "heavens1\r"
expect "pi@192.168.1.113's password:"
send "0116166224\r"
