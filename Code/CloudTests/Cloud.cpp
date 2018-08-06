#include <iostream>
#include <fstream>
#include <stdio.h>
//#include "mpi.h"
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>
#include <ctime>

using namespace std;

char delimiter = ',';

int main(int argc, char *argv[]){


  unsigned int milli ;//= 500000;
  milli = 100000;


  // Initiate Communication
  system("sudo service ssh start");

  cout << "Sending Request..." << endl;


  clock_t start;

  start = clock();


  // Runs script.sh which sends the file with the request to the Sensor
  system("./ReqScriptJohn.sh");
  system("./ReqScriptRichard.sh");
  system("./ReqScriptMiddleton.sh");
  system("./ReqScriptAudrey.sh");


  cout << "Request Sent." << endl;

  // Wait till file with results is sent back from sensor/s

  ifstream inFileA;
  ifstream inFileB;
  ifstream inFileC;
  ifstream inFileD;

  cout << "Waiting For Data..." << endl;


  while(1)
  {
    inFileA.open("AreaA.txt",ifstream::in);
    if (inFileA)
    {
      break;
    }
  }

  inFileA.close();

  cout << "A Received" << endl;

  while(1)
  {
    inFileB.open("AreaB.txt",ifstream::in);
    if (inFileB)
    {
      break;
    }
  }

  inFileB.close();

  cout << "B Received" << endl;

  while(1)
  {
    inFileC.open("AreaC.txt",ifstream::in);
    if (inFileC)
    {
      break;
    }
  }

  inFileC.close();

  cout << "C Received" << endl;

  while(1)
  {
    inFileD.open("AreaD.txt",ifstream::in);
    if (inFileD)
    {
      break;
    }
  }

  inFileD.close();

  cout << "D Received" << endl;

  usleep(milli);


  cout << "Data Received" << endl;

  string ID,city,date,year,month,day,avg_temp;

  // File is now receieved and ready to do calculations with
  inFileA.open("AreaA.txt",ifstream::in);
  double currentSum= 0;
  int count = 0;

  cout << "Doing Calcs" << endl;

  while (inFileA.good())
  {
    getline(inFileA,ID,delimiter);
    getline(inFileA,city,delimiter);
    getline(inFileA,year,delimiter);
    getline(inFileA,month,delimiter);
    getline(inFileA,day,delimiter);
    getline(inFileA,avg_temp,'\n');


    // If city is Auckland (AreaA)
    if ((city == "\"Auckland\"") && (month == "9" ))
    {

      currentSum += stoi(avg_temp);
      count ++;
    }


  }


  inFileB.open("AreaB.txt",ifstream::in);



  cout << "Doing More Calcs" << endl;

  while (inFileB.good())
  {
    getline(inFileB,ID,delimiter);
    getline(inFileB,city,delimiter);
    getline(inFileB,year,delimiter);
    getline(inFileB,month,delimiter);
    getline(inFileB,day,delimiter);
    getline(inFileB,avg_temp,'\n');


    // If city is Auckland (AreaA)
    if ((city == "\"Auckland\"") && (month == "9" ))
    {

      currentSum += stoi(avg_temp);
      count ++;
    }


  }



  inFileC.open("AreaC.txt",ifstream::in);


  cout << "Doing More and More Calcs" << endl;

  while (inFileC.good())
  {
    getline(inFileC,ID,delimiter);
    getline(inFileC,city,delimiter);
    getline(inFileC,year,delimiter);
    getline(inFileC,month,delimiter);
    getline(inFileC,day,delimiter);
    getline(inFileC,avg_temp,'\n');


    // If city is Auckland (AreaA)
    if ((city == "\"Auckland\"") && (month == "9" ))
    {

      currentSum += stoi(avg_temp);
      count ++;
    }


  }


  inFileD.open("AreaD.txt",ifstream::in);


  cout << "Doing Calcs" << endl;

  while (inFileA.good())
  {
    getline(inFileD,ID,delimiter);
    getline(inFileD,city,delimiter);
    getline(inFileD,year,delimiter);
    getline(inFileD,month,delimiter);
    getline(inFileD,day,delimiter);
    getline(inFileD,avg_temp,'\n');


    // If city is Auckland (AreaA)
    if ((city == "\"Auckland\"") && (month == "9" ))
    {

      currentSum += stoi(avg_temp);
      count ++;
    }


  }






  double avg = currentSum/count;

  cout << avg << endl;


  cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  //system("sudo service ssh stop");

  return 0;
}
