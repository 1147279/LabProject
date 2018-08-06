#include "Table.h"

Table::Table()
{
	_delimeter = ',';
	
	 _locationChosen = false;
	 _yearChosen = false;
	 _monthChosen = false;
	 _dayChosen = false;
	 _hourChosen = false;
	 _minuteChosen = false;
	 _temperatureChosen = false;
	 _humidityChosen = false;
	 _pressureChosen = false;
	 

	_locationCondition = where::Any;
	_yearConditions = where::Any;
	_monthConditions = where::Any;
	_dayConditions = where::Any;
	_hourConditions = where::Any;
	_minuteConditions = where::Any;
	_temperatureConditions = where::Any;
	_humidityConditions = where::Any;
	_pressureConditions = where::Any;
	 
}



void Table::from(string fileName)
{
	_fileName = fileName + ".txt";
	
}



/////////////////////////////////////////////////////////////////////////////



int Table::numOfDelimters(string str, char delimeter)
{
	int counter = 0;
	
	for(int i = 0; i < str.size(); i++)
	{
		if(str.at(i) == delimeter)
			counter++;
	}
	return counter;
}


double Table::stringToDouble(string str)
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


double Table::powerFunction(double multiplier, int power)
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



void Table::delimeterSeparation(string str, vector<string>& inputList, char delimeter, int delimeterCounter)
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
		//arr[counter] = stringToDouble(temp);
		
		inputList.push_back(temp);
		temp = "";
		lowerBound = upperBound + 1;
		//if(counter < numOfRegions)
		counter++;
		upperBound = boundIndex[counter];
		
	}
}


////////////////////////////////////////////////////////////////////////////////
//Checks if attribute has been chosen
bool Table::isLocationChosen()
{
	if(_locationChosen == true)
		return true;
	else
		return false;
}

bool Table::isYearChosen()
{
	if(_yearChosen == true)
		return true;
	else
		return false;
}

bool Table::isMonthChosen()
{
	if(_monthChosen == true)
		return true;
	else
		return false;
}
bool Table::isDayChosen()
{
	if(_dayChosen == true)
		return true;
	else
		return false;
}
bool Table::isHourChosen()
{
	if(_hourChosen == true)
		return true;
	else
		return false;
}

bool Table::isMinuteChosen()
{
	if(_minuteChosen == true)
		return true;
	else
		return false;
}

bool Table::isTemperatureChosen()
{
	if(_temperatureChosen == true)
		return true;
	else
		return false;
}

bool Table::isHumidityChosen()
{
	if(_humidityChosen == true)
		return true;
	else
		return false;
}

bool Table::isPressureChosen()
{
	if(_pressureChosen == true)
		return true;
	else
		return false;
}

////////////////////////////////////////////////////////////////////////////////
//This is where one chooses columns
void Table::selection(Type attribute)
{
	if(attribute == Type::All)
	{
		_locationChosen = true;
		_yearChosen = true;
		_monthChosen = true;
		_dayChosen = true;
		_hourChosen = true;
		_minuteChosen = true;
		_temperatureChosen = true;
		_humidityChosen = true;
		_pressureChosen = true;	
		
	}else if(attribute == Type::Location)
	{
		_locationChosen = true;
	}else if(attribute == Type::Year)
	{
		_yearChosen = true;
	}else if(attribute == Type::Month)
	{
		_monthChosen = true;
	}else if(attribute == Type::Day)
	{
		_dayChosen = true;
	}else if(attribute == Type::Hour)
	{
		_hourChosen = true;
	}else if(attribute == Type::Minute)
	{
		_minuteChosen = true;
	}else if(attribute == Type::Temperature)
	{
		_temperatureChosen = true;
	}else if(attribute == Type::Humidity)
	{
		_humidityChosen = true;
	}else if(attribute == Type::Pressure)
	{
		_pressureChosen = true;
	}
}


void Table::selection(Type attribute, Type attribute1)
{
	int numOfParameters = 2;
	Type Arr[numOfParameters];
	Arr[0] = attribute;
	Arr[1] = attribute1;
	
	for(int i = 0; i < numOfParameters; i++)
	{
		if(Arr[i] == Type::Location)
		{
			_locationChosen = true;
		}else if(Arr[i] == Type::Year)
		{
			_yearChosen = true;
		}else if(Arr[i] == Type::Month)
		{
			_monthChosen = true;
		}else if(Arr[i] == Type::Day)
		{
			_dayChosen = true;
		}else if(Arr[i] == Type::Hour)
		{
			_hourChosen = true;
		}else if(Arr[i] == Type::Minute)
		{
			_minuteChosen = true;
		}else if(Arr[i] == Type::Temperature)
		{
			_temperatureChosen = true;
		}else if(Arr[i] == Type::Humidity)
		{
			_humidityChosen = true;
		}else if(Arr[i] == Type::Pressure)
		{
			_pressureChosen = true;
		}
	}
	
}

void Table::selection(Type attribute, Type attribute1, Type attribute2)
{
	int numOfParameters = 3;
	Type Arr[numOfParameters];
	Arr[0] = attribute;
	Arr[1] = attribute1;
	Arr[2] = attribute2;
	for(int i = 0; i < numOfParameters; i++)
	{
		if(Arr[i] == Type::Location)
		{
			_locationChosen = true;
		}else if(Arr[i] == Type::Year)
		{
			_yearChosen = true;
		}else if(Arr[i] == Type::Month)
		{
			_monthChosen = true;
		}else if(Arr[i] == Type::Day)
		{
			_dayChosen = true;
		}else if(Arr[i] == Type::Hour)
		{
			_hourChosen = true;
		}else if(Arr[i] == Type::Minute)
		{
			_minuteChosen = true;
		}else if(Arr[i] == Type::Temperature)
		{
			_temperatureChosen = true;
		}else if(Arr[i] == Type::Humidity)
		{
			_humidityChosen = true;
		}else if(Arr[i] == Type::Pressure)
		{
			_pressureChosen = true;
		}
	}
}

void Table::selection(Type attribute, Type attribute1, Type attribute2, Type attribute3)
{
	int numOfParameters = 4;
	Type Arr[numOfParameters];
	Arr[0] = attribute;
	Arr[1] = attribute1;
	Arr[2] = attribute2;
	Arr[3] = attribute3;
	for(int i = 0; i < numOfParameters; i++)
	{
		if(Arr[i] == Type::Location)
		{
			_locationChosen = true;
		}else if(Arr[i] == Type::Year)
		{
			_yearChosen = true;
		}else if(Arr[i] == Type::Month)
		{
			_monthChosen = true;
		}else if(Arr[i] == Type::Day)
		{
			_dayChosen = true;
		}else if(Arr[i] == Type::Hour)
		{
			_hourChosen = true;
		}else if(Arr[i] == Type::Minute)
		{
			_minuteChosen = true;
		}else if(Arr[i] == Type::Temperature)
		{
			_temperatureChosen = true;
		}else if(Arr[i] == Type::Humidity)
		{
			_humidityChosen = true;
		}else if(Arr[i] == Type::Pressure)
		{
			_pressureChosen = true;
		}
	}
}

void Table::selection(Type attribute, Type attribute1, Type attribute2, Type attribute3, Type attribute4)
{
	int numOfParameters = 5;
	Type Arr[numOfParameters];
	Arr[0] = attribute;
	Arr[1] = attribute1;
	Arr[2] = attribute2;
	Arr[3] = attribute3;
	Arr[4] = attribute4;
	for(int i = 0; i < numOfParameters; i++)
	{
		if(Arr[i] == Type::Location)
		{
			_locationChosen = true;
		}else if(Arr[i] == Type::Year)
		{
			_yearChosen = true;
		}else if(Arr[i] == Type::Month)
		{
			_monthChosen = true;
		}else if(Arr[i] == Type::Day)
		{
			_dayChosen = true;
		}else if(Arr[i] == Type::Hour)
		{
			_hourChosen = true;
		}else if(Arr[i] == Type::Minute)
		{
			_minuteChosen = true;
		}else if(Arr[i] == Type::Temperature)
		{
			_temperatureChosen = true;
		}else if(Arr[i] == Type::Humidity)
		{
			_humidityChosen = true;
		}else if(Arr[i] == Type::Pressure)
		{
			_pressureChosen = true;
		}
	}
}

void Table::selection(Type attribute, Type attribute1, Type attribute2, Type attribute3, Type attribute4, Type attribute5)
{
	int numOfParameters = 6;
	Type Arr[numOfParameters];
	Arr[0] = attribute;
	Arr[1] = attribute1;
	Arr[2] = attribute2;
	Arr[3] = attribute3;
	Arr[4] = attribute4;
	Arr[5] = attribute5;
	for(int i = 0; i < numOfParameters; i++)
	{
		if(Arr[i] == Type::Location)
		{
			_locationChosen = true;
		}else if(Arr[i] == Type::Year)
		{
			_yearChosen = true;
		}else if(Arr[i] == Type::Month)
		{
			_monthChosen = true;
		}else if(Arr[i] == Type::Day)
		{
			_dayChosen = true;
		}else if(Arr[i] == Type::Hour)
		{
			_hourChosen = true;
		}else if(Arr[i] == Type::Minute)
		{
			_minuteChosen = true;
		}else if(Arr[i] == Type::Temperature)
		{
			_temperatureChosen = true;
		}else if(Arr[i] == Type::Humidity)
		{
			_humidityChosen = true;
		}else if(Arr[i] == Type::Pressure)////////////////////////////////////////////////////////////////////////////////
		{
			_pressureChosen = true;
		}
	}
}

void Table::selection(Type attribute, Type attribute1, Type attribute2, Type attribute3, Type attribute4, Type attribute5, Type attribute6)
{
	int numOfParameters = 7;
	Type Arr[numOfParameters];
	Arr[0] = attribute;
	Arr[1] = attribute1;
	Arr[2] = attribute2;
	Arr[3] = attribute3;
	Arr[4] = attribute4;
	Arr[5] = attribute5;
	Arr[6] = attribute6;
	for(int i = 0; i < numOfParameters; i++)
	{
		if(Arr[i] == Type::Location)
		{
			_locationChosen = true;
		}else if(Arr[i] == Type::Year)
		{
			_yearChosen = true;
		}else if(Arr[i] == Type::Month)
		{
			_monthChosen = true;
		}else if(Arr[i] == Type::Day)
		{
			_dayChosen = true;
		}else if(Arr[i] == Type::Hour)
		{
			_hourChosen = true;
		}else if(Arr[i] == Type::Minute)
		{
			_minuteChosen = true;
		}else if(Arr[i] == Type::Temperature)
		{
			_temperatureChosen = true;
		}else if(Arr[i] == Type::Humidity)
		{
			_humidityChosen = true;
		}else if(Arr[i] == Type::Pressure)
		{
			_pressureChosen = true;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
//get conditions
void Table::getLocationConditions(where con, string value)
{
	_locationThreshold = value;
	_locationCondition = con;
}


void Table::getYearConditions(where con, double value)
{
	_yearThreshold = value;
	_yearConditions = con;
}


void Table::getMonthConditions(where con, double value)
{
	_monthThreshold = value;
	_monthConditions = con;
}
void Table::getDayConditions(where con, double value)
{
	_dayThreshold = value;
	_dayConditions = con;
}


void Table::getHourConditions(where con, double value)
{
	_hourThreshold = value;
	_hourConditions = con;
}


void Table::getMinuteConditions(where con, double value)
{
	_minuteThreshold = value;
	_minuteConditions = con;
	
}
void Table::getTemperatureConditions(where con, double value)
{
	_temperatureThreshold = value;
	_temperatureConditions = con;
}

void Table::getPressureConditions(where con, double value)
{
	_pressureThreshold = value;
	_pressureConditions = con;
}
void Table::getHumidityConditions(where con, double value)
{
	_humidityThreshold = value;
	_humidityConditions = con;
}


////////////////////////////////////////////////////////////////////////////////
//See if conditions met
bool Table::isLocationConditionMet()
{
	if(_locationCondition == where::Any)
		return true;
	else if(_locationThreshold == _location)
		return true;
	
	return false;
}

bool Table::isYearConditionMet()
{
	if(_yearConditions == where::Any)
		return true;
	else if(_yearConditions == where::lessThan)
	{
		if(_year < _yearThreshold)
			return true;
		else
			return false;
	}else if(_yearConditions == where::lessOrEqualTo)
	{
		if(_year <= _yearThreshold)
			return true;
		else
			return false;
	}else if(_yearConditions == where::equalTo)
	{
		if(_year == _yearThreshold)
			return true;
		else
			return false;
	}else if(_yearConditions == where::greaterOrEqualTo)
	{
		if(_year >= _yearThreshold)
			return true;
		else
			return false;
	}else if(_yearConditions == where::greaterThan)
	{
		if(_year > _yearThreshold)
			return true;
		else
			return false;
	}
}

bool Table::isMonthConditionMet()
{
	if(_monthConditions == where::Any)
		return true;
	else if(_monthConditions == where::lessThan)
	{
		if(_month < _monthThreshold)
			return true;
		else
			return false;
	}else if(_monthConditions == where::lessOrEqualTo)
	{
		if(_month <= _monthThreshold)
			return true;
		else
			return false;
	}else if(_monthConditions == where::equalTo)
	{
		if(_month == _monthThreshold)
			return true;
		else
			return false;
	}else if(_monthConditions == where::greaterOrEqualTo)
	{
		if(_month >= _monthThreshold)
			return true;
		else
			return false;
	}else if(_monthConditions == where::greaterThan)
	{
		if(_month > _monthThreshold)
			return true;
		else
			return false;
	}
}

bool Table::isDayConditionMet()
{
	if(_dayConditions == where::Any)
		return true;
	else if(_dayConditions == where::lessThan)
	{
		if(_day < _dayThreshold)
			return true;
		else
			return false;
	}else if(_dayConditions == where::lessOrEqualTo)
	{
		if(_day <= _dayThreshold)
			return true;
		else
			return false;
	}else if(_dayConditions == where::equalTo)
	{
		if(_day == _dayThreshold)
			return true;
		else
			return false;
	}else if(_dayConditions == where::greaterOrEqualTo)
	{
		if(_day >= _dayThreshold)
			return true;
		else
			return false;
	}else if(_dayConditions == where::greaterThan)
	{
		if(_day > _dayThreshold)
			return true;
		else
			return false;
	}
}

bool Table::isHourConditionMet()
{
	if(_hourConditions == where::Any)
		return true;
	else if(_hourConditions == where::lessThan)
	{
		if(_hour < _hourThreshold)
			return true;
		else
			return false;
	}else if(_hourConditions == where::lessOrEqualTo)
	{
		if(_hour <= _hourThreshold)
			return true;
		else
			return false;
	}else if(_hourConditions == where::equalTo)
	{
		if(_hour == _hourThreshold)
			return true;
		else
			return false;
	}else if(_hourConditions == where::greaterOrEqualTo)
	{
		if(_hour >= _hourThreshold)
			return true;
		else
			return false;
	}else if(_hourConditions == where::greaterThan)
	{
		if(_hour > _hourThreshold)
			return true;
		else
			return false;
	}
}

bool Table::isMinuteConditionMet()
{
	if(_minuteConditions == where::Any)
		return true;
	else if(_minuteConditions == where::lessThan)
	{
		if(_minute < _minuteThreshold)
			return true;
		else
			return false;
	}else if(_minuteConditions == where::lessOrEqualTo)
	{
		if(_minute <= _minuteThreshold)
			return true;
		else
			return false;
	}else if(_minuteConditions == where::equalTo)
	{
		if(_minute == _minuteThreshold)
			return true;
		else
			return false;
	}else if(_minuteConditions == where::greaterOrEqualTo)
	{
		if(_minute >= _minuteThreshold)
			return true;
		else
			return false;
	}else if(_minuteConditions == where::greaterThan)
	{
		if(_minute > _minuteThreshold)
			return true;
		else
			return false;
	}
}

bool Table::isTemperatureConditionMet()
{
	if(_temperatureConditions == where::Any)
		return true;
	else if(_temperatureConditions == where::lessThan)
	{
		if(_temperature < _temperatureThreshold)
			return true;
		else
			return false;
	}else if(_temperatureConditions == where::lessOrEqualTo)
	{
		if(_temperature <= _temperatureThreshold)
			return true;
		else
			return false;
	}else if(_temperatureConditions == where::equalTo)
	{
		if(_temperature == _temperatureThreshold)
			return true;
		else
			return false;
	}else if(_temperatureConditions == where::greaterOrEqualTo)
	{
		if(_temperature >= _temperatureThreshold)
			return true;
		else
			return false;
	}else if(_temperatureConditions == where::greaterThan)
	{
		if(_temperature > _temperatureThreshold)
			return true;
		else
			return false;
	}
}

bool Table::isHumidityConditionMet()
{
	if(_humidityConditions == where::Any)
		return true;
	else if(_humidityConditions == where::lessThan)
	{
		if(_humidity < _humidityThreshold)
			return true;
		else
			return false;
	}else if(_humidityConditions == where::lessOrEqualTo)
	{
		if(_humidity <= _humidityThreshold)
			return true;
		else
			return false;
	}else if(_humidityConditions == where::equalTo)
	{
		if(_humidity == _humidityThreshold)
			return true;
		else
			return false;
	}else if(_humidityConditions == where::greaterOrEqualTo)
	{
		if(_humidity >= _humidityThreshold)
			return true;
		else
			return false;
	}else if(_humidityConditions == where::greaterThan)
	{
		if(_humidity > _humidityThreshold)
			return true;
		else
			return false;
	}
}

bool Table::isPressureConditionMet()
{
	if(_pressureConditions == where::Any)
		return true;
	else if(_pressureConditions == where::lessThan)
	{
		if(_pressure < _pressureThreshold)
			return true;
		else
			return false;
	}else if(_pressureConditions == where::lessOrEqualTo)
	{
		if(_pressure <= _pressureThreshold)
			return true;
		else
			return false;
	}else if(_pressureConditions == where::equalTo)
	{
		if(_pressure == _pressureThreshold)
			return true;
		else
			return false;
	}else if(_pressureConditions == where::greaterOrEqualTo)
	{
		if(_pressure >= _pressureThreshold)
			return true;
		else
			return false;
	}else if(_pressureConditions == where::greaterThan)
	{
		if(_pressure > _pressureThreshold)
			return true;
		else
			return false;
	}
}


bool Table::conditionsMet()
{
	if(isLocationConditionMet() == false)
		return false;
	
	if(isYearConditionMet() == false)
		return false;
	
	if(isMonthConditionMet() == false)
		return false;
	
	
	
	if(isDayConditionMet() == false)
		return false;
	
	if(isHourConditionMet()	 == false)
		return false;
	if(isMinuteConditionMet() == false)
		return false;
	if(isTemperatureConditionMet() == false)
		return false;
	if(isHumidityConditionMet() == false)
		return false;
	if(isPressureConditionMet() == false)
		return false;
	
	
	
	return true;
}
////////////////////////////////////////////////////////////////////////////////

void Table::run()
{
	input.open(_fileName);
	string str = "";
	while(input >> str)
	{
		_delimeterCounter = numOfDelimters(str, _delimeter);
		delimeterSeparation(str, _inputList, _delimeter, _delimeterCounter);
		
		/*
		for(int i = 0; i < _inputList.size(); i++)
			cout << _inputList.at(i) << "\t";
		cout << endl;
		*/


		_location = (_inputList.at(0));
		_year = stringToDouble(_inputList.at(1));
		_month = stringToDouble(_inputList.at(2));
		_day = stringToDouble(_inputList.at(3));
		_hour = stringToDouble(_inputList.at(4));
		_minute = stringToDouble(_inputList.at(5));
		_temperature = stringToDouble(_inputList.at(6));
		_humidity = stringToDouble(_inputList.at(7));
		_pressure = stringToDouble(_inputList.at(8));
		
		
		if(conditionsMet() == true)
		{
			for(int i = 0; i < _inputList.size(); i++)
			{
				if(i == 0) // case 0 = Location 
				{
					if(isLocationChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}else if(i == 1) // case 1 = Year
				{
					if(isYearChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}else if(i == 2) // case 2 = month
				{
					if(isMonthChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}else if(i == 3)// case 3 = day
				{
					if(isDayChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}else if(i == 4 )// case 4 = hour
				{
					if(isHourChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}else if(i == 5)// case 5 = minute
				{
					if(isMinuteChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}else if ( i == 6)// case 6 = temperature
				{
					if(isTemperatureChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}else if(i == 7)// case 7 = humidity
				{
					if(isHumidityChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}else if(i == 8)// case 8 = pressure
				{
					if(isPressureChosen() == true)
					{
						cout << _inputList.at(i) << "\t";
					}
				}
			}
		}
		cout <<endl;
		_inputList.clear();
	}
	
	input.close();
}
