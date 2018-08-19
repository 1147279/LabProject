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

string decompress(string compressedWord, char isCompressed)
{
  int decompressedWord = "";
  string tempstring = "";
  if (compressedWord[0] == '1')
  {
    if (isCompressed == '0')
    {
      for (int i = 2 ; i < wordlength ; i++ )
      {
        decompressedWord += compressedWord[i];
      }
    }else
    {
      for (int l = 2 ; l < wordlength ; l ++)
      {
        tempstring += compressedWord[l];
      }
      for (int i = 0; i < convertToDecimal(tempstring) ; i++)
      {
        decompressedWord += compressedWord[1];
      }
    }
  }
  return decompressedWord;
}



int main()
{

  ifstream inputFileA;
  inputFileA.open("compressedbitstringA.txt", ifstream::in);

  ifstream inputFileB;
  inputFileB.open("compressedbitstringB.txt", ifstream::in);

  string compressedbitstringA;
  string compressedbitstringB;

  inputFileA >> compressedbitstringA;
  inputFileB >> compressedbitstringB;

  cout << ";;" << compressedbitstringA << endl;
  cout << ";;" << compressedbitstringB << endl;


  bool doneDecompressing = false;


  int bitsSoFarA = 0;
  int bitsSoFarB = 0;
  int bitsSoFarOut = 0;
  int unpackedA = 0;
  int unpackedB = 0;
  int iA = compressedbitstringA.length();
  int iB = compressedbitstringB.length();
  int numInAnd;

  string wordA = "";
  string wordB = "";
  string tempstringA = "";
  string tempstringB = "";
  string deCompressedA ="";
  string deCompressedB ="";
  string leftoverA = "";
  string leftoverB;
  string tempA = "";
  string tempB = "";

  int numOfBits;
  int bitsInA,bitsInB;
  int decNumA,decNumB;

  if (compressedbitstringA.length() >= compressedbitstringB.length())
  {
    numOfBits = compressedbitstringA.length();
  }else
  {
    numOfBits = compressedbitstringB.length();
  }

  while (bitsSoFarOut != numOfBits)
  {

    wordA += compressedbitstringA[iA-5];
    wordA += compressedbitstringA[iA-4];
    wordA += compressedbitstringA[iA-3];
    wordA += compressedbitstringA[iA-2];
    wordA += compressedbitstringA[iA-1];

    cout << "A: " << wordA << endl;

    wordB += compressedbitstringB[iB-5];
    wordB += compressedbitstringB[iB-4];
    wordB += compressedbitstringB[iB-3];
    wordB += compressedbitstringB[iB-2];
    wordB += compressedbitstringB[iB-1];

    cout << "B: "  << wordB << endl;

    for (int l = 2 ; l < wordlength ; l ++)
    {
      tempstringA += wordA[l];
      tempstringB += wordB[l];
    }

    bitsInA = convertToDecimal(tempstringA);
    bitsInB = convertToDecimal(tempstringB);




    while ((deCompressedA.length() < wordlength -2)&&(deCompressedB.length() < wordlength -2))
    {
      if (deCompressedA.length() < wordlength -2)
      {
        deCompressedA += decompress(wordA,wordA[0]);
        unpackedA += bitsInA;
      }
      if (deCompressedB.length() < wordlength -2)
      {
        deCompressedB += decompress(wordB,wordB[0]);
        unpackedB += bitsinB;
      }
    }


    if (bitsInA>bitsinB)
    {
      numInAnd = bitsinB;
      for (int i = 0; i < numInAnd ; i++)
      {
        tempB += deCompressedB[i];
        tempA += deCompressedB[i+bitsInA-bitsinB];

      }
      for (int i = 0 ; i < bitsInA-bitsinB; i++)
      {
        leftoverA += deCompressedA[i];
      }
    }else if (bitsinB>bitsInA)
    {
      numInAnd = bitsinB;
      for (int i = 0; i < numInAnd ; i++)
      {
        tempA += deCompressedB[i];
        tempB += deCompressedB[i+bitsInB-bitsinA];
      }
      for (int i = 0 ; i < bitsInB-bitsInA; i++)
      {
        leftoverB += deCompressedB[i];
      }
    }else
    {
      for (int i = 0; i < bitsInA ; i++)
      {
        tempA += deCompressedB[i];
        tempB += deCompressedB[i];
      }
    }







    tempstringA = "";
    tempstringB = "";
    wordA = "";
    wordB = "";

    cout << "A: " << bitsInA << endl;
    cout << "B: " << bitsInB << endl;


    iB -= wordlength;
    iA -= wordlength;

    bitsSoFarOut++;

  }


}
