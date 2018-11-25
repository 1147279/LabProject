rm instruct.txt
rm FinalResultRichard.csv
rm outTempRalph.csv
rm outTempCourage.csv
sqlite3 Result.db "delete from WEATHER where ID >= 0;"
