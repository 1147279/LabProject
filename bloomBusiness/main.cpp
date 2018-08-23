#include <iostream>
#include <fstream>

using namespace std;

int asciiSum(string str);
int powerFunction(int base, int power);
int moding(int& num, string& str);
void bloomFilterInsert (string& str, string& bitString);
bool bloomFilterContains (string& str, string& bitString);
void exportToFile(string fileName, string& str);

int main()
{
	int num = 604;
	string str = "Darren";
	cout << moding(num, str)<< endl;
}

int asciiSum(string str)
{
	int sum = 0;
	
	for(int i = 0; i < str.size(); i++)
	{
		sum += str.at(i);
	}
	
	return sum;
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


int moding(int& num, string& str)
{
	int result = 0;
	
	result = num%str.size();
	return resut;
	
}


void bloomFilterInsert (string& str, string& bitString)
{
	int hash1;
	int hash2;
	int hash3;
	int asciNum = asciiSum(str);
	int num1 = powerFunction(asciNum, 2);
	int num2 = powerFunction(asciNum, 3);
	int num3 = powerFunction(asciNum, 4);
	
	hash1 = moding(num1, str);
	hash2 = moding(num1, str);
	hash3 = moding(num1, str);
	
	bitString.at(0) = '1';
	bitString.at(1) = '1';
	bitString.at(2) = '1';
}

bool bloomFilterContains (string& str, string& bitString)
{
	int hash1;
	int hash2;
	int hash3;
	int asciNum = asciiSum(str);
	int num1 = powerFunction(asciNum, 2);
	int num2 = powerFunction(asciNum, 3);
	int num3 = powerFunction(asciNum, 4);
	
	hash1 = moding(num1, str);
	hash2 = moding(num1, str);
	hash3 = moding(num1, str);
	
	if(bitString.at(0) == '0';)
		return false;
	
	if(bitString.at(1) == '0';)
		return false;
	
	if(bitString.at(2) == '0';)
		return false;
	
	
	return true;
}


void exportToFile(string fileName, string& str)
{
	ofstream output;
	output.open(fileName,ofstream::out);
	
	output << str << endl;
	
	output.close();
}


void setBloomFilter(string fileName, string& str)
{
	ofstream input;
	input.open(fileName);
	str = "";
	input >> str;
	
	input.close();
}

