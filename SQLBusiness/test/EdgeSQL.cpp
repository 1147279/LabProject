#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include "OrdinaryBloomFilter.hpp"
#include "FnvHash.hpp"

namespace std {
    template<> struct hash<bloom::HashParams<std::string>> {
        size_t operator()(bloom::HashParams<std::string> const& s) const {
            bloom::FnvHash32 h;
            h.Update(&s.b, sizeof(uint8_t));
            h.Update((const uint8_t *) s.a.data(), s.a.length());
            return h.Digest();
        }
    };
}


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

double randomTemperatureGenerator()
{
  return ceilf(((rand()%33 +8)+((rand()%100)/27.5))* 100) / 100;
}



int main(int argc, char** argv) {


  double randTemperatureold,randTemperaturenew;
	ifstream input;
	input.open("input.txt");
  int year, month, day, hour, minute, second;
	sqlite3 *db;
	char *zErrMsg = NULL;
	int rc;
	const char *sql;
  bloom::OrdinaryBloomFilter<std::string> bf(4, 900000);

  bf.printFilter();

  string bloomKey = "";


  //bf.Insert(t1);

  //if(!bf.Query(t1)){






  string tempString = "";

  int ID = 0;
  unsigned int milli ;//= 500000;
  milli = 200000000;
  string Location = "\'FakePlace\'";
  srand(time(NULL));
  randTemperatureold = randomTemperatureGenerator();
  randTemperaturenew = randTemperatureold;

  while (1)
  {

    rc = sqlite3_open("test2.db", &db);
    getCurrentDateAndTime( year, month, day, hour, minute, second );





    /* Create SQL statement */

    /*CREATE TABLE WEATHER(
       ...> ID INT PRIMARY KEY NOT NULL,
       ...> YEAR INT NOT NULL,
       ...> MONTH INT NOT NULL,
       ...> DAY INT NOT NULL,
       ...> HOUR INT NOT NULL,
       ...> MINUTE INT NOT NULL,
       ...> SECOND INT NOT NULL,
       ...> LOCATION CHAR(50) NOT NULL,
       ...> TEMPERATURE INT NOT NULL);
    */

    randTemperatureold = randomTemperatureGenerator();
    while (abs(randTemperaturenew-randTemperatureold) > 2)
    {
      randTemperatureold = randomTemperatureGenerator();
    }

    tempString += "INSERT INTO WEATHER (ID,YEAR,MONTH,DAY,HOUR,MINUTE,SECOND,LOCATION,TEMPERATURE) VALUES (";
    tempString += to_string(ID);
    tempString += ",";
    tempString += to_string(year);
    tempString += ",";
    tempString += to_string(month);
    tempString += ",";
    tempString += to_string(day);
    tempString += ",";
    tempString += to_string(hour);
    tempString += ",";
    tempString += to_string(minute);
    tempString += ",";
    tempString += to_string(second);
    tempString += ",";
    tempString += Location;
    tempString += ",";
    tempString += to_string(randTemperatureold);
    tempString += ");";

    randTemperaturenew = randTemperatureold;

    sql = tempString.c_str();
    cout << sql << endl;




  	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    bloomKey += Location;
    bloomKey += to_string(year);
    bloomKey += to_string(month);
    bloomKey += to_string(day);
    bloomKey += to_string(hour);
    bloomKey += to_string(minute);
    bloomKey += to_string(second);

    bf.Insert(bloomKey);
    bf.printFilter();

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
