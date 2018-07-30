#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const char delimiter = ',';



int main(int argc, char *argv[])
{

  ifstream input_A;


  ofstream outFile;



  //ofstream outFile;
  //outFile.open("Weather.csv",ofstream::out);

  string ID,city,date,year,month,day,high_temp,avg_temp,low_temp,high_dewpt,
          avg_dewpt,low_dewpt,high_humidity,avg_humidity,low_humidity,high_hg,
          avg_hg,low_hg,high_vis,avg_vis,low_vis,high_wind,avg_wind,low_wind,precip,events;




  input_A.open("Weather.csv", ifstream::in);
  outFile.open("AreaA.txt",ofstream::out);

  int count = 0 ;
  int currentSum = 0;
  int avg ;

  int linestoAVG, divisions;



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


      outFile << ID << delimiter << city << delimiter << year <<
      delimiter << month << delimiter << day << delimiter << avg_temp << endl ;



  }

  input_A.close();

  outFile.close();






  return 0;
}
