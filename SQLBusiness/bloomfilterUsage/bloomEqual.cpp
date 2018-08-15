#include <string>
#include <iostream>
#include "OrdinaryBloomFilter.hpp"
#include "FnvHash.hpp"
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){


  ifstream inputFile("bitstringtest.txt",ifstream::in);
  ifstream inputFile2("bitstringtest1.txt",ifstream::in);

  string in1,in2;

  inputFile >> in1;
  inputFile2 >> in2;


  for (int i = 0 ; i < in1.length() ; i ++)
  {
    if (in1[i] != in2[i])
    {
      cout << "Not equal" << endl;
      return 0;
    }
  }

  cout << "Equal" << endl;
  return 0;
}
