#include <iostream>
#include <fstream>

using namespace stdl

int main()
{
  ifstream in;
  in.open("resultingBitStringCompressed.txt");
  string check;
  in >> check;
  for (int i= 0; i < check.size();i++)
  {
    if (i%14 == 0)
      cout << check[i] <<endl;
  }
  in.close();
}
