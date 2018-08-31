#!/usr/bin/expect -f
spawn scp -r /home/uyanda/Desktop/ELEN4012/LabProject/relays/instruct.txt  darren@192.168.43.193:/home/darren/Desktop/Proooooj/LabProject/JoinBusiness/
expect "darren@192.168.43.193's password:"
send "0116166224\r"
expect "darren@192.168.43.193's password:"
send "0116166224\r"
expect "darren@192.168.43.193's password:"
send "0116166224\r"
