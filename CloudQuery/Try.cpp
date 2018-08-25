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

  cin.getline (query,256);

  string write ="";




    string tempString ="";
    sqlite3 *db;
  	char *zErrMsg = NULL;
  	int rc;
  	const char *sql;
    rc = sqlite3_open("Result.db", &db);

      tempString = ".mode csv";
      sql = tempString.c_str();
      cout << sql << endl;
    	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

      tempString = ".import outTempJohn.csv WEATHER";
      sql = tempString.c_str();
      cout << sql << endl;
    	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);



      //attach database 'AA.db' as gg;insert into main.WEATHER select * from gg.WEATHER;




    sqlite3_close(db);







  return 0;
}
