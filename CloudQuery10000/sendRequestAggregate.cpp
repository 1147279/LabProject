#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <sqlite3.h>


using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{

   for(int i = 0; i<argc; i++) {
      cout << azColName[i] << argv[i] << endl;
   }
   cout << endl;

   return 0;
}

int main(int argc, char** argv)
{

  string agg;
  unsigned int milli ;//= 500000;
  milli = 100000;
  string temp = "";
  char query[256];
  string queryTwo = "";
  ofstream outreq;
  outreq.open("reqQuery.txt",ofstream::out);



  cin.getline (query,256);

  string write ="";




  //cout << query << endl;


  write += "echo \'";
  write += query;
  write += "\' > reqQuery.txt";
  cout << write << endl;


  system(write.c_str());


  cout << "What Aggregate Function would you like to perform? "<<endl;
  cout << "Type avg for average, sum for sum: ";
  cin >> agg;
  

    system("sudo service ssh start");


    clock_t start;

    start = clock();


    system("./sendReqAudrey.sh");
    system("./sendReqJohn.sh");
    system("./sendReqRichard.sh");
    system("./sendReqMiddleton.sh");


    cout << "Requests Sent." << endl;

    // Wait till file with results is sent back from sensor/s

    ifstream inFileA;
    ifstream inFileB;
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

    string firstline,aggregateA,aggregateB,aggregateC,aggregateD;


    usleep(milli);
    ofstream outFile;
    inFileA.open("outTempAudrey.csv",ifstream::in);
    inFileB.open("outTempJohn.csv",ifstream::in);
    inFileC.open("outTempMiddleton.csv",ifstream::in);
    inFileD.open("outTempRichard.csv",ifstream::in);
    outFile.open("QueryResult.txt",ofstream::out);



    while (inFileA.good())
    {
      getline(inFileA,firstline,'\n');
      getline(inFileA,aggregateA,'\n');


    }
    while (inFileB.good())
    {
      getline(inFileA,firstline,'\n');
      getline(inFileA,aggregateB,'\n');


    }
    while (inFileC.good())
    {
      getline(inFileA,firstline,'\n');
      getline(inFileA,aggregateC,'\n');


    }   while (inFileD.good())
    {
      getline(inFileA,firstline,'\n');
      getline(inFileA,aggregateD,'\n');


    }

    double answer=0;

    if (agg == "avg")
    {
      answer = (stoi(aggregateA)+stoi(aggregateB)+stoi(aggregateC)+stoi(aggregateD))/4;
    }

    if (agg == "sum")
    {
        answer = (stoi(aggregateA)+stoi(aggregateB)+stoi(aggregateC)+stoi(aggregateD));
    }


    if (answer == 0)
    {
      cout << "The " << agg << " is" << answer << endl;
    }



    system(write.c_str());


    inFileA.close();
    inFileB.close();
    inFileC.close();
    inFileD.close();
    outFile.close();


    cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  return 0;
}
