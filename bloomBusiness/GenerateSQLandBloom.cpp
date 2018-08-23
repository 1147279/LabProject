#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include <cmath>
//#include "OrdinaryBloomFilter.hpp"
//#include "FnvHash.hpp"




using namespace std;




int asciiSum(string str);
int powerFunction(int base, int power);
int moding(int& num, string& str);
void bloomFilterInsert (string& str, string& bitString);
bool bloomFilterContains (string& str, string& bitString);
void exportToFile(string fileName, string& str);




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


void initialiseString(string& str, int strSize);


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
  string bloomfilter ;

  //bf.printFilter();

  string bloomKey = "";
  initialiseString(bloomfilter, 1000000);


  //bf.Insert(t1);

  //if(!bf.Query(t1)){






  string tempString = "";


  unsigned int milli ;//= 500000;
  milli = 2;
  string Location = "\'Kensington\'";
  srand(time(NULL));
  randTemperatureold = randomTemperatureGenerator();
  randTemperaturenew = randTemperatureold;
  int l=0;
  string check;
   rc = sqlite3_open("test2.db", &db);
  tempString += "DELETE FROM WEATHER WHERE ID >= 0;";

	sql = tempString.c_str();
    cout << sql << endl;




  	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);


  while (l<1000)
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

    //bf.Insert(bloomKey);
	bloomFilterInsert(bloomKey, bloomfilter);

    tempString="";
    bloomKey = "";
    ID++;

    //usleep(milli);



    l++;
  }
	sqlite3_close(db);
	system("sqlite3 -header -csv 'test2.db' 'select * from WEATHER;' > outTemp.csv");

  //bf.printFilter();
	exportToFile("bitstringOUT.txt", bloomfilter);
  //system("mv bitstringprint.txt bitstringread.txt");





	//sqlite3_close(db);
	input.close();
return 0;
}


void initialiseString(string& str, int strSize)
{
	str = "";
	for(int i = 0; i < strSize; i++)
		str += "0";
}


int asciiSum(string str)
{
	int sum = 0;

	for(int i = 0; i < str.size(); i++)
	{
		sum += str.at(i);
	}

	return sum;
}



int powerFunction(int base, int power)
{
	int number = base;

	if(power == 0)
	{
		return 1;
	}else if (power > 0)
	{
		for (int i = 0; i < power - 1 ; i++)
		{
			number *= base;
		}
	}
	return number;
}


int moding(int& num, string& str)
{
	int result = 0;

	result = num%str.size();
	return result;

}


void bloomFilterInsert (string& str, string& bitString)
{
	int hash1;
	int hash2;
	int hash3;
	int asciNum = asciiSum(str);
  int num1 = powerFunction(asciNum, 4)-powerFunction((asciNum/2+powerFunction(asciNum, 2)),2)+3*(asciNum/23);
	int num2 = powerFunction(asciNum, 5)+powerFunction((asciNum/3+powerFunction(asciNum, 3)),2)-3*(asciNum/733);
	int num3 = powerFunction(asciNum, 6)-powerFunction((asciNum/4+powerFunction(asciNum, 4)),2)+3*(asciNum/1111);
  
	hash1 = moding(num1, bitString);
	hash2 = moding(num2, bitString);
	hash3 = moding(num3, bitString);

  cout << "first: " << hash1 << endl;
  cout << "second: " << hash2 << endl;
  cout << "third: " << hash3 << endl;

	bitString.at(hash1) = '1';
	bitString.at(hash2) = '1';
	bitString.at(hash3) = '1';
}

bool bloomFilterContains (string& str, string& bitString)
{
	int hash1;
	int hash2;
	int hash3;
	int asciNum = asciiSum(str);
  int num1 = powerFunction(asciNum, 4)-powerFunction((asciNum/2+powerFunction(asciNum, 2)),2)+3*(asciNum/23);
	int num2 = powerFunction(asciNum, 5)+powerFunction((asciNum/3+powerFunction(asciNum, 3)),2)-3*(asciNum/733);
	int num3 = powerFunction(asciNum, 6)-powerFunction((asciNum/4+powerFunction(asciNum, 4)),2)+3*(asciNum/1111);


	hash1 = moding(num1, bitString);
	hash2 = moding(num1, bitString);
	hash3 = moding(num1, bitString);

	if(bitString.at(hash1) == '0')
		return false;

	if(bitString.at(hash2) == '0')
		return false;

	if(bitString.at(hash3) == '0')
		return false;


	return true;
}


void exportToFile(string fileName, string& str)
{
	ofstream output;
	output.open(fileName,ofstream::out);

	output << str << endl;

	output.close();
}


void setBloomFilter(string fileName, string& str)
{
	ifstream input;
	input.open(fileName,ifstream::in);
	str = "";
	input >> str;

	input.close();
}
