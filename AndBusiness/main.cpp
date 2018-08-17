#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <bitset>
#include <string>
#include <string.h>

using namespace std;

int powerFunction(int base, int power); // works
int binaryStringToDecimal(string str);
string decompressString(string str);
string logicalEnd(string str1, string str2);
string compressString(string bitstring);









int main ()
{

	cout << compressString("11111")<< endl;
}




int powerFunction(int base, int power)
{
	int number = base;

	if(power == 0)
	{
		return 1;
	}else if (power > 0)
	{
		for (int i = 0; i < power - 1 ; i++)
		{
			number *= base;
		}
	}
	return number;
}



int binaryStringToDecimal(string str)
{
	int stringSize = str.size();
	int temp;
	int sum = 0;
	for(int i = 0; i < stringSize; i++)
	{
		temp = str.at(stringSize - i - 1) - '0';
		temp = temp*powerFunction(2, i);
		sum += temp;
	}

	return sum;
}


string decompressString(string str)
{
	string temp = "";
	string word = "";
	int stringSize = str.size();
	bool isCompressed = false;

	if(str.at(0) == '1')
		isCompressed = true;

	if(isCompressed == false)
	{
		for(int i = 2; i < stringSize; i++)
		{
			word += str.at(i);
		}
		return word;
	}else
	{
		temp = str.at(1);

		for(int i = 2; i < stringSize; i++)
			word = word + str.at(i);

		int numOfBits = binaryStringToDecimal(word);
		word = "";
		cout << "Number of ones " << numOfBits << endl;

		for(int i = 0; i < numOfBits; i++)
			word = word + temp;
		return word;
	}

}


string logicalEnd(string str1, string str2)
{
	if(str1.size() != str2.size())
		return "";

	int stringSize = str1.size();
	string result = "";

	for(int i = 0; i < stringSize; i++)
		result += "0";

	for(int i = 0; i < stringSize; i++)
	{
		if(str1.at(i) == '1' && str2.at(i) == '1')
			result.at(i) = '1';
		else
			result.at(i) = '0';
	}

	return result;

}

string compressString(string bitstring)
{
/*
	ifstream inFile;
  inFile.open("bitstring.txt",ifstream::in);

  ofstream outFile;
  outFile.open("compressedbitstring.txt",ofstream::out);
*/
	string compressedString;
	string result = "";
	int wordlength = 6;
  int newwordnum;
  string newword = "";


  char word [20] ;


  int i = 0;
  word[1] = bitstring[i];
  int count = 1;

  while (i< bitstring.length())// != '\n')
  {

    if (bitstring[i+1] != word[1])
    {

      if ((count >= wordlength)&&(count <= pow(2,(wordlength-2))-1))
      {
        word[0] = '1';

        //cout << "word in count > wordlength: " << word << endl;
        //cout << "count: " << count <<endl;
        compressedString = bitset<3>(count).to_string();
        //cout << "binary num: " << compressedString << endl;
        for (int j = 2; j < wordlength ; j++)
        {
          word[j] = compressedString[j-2];
          //cout << "word in count > wordlength in in: " << word << endl;
        }
        cout << "A: " <<word << endl;
        result += word;
        cout << "------------------------------------------: " << endl;

      }else
      if (count < wordlength)
      {
        //cout << "i: " << i <<endl;
        word[0] = '0';
        //cout << "word in count < wordlength " << word << endl;
        int leftover = 2;
        for (int j = 0 ; j < count ; j++)
        {
          word[j+2] = word[1];
          leftover++;
          //cout << "word in count < wordlength in in " << word << endl;
        }
        for (int j = leftover  ; j < wordlength; j++)
        {
          word[j] = bitstring[i+1];
          //cout << "word in count < wordlength in in in " << word << endl;
          i++;
        }

        if (strlen(word) != wordlength)
        {
          newwordnum = strlen(word) - 2;
          cout << "newwordnum " << newwordnum<< endl;
          for (int p = 0; p < newwordnum ; p++)
          {
            newword = "";
            newword += "1";
            newword += word[p+2];
            newword += "001";
            cout << newword << endl;
            result += newword;

            cout << "------------------------------------------: " << endl;

          }
        }else
        {
          cout << "B: " << word << endl;
          result += word;
          cout << "------------------------------------------: " << endl;
        }
      }

      count = 1;

    }else
    if ((bitstring[i+1] == bitstring[i])&&(count < pow(2,(wordlength-2))-1))
    {

      //cout << " count : "<<count << endl;
      count++;


    }else
    if ((bitstring[i+1] == bitstring[i])&&(count == pow(2,(wordlength-2))-1))
    {

      word[0] = '1';

      //cout << "word in count > wordlength: " << word << endl;
      //cout << "count: " << count <<endl;
      compressedString = bitset<3>(count).to_string();
      //cout << "binary num: " << compressedString << endl;
      for (int j = 2; j < wordlength ; j++)
      {
        word[j] = compressedString[j-2];
        //cout << "word in count > wordlength in in: " << word << endl;
      }
      cout <<"C: " << word << endl;
      result += word;
      //cout << " count : "<<count << endl;
      cout << "------------------------------------------: " << endl;
      count =1;
    }



    i++;

    word[1] = bitstring[i];

    //cout << "We've had " << count << " " << word[1] << "'s" << endl;
  }

  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;

	return result;

}
