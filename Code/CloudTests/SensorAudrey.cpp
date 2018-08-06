#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <unistd.h>

using namespace std;

int main()
{

  system("sudo systemsetup -setremotelogin on");
  unsigned int milli ;//= 500000;
  milli = 100000;

  double sum = 0;

  ifstream inFile;


  cout << "Waiting For Request..." << endl;

  while(1)
  {
    inFile.open("Req.txt",ifstream::in);
    if (inFile)
    {
      break;
    }
  }

  inFile.close();


  cout << "Request received." << endl;

  usleep(milli);

  cout << "Sending Data..." << endl;


  // Runs script.sh which sends the file with the request to the Sensor
  system("./scriptAudrey.sh");

  cout << "Data Sent." << endl;


  //system("sudo systemsetup -setremotelogin off");


}
