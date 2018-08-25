#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <bitset>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <sqlite3.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{

   for(int i = 0; i<argc; i++) {
      cout << azColName[i] << argv[i] << endl;
   }
   cout << endl;

   return 0;
}

int main ()
{


	unsigned int milli ;//= 500000;
  milli = 200000;

	ifstream input;
	ifstream infile;


	cout << "Sending Request For Join.." << endl;

	system("sudo service ssh start");

	system("./start.sh");
  system("./start0.sh");



	while(1)
	{
		input.open("outTemp.csv");
		if (input)
		{
			break;
		}
	}

	input.close();

	cout << "Join B Received" << endl;

	while(1)
	{
		infile.open("outHum.csv");
		if (infile)
		{
			break;
		}
	}

	infile.close();

	cout << "Join B Received" << endl;

	usleep(milli);

	string inputString;
	string tempString;

	//inputString = "input.txt";


	input.open("outTemp.csv");

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
  string ID,year,month,day,hour,minute,second;
  string location;
  string temperature,humidity;

  string del;
  infile >> del;
  input >>del;

	cout << "A Split" << endl;
	while(input.good())
	{

    getline(input,ID,',');
    getline(input,year,',');
    getline(input,month,',');
    getline(input,day,',');
    getline(input,hour,',');
    getline(input,minute,',');
    getline(input,second,',');
    getline(input,location,',');
    getline(input,temperature,'\n');


    tempString += "INSERT INTO TEMP (ID,YEAR,MONTH,DAY,HOUR,MINUTE,SECOND,LOCATION,TEMPERATURE) VALUES (";
    tempString += ID;
    tempString += ",";
    tempString += year;
    tempString += ",";
    tempString += month;
    tempString += ",";
    tempString += day;
    tempString += ",";
    tempString += hour;
    tempString += ",";
    tempString += minute;
    tempString += ",";
    tempString += second;
    tempString += ",";
    tempString += "\'";
    tempString += location;
    tempString += "\'";
    tempString += ",";
    tempString += temperature;
    tempString += ");";


    sql = tempString.c_str();
    cout << sql << endl;

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    tempString="";
	}
	input.close();
	infile.open("outHum.csv");
	cout << "B Split" << endl;
	while(infile.good())
	{
    getline(infile,ID,',');
    getline(infile,year,',');
    getline(infile,month,',');
    getline(infile,day,',');
    getline(infile,hour,',');
    getline(infile,minute,',');
    getline(infile,second,',');
    getline(infile,location,',');
    getline(infile,temperature,'\n');


    tempString += "INSERT INTO HUMID (ID,YEAR,MONTH,DAY,HOUR,MINUTE,SECOND,LOCATION,HUMIDITY) VALUES (";
    tempString += ID;
    tempString += ",";
    tempString += year;
    tempString += ",";
    tempString += month;
    tempString += ",";
    tempString += day;
    tempString += ",";
    tempString += hour;
    tempString += ",";
    tempString += minute;
    tempString += ",";
    tempString += second;
    tempString += ",";
    tempString += "\'";
    tempString += location;
    tempString += "\'";
    tempString += ",";
    tempString += humidity;
    tempString += ");";


    sql = tempString.c_str();
    cout << sql << endl;

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    tempString="";
	}
	cout << "C Split" << endl;

	string condition = "'select TEMP.YEAR, TEMP.MONTH, TEMP.DAY, TEMP.HOUR, TEMP.MINUTE, TEMP.SECOND,"\
  " TEMP.LOCATION, TEMP.TEMPERATURE,"\
	 " HUMID.YEAR, HUMID.MONTH, HUMID.DAY, HUMID.HOUR, HUMID.MINUTE, HUMID.SECOND, HUMID.LOCATION, " \
   "HUMID.HUMIDITY "\
	"FROM TEMP " \
	"INNER JOIN HUMID ON TEMP.YEAR = HUMID.YEAR and TEMP.MONTH = HUMID.MONTH and TEMP.DAY = HUMID.DAY and "\
	" TEMP.HOUR = TEMP.HOUR and TEMP.MINUTE = HUMID.MINUTE and TEMP.SECOND = HUMID.SECOND and TEMP.LOCATION = HUMID.LOCATION;'";

  condition = "sqlite3 -header -csv 'test.db' " +  condition  +" > Output.csv";
  cout << condition << '\n';
	system(condition.c_str());
	sqlite3_close(db);

	infile.close();






	return 0;
}
