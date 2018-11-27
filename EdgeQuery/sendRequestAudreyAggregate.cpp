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

  cout << "Waiting For Cloud Request..." << endl;
  ifstream waitfor;

  while(1)
  {
    waitfor.open("instruct.txt",ifstream::in);
    if (waitfor)
    {
      cout << "Received: "<<endl;
      break;
    }
  }

  waitfor.close();

  string agg;
  unsigned int milli ;//= 500000;
  milli = 100000;
  string temp = "";
  char query[256];
  system("mv instruct.txt reqQuery.txt");

 /*
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
*/

  agg = "avg";

    system("sudo service ssh start");


    clock_t start;

    start = clock();


    system("./sendReqStorm.sh");
    system("./sendReqHarvis.sh");



    cout << "Requests Sent." << endl;

    // Wait till file with results is sent back from sensor/s

    ifstream inFileA;
    ifstream inFileB;


    cout << "Waiting For Data..." << endl;


    while(1)
    {
      inFileA.open("outTempStorm.csv",ifstream::in);
      if (inFileA)
      {
        break;
      }
    }

    inFileA.close();

    cout << "Storm Received" << endl;



    while(1)
    {
      inFileB.open("outTempHarvis.csv",ifstream::in);
      if (inFileB)
      {
        break;
      }
    }

    inFileB.close();

    cout << "Harvis Received" << endl;




    string firstline,aggregateA,aggregateB;


    usleep(milli);
    ofstream outFile;
    inFileA.open("outTempStorm.csv",ifstream::in);
    inFileB.open("outTempHarvis.csv",ifstream::in);
    outFile.open("QueryResult.txt",ofstream::out);



    for (int i = 0;i<2;i++)
    {
      inFileA >> firstline;
      if (i ==1)
      {
        aggregateA = firstline;
      }

    }
    for (int i = 0;i<2;i++)
    {
      inFileB >> firstline;
      if (i ==1)
      {
        aggregateB = firstline;
      }
    }


    cout << "A: " << aggregateA <<endl;
    cout << "B: " << aggregateB <<endl;


    double answer=0;

    if (agg == "avg")
    {
      answer = (stod(aggregateA)+stod(aggregateB))/2;
    }

    if (agg == "sum")
    {
        answer = (stod(aggregateA)+stod(aggregateB));
    }


    if (answer != 0)
    {
      cout << "The " << agg << " is " << answer << endl;
    }


    ofstream tocloud;
    tocloud.open("FinalResultAudrey.csv");
    tocloud << "avg(TEMPERATURE)"<< endl;
    tocloud << answer;
    tocloud.close();

    usleep(milli);




    system("./tocloudAudreyAgg.sh");

    //system(write.c_str());


    inFileA.close();
    inFileB.close();

    outFile.close();


    cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  return 0;
}
