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
void setBloomFilter(string fileName, string& str);



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

  string tempString = "\'Kensington\'2019102122460";
  string tempString2 = "\'Kensington\'2018102122460";

  string bloomfilter ;
  setBloomFilter("bitstringIN.txt",bloomfilter);


  if (bloomFilterContains(tempString,bloomfilter))
  {
    cout << "Its in there..." << endl;
  }

  if (bloomFilterContains(tempString2,bloomfilter))
  {
    cout << "Its in there but it shouldn't be..." << endl;
  }






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
		sum += i*str.at(i)+powerFunction(i,2)*str.at(i)+str.at(i)*107;
	}

	return sum-310296;
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

  cout << asciNum;
  int num1;// = asciNum;
  num1 = (asciNum-1555)*5112+2*asciNum; //+powerFunction((asciNum/2+powerFunction(num1, 2)),2)+3*(asciNum/23);

	int num2 = asciNum ;
  num2= powerFunction(num2, 3)+powerFunction((asciNum/3+powerFunction(asciNum, 3)),2)-3*(asciNum/21);

	int num3 = asciNum ;
  num3= (asciNum/1023)*(499*asciNum)-17825;//powerFunction(num3, 1)+powerFunction((num3/4+powerFunction(asciNum, 4)),2)+3*(asciNum/17);


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
  cout << asciNum;
  int num1;// = asciNum;
  num1 = (asciNum-1555)*5112+2*asciNum; //+powerFunction((asciNum/2+powerFunction(num1, 2)),2)+3*(asciNum/23);

	int num2 = asciNum ;
  num2= powerFunction(num2, 3)+powerFunction((asciNum/3+powerFunction(asciNum, 3)),2)-3*(asciNum/21);

	int num3 = asciNum ;
  num3= (asciNum/1023)*(499*asciNum)-17825;//powerFunction(num3, 1)+powerFunction((num3/4+powerFunction(asciNum, 4)),2)+3*(asciNum/17);


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
