#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/EdgeQuery/forCloud.txt  uyanda@10.0.0.113:/Users/darrenblanckensee/Desktop/ELEN4012/LabProject/relays
expect "uyanda@10.0.0.113's password:"
send "0116166224\r"
expect "uyanda@10.0.0.113's password:"
send "0116166224\r"
expect "uyanda@10.0.0.113's password:"
send "0116166224\r"