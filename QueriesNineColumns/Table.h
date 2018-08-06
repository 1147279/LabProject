#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum class Type
{
	All, Location, Year, Month, Day, Hour, Minute, Humidity, Pressure, Temperature
};

enum class where
{
	All,
    lessThan,
    lessOrEqualTo,
    equalTo,
    greaterOrEqualTo,
    greaterThan,
    Any
};

class Table
{
public:
	Table();
	void from(string text);
	////////////////////////////////////////////////////////////////////////////////																																																																																																																																								//////
	int numOfDelimters(string str, char delimeter);
	double stringToDouble(string str);
	double powerFunction(double multiplier, int power);
	void delimeterSeparation(string str, vector<string>& inputList, char delimeter, int delimeterCounter);
	
	////////////////////////////////////////////////////////////////////////////////
	//This is where one chooses columns
	void selection(Type attribute);
	void selection(Type attribute, Type attribute1);
	void selection(Type attribute, Type attribute1, Type attribute2);
	void selection(Type attribute, Type attribute1, Type attribute2, Type attribute3);
	void selection(Type attribute, Type attribute1, Type attribute2, Type attribute3, Type attribute4);
	void selection(Type attribute, Type attribute1, Type attribute2, Type attribute3, Type attribute4, Type attribute5);
	void selection(Type attribute, Type attribute1, Type attribute2, Type attribute3, Type attribute4, Type attribute5, Type attribute6);
	
	////////////////////////////////////////////////////////////////////////////////
	//Checks if attribute has been chosen
	bool isLocationChosen();
	bool isYearChosen();
	bool isMonthChosen();
	bool isDayChosen();
	bool isHourChosen();
	bool isMinuteChosen();
	bool isTemperatureChosen();
	bool isHumidityChosen();
	bool isPressureChosen();
	
	////////////////////////////////////////////////////////////////////////////////
	//get conditions
	void getLocationConditions(where con, string value);
	void getYearConditions(where con, double value);
	void getMonthConditions(where con, double value);
	void getDayConditions(where con, double value);
	void getHourConditions(where con, double value);
	void getMinuteConditions(where con, double value);
	void getTemperatureConditions(where con, double value);
	void getPressureConditions(where con, double value);
	void getHumidityConditions(where con, double value);

	////////////////////////////////////////////////////////////////////////////////
	//See if conditions met
	bool conditionsMet();
	bool isLocationConditionMet();
	bool isYearConditionMet();
	bool isMonthConditionMet();
	bool isDayConditionMet();
	bool isHourConditionMet();
	bool isMinuteConditionMet();
	bool isTemperatureConditionMet();
	bool isHumidityConditionMet();
	bool isPressureConditionMet();
	////////////////////////////////////////////////////////////////////////////////
	
	
	void run();
private:
	ifstream input;
	ofstream output;
	string _fileName;
	
	vector<string> _inputList;
	int _delimeterCounter;
	char _delimeter;
	
	// Checking if chosen or not
	bool _locationChosen;
	bool _yearChosen;
	bool _monthChosen;
	bool _dayChosen;
	bool _hourChosen;
	bool _minuteChosen;
	bool _temperatureChosen;
	bool _humidityChosen;
	bool _pressureChosen;
	
	//Values of attributes
	string _location;
	double _year;
	double _month;
	double _day;
	double _hour;
	double _minute;
	double _temperature;
	double _humidity;
	double _pressure;
	
	//Attribute threshold
	string _locationThreshold;
	double _yearThreshold;
	double _monthThreshold;
	double _dayThreshold;
	double _hourThreshold;
	double _minuteThreshold;
	double _temperatureThreshold;
	double _humidityThreshold;
	double _pressureThreshold;
	
	
	
	//Values of Conditions (using where enum class)
	where _locationCondition;
	where _yearConditions;
	where _monthConditions;
	where _dayConditions;
	where _hourConditions;
	where _minuteConditions;
	where _temperatureConditions;
	where _humidityConditions;
	where _pressureConditions;
	
};

#endif
