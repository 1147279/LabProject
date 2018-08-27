#!/usr/bin/expect -f
spawn scp -r /home/pi/Desktop/2/LabProject/JoinBusiness10000/resultingBitStringCompressed.txt  pi@192.168.43.255:/home/pi/Desktop/2/LabProject/JoinBusiness10000/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.43.255's password:"
send "0116166224\r"
