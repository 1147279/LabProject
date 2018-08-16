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
  bool done;


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


    system("./sendReqAudrey");
    //system("./sendReqJohn");
    //system("./sendReqRichard");
    //system("./sendReqMiddleton");


    cout << "Requests Sent." << endl;

    // Wait till file with results is sent back from sensor/s

    ifstream inFileA;
    //ifstream inFileB;
    //ifstream inFileC;
    //ifstream inFileD;

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

    usleep(milli);
    ofstream outFile;
    inFileA.open("outTempAudrey.txt",ifstream::in);
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
