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

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{

   for(int i = 0; i<argc; i++) {
      cout << azColName[i] << argv[i] << endl;
   }
   cout << endl;

   return 0;
}


int powerFunction(int base, int power);
int binaryStringToDecimal(string str);
string decompressString(string str);
string logicalEnd(string str1, string str2);
string compressString(string bitstring, int wordlength);
string decompressor(int index, int wordLength, string& str);
string decimalToBinary(int num, int bitStreamLength);
void andingStrings(string& strA, string& strB, int& wordLength, string& str, string& compressedString);
void setBloomFilter(string fileName, string& str);
bool bloomFilterContains (string& str, string& bitString);
int moding(int& num, string& str);
int asciiSum(string str);
string Decomp(string compressed,int wordlength);



int main ()
{

  cout << "Waiting For Cloud Request..." << endl;
  ifstream waitfor;

  while(1)
  {
    waitfor.open("instruct.txt",ifstream::in);
    if (waitfor)
    {
      break;
    }
  }

  waitfor.close();


	unsigned int milli ;//= 500000;
  milli = 400000;

	ifstream input;
	ifstream infile;


	cout << "Sending Request For Join.." << endl;

	system("sudo service ssh start");

	system("./startRichard.sh");



	while(1)
	{
		input.open("ForJoin.csv");
		if (input)
		{
			break;
		}
	}

	input.close();

	cout << "Join Ralph Received" << endl;

	while(1)
	{
		infile.open("ForJoin2.csv");
		if (infile)
		{
			break;
		}
	}

	infile.close();

	cout << "Join Courage Received" << endl;


  while(1)
	{
		infile.open("compressedbloomFinalRichard.txt");
		if (infile)
		{
			break;
		}
	}

	infile.close();

	cout << "Richard Bloom filter Received" << endl;

	usleep(milli);

	string inputString;
	string tempString;

	//inputString = "input.txt";


	input.open("ForJoin.csv");

  system("./sendBloomJohn.sh");
  system("./sendBloomAudrey.sh");


  while(1)
	{
		infile.open("compressedbloomFinalAudrey.txt");
		if (infile)
		{
			break;
		}
	}

	infile.close();

	cout << "Audrey Bloom filter Received" << endl;




	int wordlength =14;
	ifstream inputAudrey;
	ifstream inputRichard;

  inputAudrey.open("compressedbloomFinalAudrey.txt");
  inputRichard.open("compressedbloomFinalRichard.txt");

  string compressedRichardBloom,RichardBloom;
  compressedRichardBloom="";
  RichardBloom = "";
  inputRichard >> compressedRichardBloom;
  cout << "compressedRichardBloom size: "<< compressedRichardBloom.size()<<endl;



  string compressedAudreyBloom,AudreyBloom;
  compressedAudreyBloom="";
  AudreyBloom = "";
  inputAudrey >> compressedAudreyBloom;
  cout << "compressedAudreyBloom size: "<< compressedAudreyBloom.size()<<endl;



  int sz = compressedAudreyBloom.size()/wordlength;
  int sz2 = compressedRichardBloom.size()/wordlength;

  for (int i = 0 ; i < sz ; i++)
  {
    AudreyBloom = decompressor(i,wordlength,compressedAudreyBloom) + AudreyBloom;
  }

  for (int i = 0 ; i < sz2 ; i++)
  {
    RichardBloom = decompressor(i,wordlength,compressedRichardBloom) + RichardBloom;
  }

  cout << "AudreyBloom size: "<< AudreyBloom.size()<<endl;
  cout << "RichardBloom size: "<< RichardBloom.size()<<endl;

  string resBloom = logicalEnd(RichardBloom,AudreyBloom);

  cout << "resbloom size: "<< resBloom.size()<<endl;


  ofstream output;
  output.open("resultingBitStringRoundOne.txt",ofstream::out);

  output << resBloom;

  output.close();






//ROUND 2

  while(1)
  {
    infile.open("compressedbloomFinalJohn.txt");
    if (infile)
    {
      break;
    }
  }

  infile.close();

  cout << "John Bloom filter Received" << endl;




  //int wordlength =14;
  ifstream inputJohn;


  inputJohn.open("compressedbloomFinalJohn.txt");



  string compressedJohnBloom,JohnBloom;
  compressedJohnBloom="";
  JohnBloom = "";
  inputJohn >> compressedJohnBloom;
  cout << "compressedJohnBloom size: "<< compressedJohnBloom.size()<<endl;



  sz = compressedJohnBloom.size()/wordlength;


  for (int i = 0 ; i < sz ; i++)
  {
    JohnBloom = decompressor(i,wordlength,compressedJohnBloom) + JohnBloom;
  }

  cout << "JohnBloom size: "<< JohnBloom.size()<<endl;
  cout << "RoundOneBloom size: "<< resBloom.size()<<endl;

  string resBloom2 = logicalEnd(resBloom,JohnBloom);

  cout << "resbloom2 size: "<< resBloom2.size()<<endl;



  output.open("resultingBitStringRoundTwo.txt",ofstream::out);

  output << resBloom2;

  output.close();






  /*
  string resBloomCompd = compressString(resBloom,wordlength);

  ofstream outputcomp;
  outputcomp.open("resultingBitStringCompressed.txt",ofstream::out);

  char one;

  for (int i =0; i < resBloomCompd.size();i++)
  {
    one = resBloomCompd[i];
    outputcomp.put(one);
  }




  outputcomp.close();

  */
  string bloomKey;
  string ID,year,month,day,hour,minute,second;
	string location;
	string humidity;

  ifstream firstcsv;
	firstcsv.open("ForJoin.csv");


  string decompResultBloom = resBloom2;

  ofstream participators;
	participators.open("ForJoinReduced.csv");

	tempString= "";
  setBloomFilter("resultingBitStringRoundTwo.txt",decompResultBloom);

	string firstline;
	firstcsv >> firstline;

	while (firstcsv.good())
	{
		getline(firstcsv,ID,',');
		getline(firstcsv,year,',');
		getline(firstcsv,month,',');
		getline(firstcsv,day,',');
		getline(firstcsv,hour,',');
		getline(firstcsv,minute,',');
		getline(firstcsv,second,',');
		getline(firstcsv,location,',');
		getline(firstcsv,humidity,'\n');



		tempString += ID;
		tempString += ",";
		tempString += year;
		tempString += ",";
		tempString += month;
		tempString += ",";
		tempString += day;
		tempString += ",";
		tempString += hour;
		tempString += ",";
		tempString += minute;
		tempString += ",";
		tempString += second;
		tempString += ",";
		tempString += "\'";
		tempString += location;
		tempString += "\'";
		tempString += ",";
		tempString += humidity;

		cout << tempString << endl;

		bloomKey += "\'";
		bloomKey += location;
		bloomKey += "\'";
    bloomKey += year;
    bloomKey += month;
    bloomKey += day;
    bloomKey += hour;
    bloomKey += minute;
    bloomKey += second;

		cout << "----------------------" << endl;
		cout << bloomKey << endl;
		cout << "----------------------" << endl;


		if (bloomFilterContains(bloomKey,decompResultBloom))
	  {
			participators << tempString <<endl;
	  }

		bloomKey = "";
		tempString="";

	}



  decompResultBloom = resBloom2;


  firstcsv.close();
	firstcsv.open("ForJoin2.csv");



  participators.close();
	participators.open("ForJoinReduced2.csv");

	tempString= "";
  setBloomFilter("resultingBitStringRoundTwo.txt",decompResultBloom);

	firstline="";
	firstcsv >> firstline;

	while (firstcsv.good())
	{
		getline(firstcsv,ID,',');
		getline(firstcsv,year,',');
		getline(firstcsv,month,',');
		getline(firstcsv,day,',');
		getline(firstcsv,hour,',');
		getline(firstcsv,minute,',');
		getline(firstcsv,second,',');
		getline(firstcsv,location,',');
		getline(firstcsv,humidity,'\n');



		tempString += ID;
		tempString += ",";
		tempString += year;
		tempString += ",";
		tempString += month;
		tempString += ",";
		tempString += day;
		tempString += ",";
		tempString += hour;
		tempString += ",";
		tempString += minute;
		tempString += ",";
		tempString += second;
		tempString += ",";
		tempString += "\'";
		tempString += location;
		tempString += "\'";
		tempString += ",";
		tempString += humidity;

		cout << tempString << endl;

		bloomKey += "\'";
		bloomKey += location;
		bloomKey += "\'";
    bloomKey += year;
    bloomKey += month;
    bloomKey += day;
    bloomKey += hour;
    bloomKey += minute;
    bloomKey += second;

		cout << "----------------------" << endl;
		cout << bloomKey << endl;
		cout << "----------------------" << endl;


		if (bloomFilterContains(bloomKey,decompResultBloom))
	  {
			participators << tempString <<endl;
	  }

		bloomKey = "";
		tempString="";

	}



  participators.close();



















  system("./tocloudRichard.sh");




	return 0;
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

string compressString(string bitstring, int wordlength)
{

  int newwordnum;
	string cword = "";
  string newword = "";
	string compressedString;

  char word [14] ;

  string result = "";

  int i = 0;
  word[1] = bitstring[i];
  int count = 1;

  while (i< bitstring.length())// != '\n')
  {

    if (bitstring[i+1] != word[1])
    {

      if ((count >= wordlength-2)&&(count <= pow(2,(wordlength-2))-1))
      {
        word[0] = '1';

        //cout << "word in count > wordlength: " << word << endl;
        //cout << "count: " << count <<endl;
        compressedString = decimalToBinary(count, wordlength-2);
        //cout << "binary num: " << compressedString << endl;
        for (int j = 2; j < wordlength ; j++)
        {
          word[j] = compressedString[j-2];
          //cout << "word in count > wordlength in in: " << word << endl;
        }
        //cout << "A: " <<word << endl;
				cword=word;
        result += cword;
        //cout << "------------------------------------------: " << endl;

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
          //cout << "newwordnum " << newwordnum<< endl;
          for (int p = 0; p < newwordnum ; p++)
          {
            newword = "";
            newword += "1";
            newword += word[p+2];
            //newword += "001";
            for (int h = 2 ; h < wordlength-1 ; h++)
            {
              newword += "0";
            }
            newword+="1";
            //cout << newword << endl;
						cword = newword;
            result += cword;

            //cout << "------------------------------------------: " << endl;

          }
        }else
        {
          //cout << "B: " << word << endl;
					cword=word;
	        result += cword;
          //cout << "------------------------------------------: " << endl;
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
      compressedString = decimalToBinary(count, wordlength-2);
      //cout << "binary num: " << compressedString << endl;
      for (int j = 2; j < wordlength ; j++)
      {
        word[j] = compressedString[j-2];
        //cout << "word in count > wordlength in in: " << word << endl;
      }
      //cout <<"C: " << word << endl;
			cword=word;
			result += cword;
      //cout << " count : "<<count << endl;
      //cout << "------------------------------------------: " << endl;
      count =1;
    }



    i++;

    word[1] = bitstring[i];

    //cout << "We've had " << count << " " << word[1] << "'s" << endl;
  }
  //cout << "compressed:   "<<result << endl;
	string newres = result;
  return newres;
}

string decompressor(int index, int wordLength, string& str)
{
	string temp = "";

	temp = str.substr(str.size() - (1+index)*wordLength, wordLength);
	temp = decompressString(temp);
	return temp;
}

string decimalToBinary(int num, int bitStreamLength)
{
	int temp = num;
	string result = "";
	char storage;
	while(temp > 0)
	{
		storage = temp%2 + '0';
		result = storage + result;
		temp = temp >> 1; // use bit shifting
	}


	for(int i = result.size(); i < bitStreamLength; i++)
	{
		result = '0' + result;
	}

	return result;
}




void andingStrings(string& strA, string& strB, int& wordLength,string& str, string& compressedString)
{
	string result = "";

	int stringASize = strA.size();
	int stringBSize = strB.size();


	wordLength = wordLength;
	int strASize = stringASize;
	int strBSize = stringBSize;
	int divisionsA = strASize/wordLength;
	int divisionsB = strBSize/wordLength;


	string tempA = "";
	string tempB = "";



	for(int i = 0; i < divisionsA; i++)
	{
		tempA =   decompressor(i, wordLength,  strA) + tempA;
	}
	//cout << "A decompressed size "<< tempA.size() << endl;

	for(int i = 0; i < divisionsB; i++)
	{
		tempB =   decompressor(i, wordLength,  strB) + tempB;
	}
	//cout << "B decompressed size "<< tempB.size() << endl;

	string temp = "";
	temp = logicalEnd(tempA, tempB);


	/*
	cout <<"string A " <<  tempA << endl;
	cout <<"string B " <<  tempB << endl;
	cout <<"string R " <<  temp << endl;
	*/

	string tempA1;
	string tempB1;

	tempA = "";
	tempB = "";


	int decompresseddedWordLength = wordLength;
	temp = "";

	int stringTempASize = 0;
	int stringTempBSize = 0;

	int divisions;

	if(divisionsA > divisionsB)
	{
		divisions = divisionsA;
	}else if(divisionsA > divisionsB)
	{
		divisions = divisionsB;
	}else
	{
		divisions = divisionsB;
	}

	for(int i = 0; i < divisions; i++)
	{
		if(i < divisionsA)
		{
			tempA =   decompressor(i, decompresseddedWordLength,  strA) + tempA;
			//cout << "tempA " << tempA << endl;
		}


		if(i < divisionsB)
		{
			tempB =   decompressor(i, decompresseddedWordLength,  strB) + tempB;
			//cout << "tempB " << tempB << endl;
		}



		if(i < divisions - 1)
		{
			while(true)
			{
				if(tempA.size() == decompresseddedWordLength && tempB.size() == decompresseddedWordLength)
				{
					temp = logicalEnd(tempA, tempB) + temp;
					tempA = "";
					tempB = "";
					break;

				}else if(tempA.size() > decompresseddedWordLength && tempB.size() > decompresseddedWordLength)
				{
					stringTempASize = tempA.size();
					tempA1 = tempA.substr(stringTempASize - decompresseddedWordLength, decompresseddedWordLength);
					tempA = tempA.substr(0, stringTempASize - decompresseddedWordLength);

					stringTempBSize = tempB.size();
					tempB1 = tempB.substr(stringTempBSize - decompresseddedWordLength, decompresseddedWordLength);
					tempB = tempB.substr(0, stringTempBSize - decompresseddedWordLength);

					temp = logicalEnd(tempA1, tempB1) + temp;

				}else if(tempA.size() > decompresseddedWordLength && tempB.size() == decompresseddedWordLength)
				{
					stringTempASize = tempA.size();
					tempA1 = tempA.substr(stringTempASize - decompresseddedWordLength, decompresseddedWordLength);
					tempA = tempA.substr(0, stringTempASize - decompresseddedWordLength);

					temp = logicalEnd(tempA1, tempB) + temp;
					tempB = "";
					break;

				}else if(tempA.size() == decompresseddedWordLength && tempB.size() >  decompresseddedWordLength)
				{
					stringTempBSize = tempB.size();
					tempB1 = tempB.substr(stringTempBSize - decompresseddedWordLength, decompresseddedWordLength);
					tempB = tempB.substr(0, stringTempBSize - decompresseddedWordLength);

					temp = logicalEnd(tempB1, tempA) + temp;
					tempA = "";
					break;
				}else
				{
					break;
				}
			}
		}else if(i == divisions - 1)
		{
			temp = logicalEnd(tempA, tempB) + temp;
			tempA = "";
			tempB = "";
			break;
		}

	}
	//cout << "String T "<< temp<<endl;
	string strC = compressString(temp, wordLength);
	//cout <<"String Q "<< strC << endl;
	compressedString = strC;
	str = temp;

	int stringCSize = strC.size();
	int strCSize = stringCSize;
	int divisionsC = strCSize/wordLength;

	string tempC = "";



	for(int i = 0; i < stringCSize/wordLength; i++)
	{
		tempC =   decompressor(i, wordLength,  strC) + tempC;
	}

	//cout <<"string C " <<  tempC << endl;
	//cout << temp<< endl;
	result = tempC;
	//cout << "String G ";
	//return result;
}


bool bloomFilterContains (string& str, string& bitString)
{
	int hash1;
	int hash2;
	int hash3;

	int asciNum = asciiSum(str);
  //cout << asciNum;
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

int moding(int& num, string& str)
{
	int result = 0;

	result = num%str.size();
	return result;

}

int asciiSum(string str)
{
	int sum = 0;

	for(int i = 0; i < str.size(); i++)
	{
		sum += i*str.at(i)+powerFunction(i,2)*str.at(i)+str.at(i)*107;
	}

	return sum-310296;
}

string Decomp(string compressed,int wordlength)
{
	string decompressed = "";
	int numOfWords = compressed.size()/wordlength;
	int j = 0;

	string tempstring="";

	for (int i = 0; i < numOfWords; i++)
	{
		if (compressed[j+0] == '1')
		{
			for (int l = 0 ; l < wordlength-2 ; l ++)
      {
        tempstring += compressed[j+2+l];
      }

    	int decNumA = convertToDecimal(tempstring);
			for (int k =0 ;k < decNumA ;k++)
			{
				decompressed += compressed[j+1];
			}
		}else
		{
			for (int l = 0 ; l < wordlength-2 ; l ++)
      {
        tempstring += compressed[j+2+l];
      }
			decompressed+=tempstring;
		}
		j+=wordlength;
	}
}



void setBloomFilter(string fileName, string& str)
{
	ifstream input;
	input.open(fileName,ifstream::in);
	str = "";
	input >> str;

	input.close();
}
