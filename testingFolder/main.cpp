#include <iostream>

using namespace std;

string decimalToBinary(int num, int bitStreamLength);

int main()
{
	cout << decimalToBinary(3, 5)<<endl;

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
		cout << temp << endl;
	}
	
	
	for(int i = result.size(); i < bitStreamLength; i++)
	{
		result = '0' + result;
	}
	
	return result;
}

