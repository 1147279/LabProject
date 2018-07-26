#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const char delimiter = '|';																					//Can be changed dependent on style of delimiter in database




//------------------------ Extract Key from KV-pair --------------------------//
string keyExtraction(const char& delimiter, string& kv_pair)
{
  string key= kv_pair.substr(0, kv_pair.find(delimiter));     			//Key is from index position 0, up until delimiter's position.
  return key;
};
//____________________________________________________________________________//

//----------------------- Determining joined KV-pair -------------------------//
 string hashJoin(string& commonKey, string& kv_A, string& kv_B)
 {

	 //Extracting Value A from KV_A
	 int value_A_start = kv_A.find(delimiter) + 1;
	 int value_A_length = kv_A.length() - value_A_start;
	 string value_A = kv_A.substr(value_A_start, value_A_length);

	 //Extracting Value B from KV_B
	 int value_B_start = kv_B.find(delimiter) + 1;
	 int value_B_length = kv_B.length() - value_B_start;
	 string value_B = kv_B.substr(value_B_start, value_B_length);

	 string joined_kv = commonKey + delimiter + value_A + delimiter + value_B;
	 return joined_kv;
 };
//____________________________________________________________________________//

int main(int argc, char *argv[])
{

  ifstream input_A;
  input_A.open("teble1.txt", ifstream::in);

  ifstream input_B;


  ofstream outFile;
  outFile.open("teble3.txt",ofstream::out);



  string kv_pair_A, key_A;

  string kv_pair_B, key_B;

  string join_kv;


  while (input_A >> kv_pair_A)
  {

    key_A= keyExtraction(delimiter, kv_pair_A);       //Extracting the key from the key-value pair read in from Table A.
    input_B.open("teble2.txt", ifstream::in);
    while (input_B >> kv_pair_B)
    {


      key_B = keyExtraction(delimiter, kv_pair_B);

      if (key_A == key_B)
      {
        join_kv = hashJoin(key_A, kv_pair_A, kv_pair_B);
        //cout << join_kv << '\n';
        outFile << join_kv << endl;

      }

    }
    input_B.close();


  }

  outFile.close();




	input_A.close();



  return 0;
}
