#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

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

  sqlite3 *db;
  char *zErrMsg = NULL;
  int rc;
  const char *sql;
  rc = sqlite3_open("Result.db", &db);

  string write="";
  write += "sqlite3 -header -csv \'Result.db\' \'select SUM(TEMPERATURE) from WEATHER;\' > SUM.csv";
  system(write.c_str());


}
