#include <iostream>
#include <sqlite3.h> 
#include <fstream>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) 
{

   for(int i = 0; i<argc; i++) {
      cout << azColName[i] << argv[i] << endl;
   }
   cout << endl;
   
   return 0;
}

int main(int argc, char** argv) {
	
	ifstream input;
	input.open("input.txt");
	
	sqlite3 *db;
	char *zErrMsg = NULL;
	int rc;
	const char *sql;

	/* Open database */
	rc = sqlite3_open("test.db", &db);

	/* Create SQL statement */
	//sql = "SELECT * from COMPANY";
	string tempString;

	
	getline(input, tempString);
	
	cout << tempString << endl;
	sql = tempString.c_str();
	/* Execute SQL statement */
	system("sqlite3 -header -csv 'test.db' 'select * from COMPANY;' > out.csv");
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);


	sqlite3_close(db);
	input.close();
return 0;
}
