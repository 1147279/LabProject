#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <unistd.h>

using namespace std;

int main()
{
  unsigned int milli ;//= 500000;
  milli = 100000;

  double sum = 0;

  ifstream inFile;

  while(1)
  {
    inFile.open("Table1.txt",ifstream::in);
    if (inFile)
    {
      break;
    }
  }

  inFile.close();


  cout << "file received" << endl;

  usleep(milli);


  inFile.open("Table1.txt",ifstream::in);
  double tempA;
  double avg;
  int count = 0;

  while (inFile >> tempA)
  {
    cout << tempA << endl;
    sum += tempA;
    count ++;

  }
  avg = sum/count;
  cout << avg << endl;


}
