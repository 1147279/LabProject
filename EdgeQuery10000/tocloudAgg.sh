#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/EdgeQuery10000/ForCloud.txt  uyanda@192.168.43.72:/home/uyanda/Desktop/ELEN4012/LabProject/EdgeQuery10000
expect "uyanda@192.168.43.72's password:"
send "heavens1\r"
expect "uyanda@192.168.43.72's password:"
send "heavens1\r"
expect "uyanda@192.168.43.72's password:"
send "heavens1\r"
