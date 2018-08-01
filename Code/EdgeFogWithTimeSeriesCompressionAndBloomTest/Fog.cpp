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
  system("./ReqScript.sh");


  cout << "Request Sent." << endl;

  // Wait till file with results is sent back from sensor/s
  ifstream inFile;

  cout << "Waiting For Data..." << endl;


  while(1)
  {
    inFile.open("avgAreaA.txt",ifstream::in);
    if (inFile)
    {
      break;
    }
  }

  inFile.close();

  usleep(milli);

  cout << "Data Received" << endl;

  double avg;

  // File is now receieved and ready to do calculations with
  inFile.open("avgAreaA.txt",ifstream::in);

  cout << "Doing Calcs" << endl;

  inFile >> avg;


  cout << avg << endl;


  cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  //system("sudo service ssh stop");

  return 0;
}
