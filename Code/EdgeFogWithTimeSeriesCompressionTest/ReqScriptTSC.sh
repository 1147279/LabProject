#!/usr/bin/expect -f
spawn scp -r /home/darren/Desktop/Proooooj/LabProject/Code/EdgeFogWithTimeSeriesCompressionTest/ReqTSC.txt  darrenblanckensee@10.0.0.108:/Users/darrenblanckensee/Desktop/LabProject/LabProject/Code/EdgeFogWithTimeSeriesCompressionTest/
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "password:"
send "0116166224\r"
expect "darrenblanckensee@10.0.0.108's password:"
send "0116166224\r"
