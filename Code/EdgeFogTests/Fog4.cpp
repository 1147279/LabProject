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
    inFileA.open("avgAreaA.txt",ifstream::in);
    //inFileB.open("avgAreaB.txt",ifstream::in);

    //if ((inFileA)&&(inFileB)&&(inFileC)&&(inFileD))
    if (inFileB)
    {
      break;
    }
  }

  cout << "A File Received" << endl;


  while(1)
  {
    //inFileA.open("avgAreaA.txt",ifstream::in);
    inFileB.open("avgAreaB.txt",ifstream::in);

    //if ((inFileA)&&(inFileB)&&(inFileC)&&(inFileD))
    if (inFileB)
    {
      break;
    }
  }

  cout << "B File Received" << endl;

  while(1)
  {
    //inFileA.open("avgAreaA.txt",ifstream::in);
    //inFileB.open("avgAreaB.txt",ifstream::in);
    inFileC.open("avgAreaC.txt",ifstream::in);
    //inFileD.open("avgAreaD.txt",ifstream::in);
    //if ((inFileA)&&(inFileB)&&(inFileC)&&(inFileD))
    if (inFileC)
    {
      break;
    }
  }

  cout << "C File Received" << endl;

  while(1)
  {
    //inFileA.open("avgAreaA.txt",ifstream::in);
    //inFileB.open("avgAreaB.txt",ifstream::in);
    //inFileC.open("avgAreaC.txt",ifstream::in);
    inFileD.open("avgAreaD.txt",ifstream::in);
    //if ((inFileA)&&(inFileB)&&(inFileC)&&(inFileD))
    if (inFileD)
    {
      break;
    }
  }

  cout << "D File Received" << endl;


  inFileA.close();
  inFileB.close();
  inFileC.close();
  inFileD.close();

  usleep(milli);
  system("clear");
  usleep(milli);


  cout << "Data Received" << endl;

  double avgA,avgB,avgC,avgD,avg;

  // File is now receieved and ready to do calculations with
  inFileA.open("avgAreaA.txt",ifstream::in);
  inFileB.open("avgAreaB.txt",ifstream::in);
  inFileC.open("avgAreaC.txt",ifstream::in);
  inFileD.open("avgAreaD.txt",ifstream::in);

  cout << "Doing Calcs" << endl;

  inFileA >> avgA;
  inFileB >> avgB;
  inFileC >> avgC;
  inFileD >> avgD;

  avg = (avgA+avgB+avgC+avgD)/4;
  //avg = (avgB+avgC+avgD)/3;

  cout << avg << endl;


  cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

  inFileA.close();
  inFileB.close();
  inFileC.close();
  inFileD.close();




  //system("sudo service ssh stop");

  return 0;
}
