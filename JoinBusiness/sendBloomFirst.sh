#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/LabProject/LabProject/bloomBusiness/compressedTempBitString.txt  pi@10.0.0.111:/home/pi/Desktop/LabProject/LabProject/bloomBusiness/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@10.0.0.111's password:"
send "0116166224\r"
