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
  inputFileB.open("compressedbitstringB.txt", ifstream::in);

  ofstream outFile;
  outFile.open("AndResult.txt", ofstream::out);

  string compressedStringA;
  string compressedStringB;
  string tempstringA = "";
  string tempstringB = "";

  inputFileA >> compressedStringA;
  inputFileB >> compressedStringB;
  //cout << "Comp string : " << compressedStringA;
  int numofWordsA = compressedStringA.length()/wordlength;
  double decNumA,decNumB;
  //cout << "num Words: " << numofWordsA << endl;;

  int i =0;
  int iA = 0;
  int iword = 0;
  int iB =0;
  double Asofar=0;
  double Bsofar=0;
  string word = "";
  double outSofar = 0;

  bool comp1A,comp1B,mixedA,mixedB,comp0A,comp0B;
  comp1A = comp1B = mixedA = mixedB = comp0A = comp0B = false;

  while (iword < numofWordsA)
  {
    //1011101110
    if ((compressedStringA[iA+0] == '1')&&(compressedStringA[iA+1] == '0'))
    {
      comp0A = true;
    }else if ((compressedStringA[iA+0] == '1')&&(compressedStringA[iA+1] == '1'))
    {
      comp1A = true;
    }else if (compressedStringA[iA+0] == '0')
    {
      mixedA = true;
    }


    if ((compressedStringB[iB+0] == '1')&&(compressedStringB[iB+1] == '0'))
    {
      comp0B = true;
    }else if ((compressedStringB[iB+0] == '1')&&(compressedStringB[iB+1] == '1'))
    {
      comp1B = true;
    }else if (compressedStringB[iB+0] == '0')
    {
      mixedB = true;
    }

    cout << "compA1: " << comp1A << "  compB1: " << comp1B << endl;
    cout << "compA0: " << comp0A << "  compB0: " << comp0B << endl;
    cout << "liteAM: " << mixedA << "  liteBM: " << mixedB << endl;
    cout << endl;

    if ((comp0A)&&(comp0B))
    {

      for (int l = 0 ; l < wordlength-2 ; l ++)
      {
        tempstringA += compressedStringA[iA+2+l];
        tempstringB += compressedStringB[iB+2+l];
      }

      decNumA = convertToDecimal(tempstringA);
      cout << "deca: " << decNumA << endl;
      Asofar += decNumA;

      decNumB = convertToDecimal(tempstringB);
      cout << "decb: " << decNumB << endl;
      Bsofar += decNumB;


      if (decNumA > decNumB)
      {
        //10111
        word += compressedStringA[iA+0];
        word += compressedStringA[iA+1];
        word += tempstringA;
        cout << word << endl;
        outFile << word;
        word = "";
        outSofar += decNumA;
        tempstringA = "";
        tempstringB = "";

        for (int l = 0 ; l < wordlength-2 ; l ++)
        {
          tempstringB += compressedStringB[iB+wordlength+2+l];
        }

        while ((Bsofar+convertToDecimal(tempstringB) <= outSofar)&&(Bsofar >0))
        {
          cout << "tmpstring: " << convertToDecimal(tempstringB) << endl;
          Bsofar += convertToDecimal(tempstringB);
          iB += wordlength;
          tempstringB = "";
          for (int l = 0 ; l < wordlength-2 ; l ++)
          {
            tempstringB += compressedStringB[iB+wordlength+2+l];
          }
          cout << "bsofar: " << Bsofar << endl;

        }
        tempstringB = "";
        //Bsofar = outSofar ;


      } else
      {
        word += compressedStringB[iB+0];
        word += compressedStringB[iB+1];
        word += tempstringB;
        cout << word << endl;
        outFile << word;
        word = "";
        outSofar += decNumB;
        tempstringA = "";
        tempstringB = "";

        for (int l = 0 ; l < wordlength-2 ; l ++)
        {
          tempstringA += compressedStringA[iA+wordlength+2+l];
        }



        while (Asofar+convertToDecimal(tempstringA) <= outSofar)
        {

          Asofar += convertToDecimal(tempstringA);
          iA += wordlength;
          tempstringA = "";
          for (int l = 0 ; l < wordlength-2 ; l ++)
          {
            tempstringA += compressedStringA[iA+wordlength+2+l];
          }
          cout << "bsofar: " << Asofar << endl;
        }
        tempstringA = "";
      }




    }else if ((comp0A)&&(comp1B))
    {
      cout << " Not yet " << endl;

      for (int l = 0 ; l < wordlength-2 ; l ++)
      {
        tempstringA += compressedStringA[iA+2+l];
        tempstringB += compressedStringB[iB+2+l];
      }

      decNumA = convertToDecimal(tempstringA);
      cout << "deca: " << decNumA << endl;
      //Asofar += decNumA;

      decNumB = convertToDecimal(tempstringB);
      cout << "decb: " << decNumB << endl;
      //Bsofar += decNumB;


      if (decNumA > decNumB)
      {
        word += compressedStringA[iA+0];
        word += compressedStringA[iA+1];
        word += tempstringA;
        cout << word << endl;
        outFile << word;
        word = "";
        outSofar += decNumA;
        tempstringA = "";
        tempstringB = "";

        for (int l = 0 ; l < wordlength-2 ; l ++)
        {
          tempstringB += compressedStringB[iB+wordlength+2+l];
        }

        while (Bsofar+convertToDecimal(tempstringB) <= outSofar)
        {

          Bsofar += convertToDecimal(tempstringB);
          iB += wordlength;
          tempstringB = "";
          for (int l = 0 ; l < wordlength-2 ; l ++)
          {
            tempstringB += compressedStringB[iB+wordlength+2+l];
          }
          cout << "bsofar: " << Bsofar << endl;
        }




      } else
      {
        word += compressedStringB[i+0];
        word += compressedStringB[i+1];
        word += tempstringA;
        cout << word << endl;
        outFile << word;
        word = "";
        outSofar += decNumA;

      }

    }else if ((comp0A)&&(mixedB))
    {
      cout << " Not yet " << endl;
    }else if ((comp1A)&&(comp0B))
    {
      cout << " Not yet " << endl;
    }else if ((comp1A)&&(comp1B))
    {
      cout << " Not yet " << endl;
    }else if ((comp1A)&&(mixedB))
    {
      cout << " Not yet " << endl;
    }else if ((mixedA)&&(mixedB))
    {
      cout << " Not yet " << endl;
    }



/*
    for (int l = 0 ; l < wordlength-2 ; l ++)
    {
      tempstringA += compressedStringA[i+2+l];
      tempstringB += compressedStringB[i+2+l];
    }

    decNumA = convertToDecimal(tempstringA);
    decNumB = convertToDecimal(tempstringB);

    cout << "decNumA: " << decNumA << endl;
    cout << "decNumB: " << decNumB << endl;
*/

    iword ++;
    i += wordlength;
  }


  outFile.close();



/*
  while ((compressedStringA[i+0] == '1')&&(compressedStringA[i+1] == '0'))
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
  */





}
