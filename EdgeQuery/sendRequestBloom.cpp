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
	  cout << "Type Command: " <<endl;
      break;
    }
  }

  waitfor.close();

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

    bool a,b,c,d;
    a=false;
    b=false;
    c=false;
    d=false;
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

    string ID,year,month,day,hour,minute,second;
    string location;
    string temperature;

    usleep(milli);






    ofstream outFile;
    inFileA.open("outTempAudrey.csv",ifstream::in);
    inFileB.open("outTempJohn.csv",ifstream::in);
    inFileC.open("outTempMiddleton.csv",ifstream::in);
    inFileD.open("outTempRichard.csv",ifstream::in);
    outFile.open("QueryResult.txt",ofstream::out);

    string checkA;
    inFileA >> checkA;
    if (checkA != "No")
    {
      cout << "IS TRUE"<<endl;
      a= true;
    }
    string checkB;
    inFileB >> checkB;
    if (checkB != "No")
    {
      cout << "IS TRUE"<<endl;
      b= true;
    }
    string checkC;
    inFileC >> checkC;
    if (checkC != "No")
    {
      cout << "IS TRUE"<<endl;
      c= true;
    }
    string checkD;
    inFileD >> checkD;
    if (checkD != "No")
    {
      cout << "IS TRUE"<<endl;
      d= true;
    }



    string tempString ="";
    sqlite3 *db;
  	char *zErrMsg = NULL;
  	int rc;
  	const char *sql;
    rc = sqlite3_open("Result.db", &db);



    if (a)
    {
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
    }

    if (b)
    {
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
    }

    if (c)
    {
      while (inFileC.good())
      {
        getline(inFileC,ID,',');
        getline(inFileC,year,',');
        getline(inFileC,month,',');
        getline(inFileC,day,',');
        getline(inFileC,hour,',');
        getline(inFileC,minute,',');
        getline(inFileC,second,',');
        getline(inFileC,location,',');
        getline(inFileC,temperature,'\n');


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
    }

    if (d)
    {
      while (inFileD.good())
      {
        getline(inFileD,ID,',');
        getline(inFileD,year,',');
        getline(inFileD,month,',');
        getline(inFileD,day,',');
        getline(inFileD,hour,',');
        getline(inFileD,minute,',');
        getline(inFileD,second,',');
        getline(inFileD,location,',');
        getline(inFileD,temperature,'\n');


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
    }

    sqlite3_close(db);

    write = "";
    write += "sqlite3 -header -csv \'Result.db\' \'";
    write += query;
    write += "\' > FinalResult.csv";
    cout << write << endl;

    system(write.c_str());

    unsigned int milliw;
    milliw = 400000;
    usleep(milliw);

    system("./tocloud.sh");





    inFileA.close();
    inFileB.close();
    inFileC.close();
    inFileD.close();
    outFile.close();


    cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;





  return 0;
}
