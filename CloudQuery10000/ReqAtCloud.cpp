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




    cout << "Type Command: " <<endl;


    string temp = "";
    char query[256];
    string queryTwo = "";

    cin.getline (query,256);

    string write ="";



    //cout << query << endl;


    write += "echo \'";
    write += query;
    write += "\' > instruct.txt";
    system(write.c_str());




    system("./sendReqJohn.sh");
    system("./sendReqRichard.sh");
    system("./sendReqAudrey.sh");



    cout << "Requests Sent to fog Gateways." << endl;


    ifstream inFileA;
    ifstream inFileB;
    ifstream inFileC;


    cout << "Waiting For Data from Fog Gateways..." << endl;


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




    string ID,year,month,day,hour,minute,second;
    string location;
    string temperature;

    usleep(milli);
    ofstream outFile;
    inFileA.open("FinalResultRichard.csv",ifstream::in);
    inFileB.open("FinalResultJohn.csv",ifstream::in);
    inFileC.open("FinalResultAudrey.csv",ifstream::in);



    outFile.open("EndResult.txt",ofstream::out);

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



    sqlite3_close(db);


    string write ="";







    write = "";
    write += "sqlite3 -header -csv \'Result.db\' \'";
    write += query;
    write += "\' > EndResult.csv";
    cout << write << endl;

    system(write.c_str());

    usleep(milli);



    inFileA.close();
    inFileB.close();
    inFileC.close();

    outFile.close();



  return 0;
}
