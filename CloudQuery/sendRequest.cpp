#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>


using namespace std;


int main(int argc, char** argv)
{

  unsigned int milli ;//= 500000;
  milli = 100000;
  string query = "";
  string write = "";
  string temp;
  bool done = false;


  while (!done)
  {
    cin >> query;
    if (query == "quit")
    {
      done = true;
      break;
    }
    write += "echo \'";
    write += query;
    write += "\' > reqQuery.txt";
    system(write.c_str());

    system("sudo service ssh start");


    clock_t start;

    start = clock();


    system("./sendReqAudrey.sh");
    //system("./sendReqJohn");
    system("./sendReqRichard");
    system("./sendReqMiddleton");


    cout << "Requests Sent." << endl;

    // Wait till file with results is sent back from sensor/s

    ifstream inFileA;
    //ifstream inFileB;
    ifstream inFileC;
    ifstream inFileD;

    cout << "Waiting For Data..." << endl;


    while(1)
    {
      inFileA.open("outTempAudrey.csv",ifstream::in);
      if (inFileA)
      {
        break;
      }
    }

    inFileA.close();

    cout << "A Received" << endl;

    /*

    while(1)
    {
      inFileB.open("outTempJohn.csv",ifstream::in);
      if (inFileB)
      {
        break;
      }
    }

    inFileB.close();

    cout << "B Received" << endl;

    */

    while(1)
    {
      inFileC.open("outTempMiddleton.csv",ifstream::in);
      if (inFileA)
      {
        break;
      }
    }

    inFileC.close();

    cout << "C Received" << endl;

    while(1)
    {
      inFileD.open("outTempRichard.csv",ifstream::in);
      if (inFileD)
      {
        break;
      }
    }

    inFileD.close();

    cout << "D Received" << endl;



    usleep(milli);
    ofstream outFile;
    inFileA.open("outTempAudrey.csv",ifstream::in);
    outFile.open("QueryResult.txt",ofstream::out);

    while (inFileA >> temp)
    {
      outFile << temp;
    }

    inFileA.close();
    outFile.close();


  }




  return 0;
}
