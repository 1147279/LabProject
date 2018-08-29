#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <bitset>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <sqlite3.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;



int main ()
{

	unsigned int milli ;//= 500000;
  milli = 100000;

	system("sudo service ssh start");
	ifstream inputres;


	while(1)
	{
		inputres.open("joinReq.txt");
		if (inputres)
		{
			break;
		}
	}

	inputres.close();

	cout << "csv..." << endl;




	usleep(milli);

	cout << "Request Received" << endl;





	system("sqlite3 -header -csv \'humidity.db\' \'select * from HUMIDITY; \' > outHum.csv");



	system("./sendCSV2.sh");
	//cout << str << endl;
	//cout << compressedString << endl;

	//cout << "Cloud Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;


	return 0;
}
