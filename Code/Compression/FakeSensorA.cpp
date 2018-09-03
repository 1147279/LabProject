#include <iostream>

#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include <cmath>

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
         if (day%30 == 0)
         {
           day = 1;
           if (month%12==0)
           {
             month = 1;
             if (year%2022==0)
             {
               year = 1;
             }
             else
             {
               year++;
             }
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
  return ceilf(((rand()%33 -10)+((rand()%100)/37.5))* 100) / 100;
}



int main(int argc, char** argv) {


  double randTemperatureold,randTemperaturenew;


  int year, month, day, hour, minute, second;
  year = 2017;
  month = 8;
  day = 1;
  hour = 1;
  minute = 1;
  second = 1;


	/* Open database */


  string tempString = "";

  int ID = 0;
  unsigned int milli ;//= 500000;
  milli = 2;
  string Location = "\'Rosebank\'";
  srand(time(NULL));
  randTemperatureold = randomTemperatureGenerator();
  randTemperaturenew = randTemperatureold;
	//rc = sqlite3_open("TAud.db", &db);
  ofstream outcsv;
  outcsv.open("Weather.csv");

  outcsv << "ID,YEAR,MONTH,DAY,HOUR,MINUTE,SECOND,LOCATION,TEMPERATURE"<< endl;

  while (ID<20000001)
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


    randTemperaturenew = randTemperatureold;


    outcsv << tempString <<endl;


    tempString="";
    ID++;
    //sqlite3_close(db);




  }


  outcsv.close();
return 0;
}
