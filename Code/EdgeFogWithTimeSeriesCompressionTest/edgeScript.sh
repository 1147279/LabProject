#!/usr/bin/expect -f
spawn scp -r /Users/darrenblanckensee/Desktop/LabProject/LabProject/Code/EdgeFogTests/avgAreaA.txt  darren@10.0.0.117:/home/darren/Desktop/Proooooj/LabProject/Code/EdgeFogTests/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@10.0.0.117's password:"
send "\r"
