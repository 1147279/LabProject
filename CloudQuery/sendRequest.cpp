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
  string temp = "";
  char query[256];

  cin.getline (query,256);

  string write ="";



  cout << query << endl;


  write += "echo \'";
  write += query;
  write += "\' > reqQuery.txt";
  cout << write << endl;
  system(write.c_str());

    system("sudo service ssh start");


    clock_t start;

    start = clock();


    system("./sendReqAudrey.sh");
    //system("./sendReqJohn");
    system("./sendReqRichard.sh");
    system("./sendReqMiddleton.sh");


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
      if (inFileC)
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
    inFileC.open("outTempMiddleton.csv",ifstream::in);
    inFileD.open("outTempRichard.csv",ifstream::in);
    outFile.open("QueryResult.txt",ofstream::out);

    while (inFileA.good())
    {
      getline(inFileA,temp,'\n');
      cout << "A:" << temp << endl;
      outFile << temp << endl;

    }
    while (inFileC.good())
    {
      getline(inFileC,temp,'\n');
      cout << "C:" << temp << endl;
      outFile << temp << endl ;

    }
    while (inFileD.good())
    {
      getline(inFileD,temp,'\n');
      cout << "D:" << temp << endl;
      outFile << temp << endl;

    }


    inFileA.close();
    outFile.close();


    cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  return 0;
}
