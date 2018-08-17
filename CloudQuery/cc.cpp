#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

  char query[256];

  cin.getline (query,256);

  string write ="";



  cout << query << endl;


  write += "echo \'";
  write += query;
  write += "\' > cc.txt";
  cout << write << endl;
  system(write.c_str());
}
