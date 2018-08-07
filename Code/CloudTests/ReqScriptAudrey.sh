#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/Code/CloudTests/Req.txt  pi@10.0.0.113:/home/pi/Desktop/LabProject/LabProject/Code/CloudTests/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@10.0.0.113's password:"
send "0116166224\r"
