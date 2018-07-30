#include <iostream>
#include <fstream>
#include <stdio.h>
//#include "mpi.h"
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;


int main(int argc, char *argv[]){


  unsigned int milli ;//= 500000;
  milli = 100000;


  // Initiate Communication
  system("sudo service ssh start");

  // Runs script.sh which sends the file with the request to the Sensor
  system("./ReqScript.sh");


  // Wait till file with results is sent back from sensor/s
  ifstream inFile;

  while(1)
  {
    inFile.open("Result.txt",ifstream::in);
    if (inFile)
    {
      break;
    }
  }

  inFile.close();

  usleep(milli);


  // File is now receieved and ready to do calculations with
  inFile.open("Result.txt",ifstream::in);
  double currentSum= 0;
  int count = 0;

  while (inFile.good())
  {
    getline(input_A,ID,delimiter);
    getline(input_A,city,delimiter);
    getline(input_A,date,delimiter);
    getline(input_A,year,delimiter);
    getline(input_A,month,delimiter);
    getline(input_A,day,delimiter);
    getline(input_A,high_temp,delimiter);
    getline(input_A,avg_temp,'\n');


    // If city is Auckland (AreaA)
    if ((city == "Auckland") && (month == "9" )
    {
      currentSum += avg_temp;
      count ++;
    }


  }

  double avg = currentSum/count;

  cout << avg;







  system("sudo service ssh stop");

  return 0;
}
