#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/Code/EdgeFogTests/Req.txt  pi@192.168.43.152:/home/pi/Desktop/LabProject/LabProject/Code/EdgeFogTests/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.43.152's password:"
send "0116166224\r"
