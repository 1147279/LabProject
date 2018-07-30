#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Table.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string textFileName = "textA";
    Table tableObject;

    tableObject.from(textFileName);
    tableObject.select(WeatherAttributes::All);
    //tableObject.select(WeatherAttributes::Humidity, WeatherAttributes::Pressure);
    tableObject.getTemperatureConditions(where::lessOrEqualTo  ,12);
    tableObject.getPressureConditions(where::greaterOrEqualTo, 15);
    tableObject.getHumidityConditions(where::greaterOrEqualTo, 10);
    tableObject.run();

    return 0;
}



int numOfDelimters(string str, char delimeter)
{
	int counter = 0;
	
	for(int i = 0; i < str.size(); i++)
	{
		if(str.at(i) == delimeter)
			counter++;
	}
	return counter;
}


double stringToDouble(string str)
{
	bool fraction = false;
	double multiplier = 10;
	double result = 0;
	int counter = 0;
	double temp;
	for(int i = 0; i < str.size(); i++)
	{
		if(i == 0)
			result = str.at(i) - '0';
		else if(str.at(i) != '.' && fraction == false)
		{
			result = result*multiplier + str.at(i) - '0';
		}else if(str.at(i) == '.')
		{
			fraction = true;
			multiplier = 1/10.0;
		}else if(fraction == true)
		{
			counter++;
			temp = str.at(i) - '0';
			result = result + (temp)*powerFunction(multiplier, counter);
		}
		
	}
	
	return result;
}


double powerFunction(double multiplier, int power)
{
	if(power == 0)
		return 1;
	else if (power == 1)
		return multiplier;
	else if(power > 1)
	{
		for(int i = 0; i < power - 1; i++)
			multiplier = multiplier/10;
	}
	return multiplier;
}



void delimeterSeparation(string str, double *arr, char delimeter, int delimeterCounter)
{
	int numOfRegions = delimeterCounter + 1;
	int boundIndex[numOfRegions];
	int lowerBound = 0;
	int upperBound;
	int counter = 0;
	string temp = "";
	
	for(int i = 0; i < str.size(); i++)
	{
		if(str.at(i) == delimeter)
		{
			boundIndex[counter] = i;
			cout << boundIndex[counter] << " ";
			counter++;
		}
	}
	
	boundIndex[delimeterCounter] = str.size();
	
	upperBound = boundIndex[0];
	
	counter = 0;
	
	for(int i = 0; i < numOfRegions; i++)
	{
		for(int j = lowerBound; j < upperBound; j++)
		{
			temp += str.at(j);
		}
		arr[counter] = stringToDouble(temp);
		temp = "";
		lowerBound = upperBound + 1;
		//if(counter < numOfRegions)
		counter++;
		upperBound = boundIndex[counter];
		
	}
	
	
	
	
	
	
}




