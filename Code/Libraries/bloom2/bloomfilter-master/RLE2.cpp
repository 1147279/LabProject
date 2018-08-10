#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <bitset>

using namespace std;

int wordlength = 15;
string compressedString;


int main()
{
  ifstream inFile;
  inFile.open("bitstring.txt",ifstream::in);

  ofstream outFile;
  outFile.open("compressedbitstring.txt",ofstream::out);


  char word [15] ;

  string bitstring;

  inFile >> bitstring;

  int i = 0;
  word[1] = bitstring[i];
  int count = 1;

  while (i< bitstring.length())// != '\n')
  {

    if (bitstring[i+1] != word[1])
    {

      if ((count > wordlength)&&(count < pow(2,(wordlength-2))-1))
      {
        word[0] = '1';

        //cout << "word in count > wordlength: " << word << endl;
        //cout << "count: " << count <<endl;
        compressedString = bitset<13>(count).to_string();
        //cout << "binary num: " << compressedString << endl;
        for (int j = 2; j < wordlength ; j++)
        {
          word[j] = compressedString[j-2];
          //cout << "word in count > wordlength in in: " << word << endl;
        }
        cout << word << endl;
        outFile << word;
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
        cout << word << endl;
        outFile << word;
        cout << "------------------------------------------: " << endl;
      }

      count = 1;

    }else
    if ((bitstring[i+1] == bitstring[i])&&(count < pow(2,(wordlength-2))-1))
    {

      cout << " count : "<<count << endl;
      count++;


    }else
    if ((bitstring[i+1] == bitstring[i])&&(count == pow(2,(wordlength-2))-1))
    {

      word[0] = '1';

      //cout << "word in count > wordlength: " << word << endl;
      //cout << "count: " << count <<endl;
      compressedString = bitset<13>(count).to_string();
      //cout << "binary num: " << compressedString << endl;
      for (int j = 2; j < wordlength ; j++)
      {
        word[j] = compressedString[j-2];
        //cout << "word in count > wordlength in in: " << word << endl;
      }
      cout << word << endl;
      outFile << word;
      cout << " count : "<<count << endl;
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


}
