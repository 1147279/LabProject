#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/Code/EdgeFogTests/avgAreaB.txt  darren@10.0.0.119:/home/darren/Desktop/Proooooj/LabProject/Code/EdgeFogTests/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@10.0.0.119's password:"
send "\r"
