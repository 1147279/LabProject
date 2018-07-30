#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/Code/CloudTests/Req.txt  darrenblanckensee@10.0.0.110:/home/u0_222/Desktop
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darrenblanckensee@10.0.0.110's password:"
send "0116166224\r"
