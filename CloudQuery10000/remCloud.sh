rm instruct.txt
rm FinalResultAudrey.csv
rm FinalResultJohn.csv
rm FinalResultRichard.csv
rm EndResult.csv
sqlite3 Result.db "delete from WEATHER where ID >= 0;"
