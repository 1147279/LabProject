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

  string ID,city,date,year,month,day,high_temp,avg_temp,low_temp,high_dewpt,
          avg_dewpt,low_dewpt,high_humidity,avg_humidity,low_humidity,high_hg,
          avg_hg,low_hg,high_vis,avg_vis,low_vis,high_wind,avg_wind,low_wind,precip,events;


  int numOfLines=0;



  while (input_A.good())
  {
    numOfLines ++;
    getline(input_A,ID,delimiter);
    getline(input_A,city,delimiter);
    getline(input_A,date,delimiter);
    getline(input_A,year,delimiter);
    getline(input_A,month,delimiter);
    getline(input_A,day,delimiter);
    getline(input_A,high_temp,delimiter);
    getline(input_A,avg_temp,delimiter);
    getline(input_A,low_temp,delimiter);
    getline(input_A,high_dewpt,delimiter);
    getline(input_A,avg_dewpt,delimiter);
    getline(input_A,low_dewpt,delimiter);
    getline(input_A,high_humidity,delimiter);
    getline(input_A,avg_humidity,delimiter);
    getline(input_A,low_humidity,delimiter);
    getline(input_A,high_hg,delimiter);
    getline(input_A,avg_hg,delimiter);
    getline(input_A,low_hg,delimiter);
    getline(input_A,high_vis,delimiter);
    getline(input_A,avg_vis,delimiter);
    getline(input_A,low_vis,delimiter);
    getline(input_A,high_wind,delimiter);
    getline(input_A,avg_wind,delimiter);
    getline(input_A,low_wind,delimiter);
    getline(input_A,precip,delimiter);
    getline(input_A,events,'\n');
  }

  input_A.close();





  input_A.open("Weather.csv", ifstream::in);
  outFile.open("resTimeSeriesCompression.txt",ofstream::out);

  int count = 0 ;
  double currentSum = 0;
  double avg ;

  int linestoAVG, divisions;

  cout << "Enter divisions" << endl;
  cin >> divisions;

  linestoAVG =  numOfLines/divisions;
  cout << "linestoAVG" << linestoAVG << endl;

  while (input_A.good())
  {
    getline(input_A,ID,delimiter);
    getline(input_A,city,delimiter);
    getline(input_A,date,delimiter);
    getline(input_A,year,delimiter);
    getline(input_A,month,delimiter);
    getline(input_A,day,delimiter);
    getline(input_A,high_temp,delimiter);
    getline(input_A,avg_temp,delimiter);
    getline(input_A,low_temp,delimiter);
    getline(input_A,high_dewpt,delimiter);
    getline(input_A,avg_dewpt,delimiter);
    getline(input_A,low_dewpt,delimiter);
    getline(input_A,high_humidity,delimiter);
    getline(input_A,avg_humidity,delimiter);
    getline(input_A,low_humidity,delimiter);
    getline(input_A,high_hg,delimiter);
    getline(input_A,avg_hg,delimiter);
    getline(input_A,low_hg,delimiter);
    getline(input_A,high_vis,delimiter);
    getline(input_A,avg_vis,delimiter);
    getline(input_A,low_vis,delimiter);
    getline(input_A,high_wind,delimiter);
    getline(input_A,avg_wind,delimiter);
    getline(input_A,low_wind,delimiter);
    getline(input_A,precip,delimiter);
    getline(input_A,events,'\n');


    if (count < linestoAVG)
    {
      currentSum += stoi(avg_temp);

    }else
    if (count == linestoAVG)
    {
      avg = currentSum/count;
      count = 0;
      currentSum = 0;
      outFile << ID << delimiter << city << delimiter << date << delimiter << year <<
      delimiter << month << delimiter << day << delimiter << avg << endl ;
    }
    count++;

  }

  input_A.close();

  outFile.close();






  return 0;
}
