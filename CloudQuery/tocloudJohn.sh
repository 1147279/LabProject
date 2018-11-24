#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/CloudQuery/FinalResulytJohn.csv  uyanda@192.168.1.100:/home/uyanda/Desktop/LabProject/LabProject/CloudQuery/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "uyanda@192.168.1.100's password:"
send "heavens1\r"
