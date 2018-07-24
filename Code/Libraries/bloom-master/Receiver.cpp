#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{

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

  cout << "file recived" << endl;

  ifstream areaA;
  areaA.open("Table1.txt", ifstream::in);

  double tempA;
  double avg;
  int count = 0;

  while (areaA >> tempA)
  {

    sum += tempA;
    count ++;

  }
  avg = sum/count;
  cout << avg << endl;


}
