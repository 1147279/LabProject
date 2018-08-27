#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/SQLBusiness/bloomfilterUsage/bitstringread.txt  pi@192.168.43.164:/home/pi/Desktop/LabProject/LabProject/SQLBusiness/bloomfilterUsage/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "pi@192.168.43.164's password:"
send "0116166224\r"
