rm instruct.txt
rm FinalResultAudrey.csv
rm outTempStorm.csv
rm outTempHarvis.csv
sqlite3 Result.db "delete from WEATHER where ID >= 0;"
