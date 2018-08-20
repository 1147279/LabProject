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
      inFileA.open("AA.db",ifstream::in);
      if (inFileA)
      {
        break;
      }
    }

    inFileA.close();

    cout << "A Received" << endl;



    while(1)
    {
      inFileB.open("JJ.db",ifstream::in);
      if (inFileB)
      {
        break;
      }
    }

    inFileB.close();

    cout << "B Received" << endl;



    while(1)
    {
      inFileC.open("MM.db",ifstream::in);
      if (inFileC)
      {
        break;
      }
    }

    inFileC.close();

    cout << "C Received" << endl;

    while(1)
    {
      inFileD.open("RR.db",ifstream::in);
      if (inFileD)
      {
        break;
      }
    }

    inFileD.close();

    cout << "D Received" << endl;

    string ID,year,month,day,hour,minute,second;
    string location;
    string temperature;

    usleep(milli);
    ofstream outFile;
    inFileA.open("AA.db",ifstream::in);
    inFileB.open("JJ.db",ifstream::in);
    inFileC.open("MM.db",ifstream::in);
    inFileD.open("RR.db",ifstream::in);
    outFile.open("QueryResult.txt",ofstream::out);

    string tempString ="";
    sqlite3 *db;
  	char *zErrMsg = NULL;
  	int rc;
  	const char *sql;
    rc = sqlite3_open("Result.db", &db);

      tempString = "sqlite3 Result.db 'attach database 'AA.db' as copysa; insert into main.WEATHER select * from copysa.WEATHER;'";
      system(tempString.c_str());

      tempString = "sqlite3 Result.db 'attach database 'RR.db' as copysr; insert into main.WEATHER select * from copysr.WEATHER;'";
      system(tempString.c_str());

      tempString = "sqlite3 Result.db 'attach database 'MM.db' as copysm; insert into main.WEATHER select * from copysm.WEATHER;'";
      system(tempString.c_str());

      tempString = "sqlite3 Result.db 'attach database 'JJ.db' as copysj; insert into main.WEATHER select * from copysj.WEATHER;'";
      system(tempString.c_str());








    sqlite3_close(db);







    inFileA.close();
    inFileB.close();
    inFileC.close();
    inFileD.close();
    outFile.close();


    cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  return 0;
}
