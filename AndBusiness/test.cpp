#include <iostream>

using namespace std;

string decimalToBinary(int num, int bitStreamLength);

int main()
{
	string str = "";
	int num = 11;
	
	cout <<  decimalToBinary(num, 5)<< endl;
	
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
		temp /= 2;
	}
	
	for(int i = result.size(); i < bitStreamLength; i++)
	{
		result = '0' + result;
	}
	
	return result;
}
