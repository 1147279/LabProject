#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/JoinBusiness/compressedbloomFinalJohn.txt  pi@192.168.1.104:/home/pi/Desktop/LabProject/LabProject/JoinBusiness/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.1.104's password:"
send "0116166224\r"
