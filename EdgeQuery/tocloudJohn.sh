#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/EdgeQuery/FinalResultJohn.csv  uyanda@192.168.1.100:/home/uyanda/Desktop/LabProject/LabProject/EdgeQuery/
expect "uyanda@192.168.1.100's password:"
send "heavens1\r"
expect "uyanda@192.168.1.100's password:"
send "heavens1\r"
expect "uyanda@192.168.1.100's password:"
send "heavens1\r"
