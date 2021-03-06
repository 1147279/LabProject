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
  system("sudo service ssh start");
  cout << "Waiting For Cloud Request..." << endl;

  ifstream waitfor;

  while(1)
  {
    //cout << "a"<<endl;
    waitfor.open("instruct.txt",ifstream::in);
    if (waitfor)
    {
        cout << "Received: "<<endl;
      break;
    }
  }

  waitfor.close();


  unsigned int milli ;//= 500000;
  milli = 100000;
  string temp = "";
  char query[256];
  string queryTwo = "";

    system("mv instruct.txt reqQuery.txt");
    /*
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

*/


    clock_t start;

    start = clock();



    system("./sendReqCourage.sh");
    system("./sendReqRalph.sh");



    cout << "Requests Sent." << endl;

    // Wait till file with results is sent back from sensor/s

    ifstream inFileA;
    ifstream inFileB;


    cout << "Waiting For Data..." << endl;


    while(1)
    {
      inFileA.open("outTempCourage.csv",ifstream::in);
      if (inFileA)
      {
        break;
      }
    }

    inFileA.close();

    cout << "Courage Received" << endl;



    while(1)
    {
      inFileB.open("outTempRalph.csv",ifstream::in);
      if (inFileB)
      {
        break;
      }
    }

    inFileB.close();

    cout << "Ralph Received" << endl;




    string ID,year,month,day,hour,minute,second;
    string location;
    string temperature;

    usleep(milli);
    ofstream outFile;
    inFileA.open("outTempCourage.csv",ifstream::in);
    inFileB.open("outTempRalph.csv",ifstream::in);

    outFile.open("QueryResult.txt",ofstream::out);

    string tempString ="";
    sqlite3 *db;
  	char *zErrMsg = NULL;
  	int rc;
  	const char *sql;
    rc = sqlite3_open("Result.db", &db);




    while (inFileA.good())
    {
      getline(inFileA,ID,',');
      getline(inFileA,year,',');
      getline(inFileA,month,',');
      getline(inFileA,day,',');
      getline(inFileA,hour,',');
      getline(inFileA,minute,',');
      getline(inFileA,second,',');
      getline(inFileA,location,',');
      getline(inFileA,temperature,'\n');


      tempString += "INSERT INTO WEATHER (ID,YEAR,MONTH,DAY,HOUR,MINUTE,SECOND,LOCATION,TEMPERATURE) VALUES (";
      tempString += ID;
      tempString += ",";
      tempString += year;
      tempString += ",";
      tempString += month;
      tempString += ",";
      tempString += day;
      tempString += ",";
      tempString += hour;
      tempString += ",";
      tempString += minute;
      tempString += ",";
      tempString += second;
      tempString += ",";
      tempString += "\'";
      tempString += location;
      tempString += "\'";
      tempString += ",";
      tempString += temperature;
      tempString += ");";


      sql = tempString.c_str();
      cout << sql << endl;

   	  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
      tempString="";

    }
    while (inFileB.good())
    {
      getline(inFileB,ID,',');
      getline(inFileB,year,',');
      getline(inFileB,month,',');
      getline(inFileB,day,',');
      getline(inFileB,hour,',');
      getline(inFileB,minute,',');
      getline(inFileB,second,',');
      getline(inFileB,location,',');
      getline(inFileB,temperature,'\n');


      tempString += "INSERT INTO WEATHER (ID,YEAR,MONTH,DAY,HOUR,MINUTE,SECOND,LOCATION,TEMPERATURE) VALUES (";
      tempString += ID;
      tempString += ",";
      tempString += year;
      tempString += ",";
      tempString += month;
      tempString += ",";
      tempString += day;
      tempString += ",";
      tempString += hour;
      tempString += ",";
      tempString += minute;
      tempString += ",";
      tempString += second;
      tempString += ",";
      tempString += "\'";
      tempString += location;
      tempString += "\'";
      tempString += ",";
      tempString += temperature;
      tempString += ");";


      sql = tempString.c_str();
      cout << sql << endl;

   	  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
      tempString="";

    }



    sqlite3_close(db);


    ifstream queryFile;
    queryFile.open("reqQuery.txt");
    queryFile.getline (query,256);

    string write ="";



    cout << write << endl;



    write = "";
    write += "sqlite3 -header -csv \'Result.db\' \'";
    write += query;
    //write += "select * from WEATHER;";
    write += "\' > FinalResultRichard.csv";
    cout << write << endl;

    system(write.c_str());

    usleep(milli);


    system("./tocloudRichard.sh");




    inFileA.close();
    inFileB.close();

    outFile.close();


    cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  return 0;
}
