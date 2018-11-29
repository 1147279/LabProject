#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/JoinBusiness/compressedTempBitString.txt  pi@192.168.1.101:/home/pi/Desktop/LabProject/LabProject/JoinBusiness/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.1.101's password:"
send "0116166224\r"
