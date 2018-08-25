#include <iostream>
#include <sqlite3.h> 
#include <fstream>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) 
{

   for(int i = 0; i<argc; i++) {
      cout << azColName[i] << argv[i] << endl;
   }
   cout << endl;
   
   return 0;
}

int main(int argc, char** argv) {
	
	cout << "Enter name of txt you will read from!"<< endl;
	
	string inputString;
	string tempString;
	
	//inputString = "input.txt";
	
	ifstream infile;
	ifstream input;
	input.open("ForJoin.csv");
	
	sqlite3 *db;
	char *zErrMsg = NULL;
	int rc;
	const char *sql;

	/* Open database */
	rc = sqlite3_open("test.db", &db);

	/* Create SQL statement */
	//sql = "SELECT * from COMPANY";
	
	/*
	
	 CREATE TABLE TEMP(ID INT PRIMARY KEY NOT NULL, YEAR PRIMARY KEY INT NOT NULL, MONTH INT  NOT NULL, DAY  INT  NOT NULL, HOUR INT NOT NULL, MINUTE INT NOT NULL, SECOND INT NOT NULL, LOCATION CHAR(50) NOT NULL, TEMPERATURE FLOAT );
	
CREATE TABLE HUMID(ID INT PRIMARY KEY NOT NULL, YEAR PRIMARY KEY INT NOT NULL, MONTH INT  NOT NULL, DAY  INT  NOT NULL, HOUR INT NOT NULL, MINUTE INT NOT NULL, SECOND INT NOT NULL, LOCATION CHAR(50) NOT NULL, HUMIDITY FLOAT );
	
	*/
	/*
	cout << "A Split" << endl;
	while(getline(input, tempString))
	{
		cout << tempString << endl;
		tempString = "INSERT INTO TEMP (ID, YEAR, MONTH, DAY, HOUR, MINUTE, SECOND, LOCATION, TEMPERATURE) VALUES (" + tempString + ");";
		
		sql = tempString.c_str();
		
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	}
	input.close();
	infile.open("ForJoin2.csv");
	cout << "B Split" << endl;
	while(getline(infile, tempString))
	{
		cout << tempString << endl;
		tempString = "INSERT INTO HUMID (ID, YEAR, MONTH, DAY, HOUR, MINUTE, SECOND, LOCATION, HUMIDITY) VALUES (" + tempString + ");";
		
		sql = tempString.c_str();
		
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	}
	cout << "C Split" << endl;
	*/
	string condition = "'select TEMP.YEAR, TEMP.MONTH, TEMP.DAY, TEMP.HOUR, TEMP.MINUTE, TEMP.SECOND, TEMP.LOCATION, "\
	 " HUMID.YEAR, HUMID.MONTH, HUMID.DAY, HUMID.HOUR, HUMID.MINUTE, HUMID.SECOND, HUMID.LOCATION " \
	"FROM TEMP " \
	"INNER JOIN HUMID ON TEMP.YEAR =HUMID.YEAR and TEMP.MONTH = HUMID.MONTH and TEMP.DAY = HUMID.DAY and "\
	" TEMP.HOUR = TEMP.HOUR and TEMP.MINUTE = HUMID.MINUTE and TEMP.SECOND = HUMID.SECOND and TEMP.LOCATION = HUMID.LOCATION;'";
	condition = "sqlite3 -header -csv 'test.db' " +  condition  +" > Output.csv";
	system(condition.c_str());
	sqlite3_close(db);
	
	infile.close();
return 0;
}