#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <unistd.h>

using namespace std;

char delimiter = ',';

int main()
{

  system("sudo service ssh start");
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

	 usleep(milli);

  getline(inFile,reqCity,delimiter);
 	getline(inFile,reqMonth,'\n');
	string tmp = "\""+reqCity+"\"";

	cout << tmp << endl;
  inFile.close();

  cout << "Data From " << tmp << " in " << reqMonth << " required" << endl;
  cout << "Request received." << endl;

  reqCity = tmp;
	

  // File is now receieved and ready to do calculations with
  string ID,city,date,year,month,day,avg_temp;

  
  inFile.open("AreaD.txt",ifstream::in);
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
    if ((city == reqCity) && (month == reqMonth ))
    {

      currentSum += stoi(avg_temp);
      count ++;
    }


  }

  double avg = currentSum/count;

  ofstream outFile;

  outFile.open("avgAreaD.txt",ofstream::out);

  outFile << avg << endl;




  cout << "Sending Data..." << endl;


  // Runs script.sh which sends the file with the request to the Sensor
  system("./edgeScriptMiddleton.sh");

  cout << "Data Sent." << endl;


  //system("sudo service ssh stop");


}
