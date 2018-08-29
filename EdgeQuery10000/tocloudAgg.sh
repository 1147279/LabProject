#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/EdgeQuery10000/ForCloud.txt  uyanda@10.0.0.113:/home/uyanda/Desktop/ELEN4012/LabProject/EdgeQuery10000
expect "uyanda@10.0.0.113's password:"
send "heavens1\r"
expect "uyanda@10.0.0.113's password:"
send "heavens1\r"
expect "uyanda@10.0.0.113's password:"
send "heavens1\r"
