#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/Code/EdgeFogTests/Req.txt  darrenblanckensee@10.0.0.110:/Users/darrenblanckensee/Desktop/LabProject/LabProject/Code/EdgeFogTests/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darrenblanckensee@10.0.0.110's password:"
send "0116166224\r"