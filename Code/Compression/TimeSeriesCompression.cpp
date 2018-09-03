#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const char delimiter = ',';


string keyExtraction(const char& delimiter, string& kv_pair)
{
  string key= kv_pair.substr(0, kv_pair.find(delimiter));
  return key;
};


int main(int argc, char *argv[])
{

  ifstream input_A;
  input_A.open("Weather.csv", ifstream::in);

  ofstream outFile;



  //ofstream outFile;
  //outFile.open("Weather.csv",ofstream::out);

  string ID,year,month,day,hour,minute,second,location,temperature;


  int numOfLines=0;



  while (input_A.good())
  {
    numOfLines ++;
    getline(input_A,ID,delimiter);
    getline(input_A,year,delimiter);
    getline(input_A,month,delimiter);
    getline(input_A,day,delimiter);
    getline(input_A,hour,delimiter);
    getline(input_A,minute,delimiter);
    getline(input_A,second,delimiter);
    getline(input_A,location,delimiter);
    getline(input_A,temperature,'\n');
  }

  input_A.close();





  input_A.open("Weather.csv", ifstream::in);
  outFile.open("resTimeSeriesCompression.txt",ofstream::out);

  int count = 1 ;
  double currentSum = 0;
  double avg ;

  int linestoAVG, divisions;

  cout << "Enter divisions (Minimum 6)" << endl;
  cin >> divisions;

  linestoAVG =  numOfLines/divisions;
  cout << "linestoAVG" << linestoAVG << endl;

  outFile << "ID,YEAR,MONTH,DAY,HOUR,MINUTE,SECOND,LOCATION,TEMPERATURE"<< endl;
  string temp;
  input_A >> temp;
    while (input_A.good())
  {
    getline(input_A,ID,delimiter);
    getline(input_A,year,delimiter);
    getline(input_A,month,delimiter);
    getline(input_A,day,delimiter);
    getline(input_A,hour,delimiter);
    getline(input_A,minute,delimiter);
    getline(input_A,second,delimiter);
    getline(input_A,location,delimiter);
    getline(input_A,temperature,'\n');


      currentSum += stod(temperature);


    if (count == linestoAVG)
    {
      avg = currentSum/count;
      count = 0;
      currentSum = 0;
      outFile << ID << delimiter << year << delimiter << month << delimiter << day <<
      delimiter << hour << delimiter << minute << delimiter << second << delimiter << location << delimiter << avg << endl ;
    }
    count++;

  }

  avg = currentSum/count;
  count = 0;
  currentSum = 0;
  outFile << ID << delimiter << year << delimiter << month << delimiter << day <<
  delimiter << hour << delimiter << minute << delimiter << second << delimiter << location << avg << endl ;
  input_A.close();

  outFile.close();






  return 0;
}
