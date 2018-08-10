#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <bitset>

using namespace std;


string compressedString;


int main()
{

  int wordlength = 9;
  ifstream inFile;
  inFile.open("bitstring.txt",ifstream::in);

  ofstream outFile;
  outFile.open("compressedbitstring.txt",ofstream::out);

  char word [9] = {'0','0','0','0','0','0','0','0','0'};
  cout << word<<endl;

  string bitstring;

  inFile >> bitstring;

  int i = 0;
  word[1] = bitstring[i];
  int count = 1;

  for (int i = 0 ; i < bitstring.length() ;i ++)
  {

    if (bitstring[i+1] != word[1])
    {

      if (count > wordlength)
      {
        word[0] = '1';

        //cout << "word in count > wordlength: " << word << endl;
        //cout << "count: " << count <<endl;
        compressedString = bitset<7>(count).to_string();
        //cout << "binary num: " << compressedString << endl;
        for (int j = 2; j < wordlength ; j++)
        {
          word[j] = compressedString[j-2];
          //cout << "word in count > wordlength in in: " << word << endl;
        }
        cout << word << endl;
        outFile << word ;
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
        outFile << word ;
        cout << "------------------------------------------: " << endl;
      }

      count = 1;

    }else
    if (bitstring[i+1] == bitstring[i])
    {
      count++;
    }




    //i++;

    word[1] = bitstring[i];

    //cout << "We've had " << count << " " << word[1] << "'s" << endl;
  }




}
