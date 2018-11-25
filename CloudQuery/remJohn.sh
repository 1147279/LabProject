rm instruct.txt
rm FinalResultJohn.csv
rm outTempMac.csv
rm outTempMurphy.csv
sqlite3 Result.db "delete from WEATHER where ID >= 0;"
