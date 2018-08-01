#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <unistd.h>

using namespace std;

char delimiter = ',';

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

  string reqCity, reqMonth;

  inFile >> reqCity >> reqMonth;

  inFile.close();

  cout << "Data From " << reqCity << " in " << reqMonth << " required" << endl;
  cout << "Request received." << endl;

  usleep(milli);


  // File is now receieved and ready to do calculations with
  string ID,city,date,year,month,day,avg_temp;

  // File is now receieved and ready to do calculations with
  inFile.open("AreaA.txt",ifstream::in);
  double currentSum= 0;
  int count = 0;

  cout << "Doing Calcs" << endl;

  while (inFile.good())
  {
    getline(inFile,ID,delimiter);
    getline(inFile,city,delimiter);
    getline(inFile,year,delimiter);
    getline(inFile,month,delimiter);
    getline(inFile,day,delimiter);
    getline(inFile,avg_temp,'\n');


    // If city is Auckland (AreaA)
    if ((city == "\"Auckland\"") && (month == "9" ))
    {

      currentSum += stoi(avg_temp);
      count ++;
    }


  }

  double avg = currentSum/count;

  ofstream outFile;

  outFile.open("avgAreaA.txt",ofstream::out);

  outFile << avg << endl;




  cout << "Sending Data..." << endl;


  // Runs script.sh which sends the file with the request to the Sensor
  system("./edgeScript.sh");

  cout << "Data Sent." << endl;


  //system("sudo systemsetup -setremotelogin off");


}
