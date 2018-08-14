#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	fstream input;
	input.open("input.txt");
	
	string temp;
	
	getline(input, temp);
	
	input.close();
}
