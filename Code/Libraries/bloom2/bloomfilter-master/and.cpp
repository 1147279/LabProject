#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <bitset>

using namespace std;

int wordlength = 5;

double convertToDecimal(string binNum)
{
  int h;
  double decNum=0;
  //cout << "binNum length: " << binNum.length() << endl;
  for (int i = 0 ; i < binNum.length() ; i++)
  {

    h = binNum.length() - i - 1;
    //cout << "i: " << i << " h: " << h << endl;
    //cout << (int)binNum[h]-48 << "*" << pow(2,i) << endl;
    decNum += ((int)binNum[h]-48)*(pow(2,i));
    //cout << "decNum: " << decNum << endl;
  }
  return decNum;
}


int main()
{

  ifstream inputFileA;
  inputFileA.open("compressedbitstringA.txt", ifstream::in);

  ifstream inputFileB;
  //inputFileB.open("compressedbitstringB.txt", ifstream::in);

  ofstream outFile;
  outFile.open("ResultString.txt", ofstream::out);

  string compressedStringA;
  string compressedStringB;
  string tempstring = "";

  inputFileA >> compressedStringA;
  inputFileB >> compressedStringB;
  //cout << "Comp string : " << compressedStringA;
  int numofWordsA = compressedStringA.length()/wordlength;
  double decNum;
  //cout << "num Words: " << numofWordsA << endl;

  int i = 0;
  int iB =0;
  int Asofar=0;
  int Bsofar=0;


  for (int j = 0 ; j < numofWordsA ; j++)
  {

    if ((compressedStringA[i+0] == '1')&&(compressedStringA[i+1] == '0'))
    {

      for (int l = 0 ; l < wordlength-2 ; l ++)
      {

        tempstring += compressedStringA[i+2+l];

      }

      decNum = convertToDecimal(tempstring);

      for (int k = 0; k< decNum ; k++)
      {
        outFile << compressedStringA[i+1];
      }
      tempstring = "";
      Asofar += decNum;


      while ((Asofar - Bsofar) > wordlength)
      {

        if ((compressedStringB[i+0] == '1'))
        {

          for (int l = 0 ; l < wordlength-2 ; l ++)
          {

            tempstring += compressedStringB[i+2+l];

          }

          decNum = convertToDecimal(tempstring);

          tempstring = "";
          Bsofar += decNum;
          iB += wordlength;

        }else if (compressedStringB[i+0] == '0')
        {
          iB += wordlength;
          Bsofar += wordlength;
        }
      }

    }else if ((compressedStringA[i+0] == '1')&&(compressedStringA[i+1] == '1'))
    {
      for (int l = 0 ; l < wordlength-2 ; l ++)
      {
        tempstring += compressedStringA[i+2+l];
      }

      decNum = convertToDecimal(tempstring);

      if (Bsofar < Asofar)
      {

      }


      for (int k = 0; k< decNum ; k++)
      {
        outFile << compressedStringA[i+1];
      }

      tempstring = "";
    }else if ((compressedStringA[i+0] == '0'))
    {

    }
    i += wordlength;
  }



}
