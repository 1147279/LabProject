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

   if (second%60 == 0)
   {
     second = 1;
     if (minute%60 == 0)
     {
       minute = 1;
       if (hour%24 == 0)
       {
         hour = 1;
         if (day%365 == 0)
         {
           day = 1;
           if (month%12)
           {
             month = 1;
           }else
           {
             month++;
           }
         }else
         {
           day++;
         }
       }else
       {
         hour ++;
       }
     }else
     {
       minute++;
     }
   }else
   {
     second++;
   }

}

double randomTemperatureGenerator()
{
  return ceilf(((rand()%33 +8)+((rand()%100)/27.5))* 100) / 100;
}



int main(int argc, char** argv) {


  double randTemperatureold,randTemperaturenew;
	ifstream input;
	input.open("input.txt");
  int year, month, day, hour, minute, second, ID;
  year = 2019; month = 8; day = 16; hour = 1; minute = 0; second = 0; ID = 0;
	sqlite3 *db;
	char *zErrMsg = NULL;
	int rc;
	const char *sql;
  bloom::OrdinaryBloomFilter<std::string> bf(4, 900000);

  //bf.printFilter();

  string bloomKey = "";


  //bf.Insert(t1);

  //if(!bf.Query(t1)){






  string tempString = "";

  
  unsigned int milli ;//= 500000;
  milli = 2;
  string Location = "\'FakePlace\'";
  srand(time(NULL));
  randTemperatureold = randomTemperatureGenerator();
  randTemperaturenew = randTemperatureold;
  int l=200;
  
   rc = sqlite3_open("test2.db", &db);
  tempString += "DELETE FROM WEATHER WHERE ID >= 0;";
	
	sql = tempString.c_str();
    cout << sql << endl;




  	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	
  
  while (l<100)
  {
	
	
   
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


    cout << "---------------" << endl;
    cout << bloomKey << endl;
    cout << "---------------" << endl;

    bf.Insert(bloomKey);


    tempString="";
    bloomKey = "";
    ID++;
    
    usleep(milli);


    
    l++;
  }
	sqlite3_close(db);
	system("sqlite3 -header -csv 'test2.db' 'select * from WEATHER;' > outTemp.csv");

  bf.printFilter();

  system("mv bitstringprint.txt bitstringread.txt");





	sqlite3_close(db);
	input.close();
return 0;
}
