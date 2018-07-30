#!/usr/bin/expect -f
spawn scp -r /Users/darrenblanckensee/Desktop/LabProject/LabProject/Code/CloudTests/avgAreaA.txt  darren@10.0.0.116:/home/darren/Desktop/Proooooj/LabProject/Code/CloudTests/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@10.0.0.116's password:"
send "\r"
