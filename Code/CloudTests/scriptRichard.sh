#!/usr/bin/expect -f
spawn scp -r /Users/darrenblanckensee/Desktop/LabProject/LabProject/Code/CloudTests/AreaA.txt  darren@192.168.43.193:/home/darren/Desktop/Proooooj/LabProject/Code/CloudTests/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darren@192.168.43.193's password:"
send "\r"
