#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/JoinBusinessCloud/joinReq.txt pi@10.0.0.111:/home/pi/Desktop/2/LabProject/JoinBusinessCloud/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@10.0.0.111's password:"
send "0116166224\r"
