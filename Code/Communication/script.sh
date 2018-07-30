#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/Code/Libraries/bloom-master/Table1.txt  u0_222@10.0.0.117:/home/u0_222/Desktop
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "u0_a222@10.0.0.117's password:"
send "\r"
