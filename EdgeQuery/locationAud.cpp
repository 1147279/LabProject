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



void initialiseString(string& str, int strSize)
{
	str = "";
	for(int i = 0; i < strSize; i++)
		str += "0";
}




bool bloomFilterContains (string& str, string& bitString)
{
	int hash1;
	int hash2;
	int hash3;
	int asciNum = asciiSum(str);
  cout << asciNum;
  int num1;// = asciNum;
  num1 = (asciNum-1555)*5112+2*asciNum; //+powerFunction((asciNum/2+powerFunction(num1, 2)),2)+3*(asciNum/23);

	int num2 = asciNum ;
  num2= powerFunction(num2, 3)+powerFunction((asciNum/3+powerFunction(asciNum, 3)),2)-3*(asciNum/21);

	int num3 = asciNum ;
  num3= (asciNum/1023)*(499*asciNum)-17825;//powerFunction(num3, 1)+powerFunction((num3/4+powerFunction(asciNum, 4)),2)+3*(asciNum/17);


	hash1 = moding(num1, bitString);
	hash2 = moding(num1, bitString);
	hash3 = moding(num1, bitString);

	if(bitString.at(hash1) == '0')
		return false;

	if(bitString.at(hash2) == '0')
		return false;

	if(bitString.at(hash3) == '0')
		return false;


	return true;
}


void setBloomFilter(string fileName, string& str)
{
	ifstream input;
	input.open(fileName,ifstream::in);
	str = "";
	input >> str;

	input.close();
}



int main(int argc, char** argv)
{

  unsigned int milli ;//= 500000;
  milli = 100000;
  string query;
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

  inFileA.open("reqQuery.txt",ifstream::in);



  rc = sqlite3_open("TAud.db", &db);

  char req[256];

  inFileA.getline (req,256);

  string write ="";

  string bloomfilter ;
  setBloomFilter("BloomLocationA.txt",bloomfilter);


  if (bloomFilterContains(str(req),bloomfilter))
  {
    cout << "Its in there..." << endl;
    cout << write << endl;


    write += "sqlite3 -header -csv \'TAud.db\' \'select * from WEATHER where LOCATION = ";
    write += req;
    write += "\' > outTempAudrey.csv";
    cout << write << endl;


    system(write.c_str());

  }else
  {
    ofstream oFile;
    oFile.open("outTempAudrey.csv");
    oFile << "No"<<endl;
    oFile.close();
  }





  system("sudo service ssh start");

  system("./audreyReply.sh");




	sqlite3_close(db);
	inFileA.close();







return 0;
}
