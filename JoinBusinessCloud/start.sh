#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/JoinBusinessCloud/joinReq.txt pi@192.168.43.164:/home/pi/Desktop/2/LabProject/JoinBusinessCloud/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.43.164's password:"
send "0116166224\r"
