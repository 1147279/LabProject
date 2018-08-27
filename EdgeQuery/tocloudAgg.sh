#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/EdgeQuery/ForCloud.txt  uyanda@192.168.43.72:/home/uyanda/Desktop/ELEN4012/LabProject/relays
expect "uyanda@192.168.43.72's password:"
send "heavens1\r"
expect "uyanda@192.168.43.72's password:"
send "heavens1\r"
expect "uyanda@192.168.43.72's password:"
send "heavens1\r"
