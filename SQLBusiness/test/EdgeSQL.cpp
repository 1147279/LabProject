#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{

   for(int i = 0; i<argc; i++) {
      cout << azColName[i] << argv[i] << endl;
   }
   cout << endl;

   return 0;
}


void getCurrentDateAndTime( int &year, int &month, int &day, int &hour, int &minute, int &second )
{
   time_t timevar;
   time( &timevar );
   tm TM = *localtime( &timevar );

   year    = TM.tm_year + 1900;
   month   = TM.tm_mon + 1;
   day     = TM.tm_mday;
   hour    = TM.tm_hour;
   minute    = TM.tm_min ;
   second    = TM.tm_sec ;

}




int main(int argc, char** argv) {

	ifstream input;
	input.open("input.txt");
  int year, month, day, hour, minute, second;
	sqlite3 *db;
	char *zErrMsg = NULL;
	int rc;
	const char *sql;

	/* Open database */


  string tempString = "";

  int ID = 0;
  unsigned int milli ;//= 500000;
  milli = 10000000;


  while (1)
  {

    rc = sqlite3_open("test2.db", &db);
    getCurrentDateAndTime( year, month, day, hour, minute, second );





    /* Create SQL statement */

    tempString += "INSERT INTO WEATHER (ID,LOCATION,TEMPERATURE) VALUES (";
    tempString += to_string(ID);
    tempString += ",";
    tempString += to_string(minute);
    tempString += ",";
    tempString += to_string(ID*10);
    tempString += ");";


    sql = tempString.c_str();
    cout << sql << endl;




  	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    tempString="";
    ID++;
    sqlite3_close(db);
    usleep(milli);


    system("sqlite3 -header -csv 'test2.db' 'select * from WEATHER;' > outTemp.csv");
  }





	sqlite3_close(db);
	input.close();
return 0;
}
