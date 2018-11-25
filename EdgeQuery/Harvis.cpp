#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>




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
  //string query;
	sqlite3 *db;
	char *zErrMsg = NULL;
	int rc;
	const char *sql;

  cout << "Waiting For Request..." << endl;

  ifstream inFileA;

  while(1)
  {
    inFileA.open("reqQuery.txt",ifstream::in);
    if (inFileA)
    {
      break;
    }
  }

  inFileA.close();
  usleep(milli);




  string write ="";

  char query[256];
  ifstream queryFile;
  queryFile.open("reqQuery.txt");
  queryFile.getline (query,256);

  cout << write << endl;


  write += "sqlite3 -header -csv \'THarvis.db\' \'";
  write += query;
  write += "\' > outTempHarvis.csv";
  cout << write << endl;

  system(write.c_str());

  system("sudo service ssh start");

  system("./harvisReply.sh");


  queryFile.close();

	//sqlite3_close(db);








return 0;
}
