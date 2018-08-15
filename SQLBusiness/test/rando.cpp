#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include <cmath>

using namespace std;

double randomTemperatureGenerator()
{
  return ceilf(((rand()%33 +8)+((rand()%100)/27.5))* 100) / 100;
}



int main(int argc, char** argv) {


  double rold = randomTemperatureGenerator();
  double rnew;
  for (int i = 0 ; i < 30 ; i ++ )
  {
    while (abs(rnew - rold)>2)

  }



}
