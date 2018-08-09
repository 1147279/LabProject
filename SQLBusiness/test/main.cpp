#include <iostream>
#include <sqlite3.h> 

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	/*
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");*/
   
   

   for(int i = 0; i<argc; i++) {
      cout << azColName[i] << argv[i] << endl;
   }
   cout << endl;
   
   return 0;
}

int main(int argc, char** argv) {
   sqlite3 *db;
   char *zErrMsg = NULL;
   int rc;
   const char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);

   /* Create SQL statement */
   sql = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
 
   sqlite3_close(db);
   return 0;
}
