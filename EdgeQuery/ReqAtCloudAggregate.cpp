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
  outreq.open("instruct.txt",ofstream::out);
  cout << "Type Command: " <<endl;


  cin.getline(query,256);

  string write ="";




  //cout << query << endl;


  write += "echo \'";
  write += query;
  write += "\' > instruct.txt";
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



    cout << "Requests Sent to fog Gateways." << endl;

    // Wait till file with results is sent back from sensor/s

    ifstream inFileA;
    ifstream inFileB;
    ifstream inFileC;


    cout << "Waiting For Data..." << endl;


        while(1)
        {
          inFileA.open("FinalResultRichard.csv",ifstream::in);
          if (inFileA)
          {
            break;
          }
        }

        inFileA.close();

        cout << "Richard Received" << endl;



        while(1)
        {
          inFileB.open("FinalResultJohn.csv",ifstream::in);
          if (inFileB)
          {
            break;
          }
        }

        inFileB.close();

        cout << "John Received" << endl;



        while(1)
        {
          inFileB.open("FinalResultAudrey.csv",ifstream::in);
          if (inFileB)
          {
            break;
          }
        }

        inFileB.close();

        cout << "Audrey Received" << endl;




    string firstline,aggregateA,aggregateB,aggregateC;


    usleep(milli);
    ofstream outFile;
    inFileA.open("FinalResultAudrey.csv",ifstream::in);
    inFileB.open("FinalResultJohn.csv",ifstream::in);
    inFileD.open("FinalResultRichard.csv",ifstream::in);
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


    }

    double answer=0;

    if (agg == "avg")
    {
      answer = (stoi(aggregateA)+stoi(aggregateB)+stoi(aggregateC))/3;
    }

    if (agg == "sum")
    {
        answer = (stoi(aggregateA)+stoi(aggregateB)+stoi(aggregateC));
    }


    if (answer == 0)
    {
      cout << "The " << agg << " is" << answer << endl;
    }



    system(write.c_str());


    inFileA.close();
    inFileB.close();
    inFileC.close();
    outFile.close();


    cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  return 0;
}
