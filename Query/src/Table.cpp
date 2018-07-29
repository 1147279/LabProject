#include "Table.h"

Table::Table()
{
    _temperature = 0;
    _pressure = 0;
    _humidity = 0;
    _caseNum = 0;


    _temperatureCondition = where::any;
    _pressureCondition = where::any;
    _humidityCondition = where::any;

}

Table::~Table()
{
    //ctor
}

void Table::from(string& fileName)
{
    _inputFileName = fileName + ".txt";
}


void Table::select(WeatherAttributes att)
{
    if(att == WeatherAttributes::All)
    {
        _caseNum = 0;
    }else if(att == WeatherAttributes::Temperature)
    {
        _caseNum = 1;
    }else if(att == WeatherAttributes::Pressure)
    {
        _caseNum = 2;
    }else if(att == WeatherAttributes::Humidity)
    {
        _caseNum = 3;
    }
}


void Table::select(WeatherAttributes att, WeatherAttributes att2)
{
    if(att == WeatherAttributes::Temperature && att2 == WeatherAttributes::Pressure)
    {
        _caseNum = 4;
    }else if(att == WeatherAttributes::Temperature && att2 == WeatherAttributes::Humidity)
    {
        _caseNum = 5;
    } else if(att == WeatherAttributes::Pressure && att2 == WeatherAttributes::Humidity)
    {
        _caseNum = 6;
    }else if(att == WeatherAttributes::Pressure && att2 == WeatherAttributes::Temperature)
    {
        _caseNum = 4;
    }else if(att == WeatherAttributes::Humidity && att2 == WeatherAttributes::Temperature)
    {
        _caseNum = 5;
    } else if(att == WeatherAttributes::Humidity && att2 == WeatherAttributes::Pressure)
    {
        _caseNum = 6;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////
void Table::getTemperatureConditions(where con, double value)
{
    _temperatureCondition = con;
    _temperatureThreshold = value;
}


void Table::getPressureConditions(where con, double value)
{
    _pressureCondition = con;
    _pressureThreshold = value;
}

void Table::getHumidityConditions(where con, double value)
{
    _humidityCondition = con;
    _humidityThreshold = value;
}
/////////////////////////////////////////////////////////////////////////////////////////////



bool Table::temperatureConditions()
{
    if(_temperatureCondition == where::any)
    {
        return true;
    }else if(_temperatureCondition == where::lessThan)
    {
        if(_temperature < _temperatureThreshold)
            return true;
    }else if(_temperatureCondition == where::lessOrEqualTo)
    {
        if(_temperature <= _temperatureThreshold)
            return true;
    }else if(_temperatureCondition == where::equalTo)
    {
        if(_temperature == _temperatureThreshold)
            return true;
    }else if(_temperatureCondition == where::greaterOrEqualTo)
    {
         if(_temperature >= _temperatureThreshold)
            return true;
    }else if(_temperatureCondition == where::greaterThan)
    {
        if(_temperature > _temperatureThreshold)
            return true;
    }

    return false;
}

bool Table::pressureConditions()
{
    if(_pressureCondition == where::any)
    {
        return true;
    }else if(_pressureCondition == where::lessThan)
    {
        if(_pressure < _pressureThreshold)
            return true;
    }else if(_pressureCondition == where::lessOrEqualTo)
    {
        if(_pressure <= _pressureThreshold)
            return true;
    }else if(_pressureCondition == where::equalTo)
    {
        if(_pressure == _pressureThreshold)
            return true;
    }else if(_pressureCondition == where::greaterOrEqualTo)
    {
         if(_pressure >= _pressureThreshold)
            return true;
    }else if(_pressureCondition == where::greaterThan)
    {
        if(_pressure > _pressureThreshold)
            return true;
    }

    return false;
}


bool Table::humidityConditions()
{
    if(_humidityCondition == where::any)
    {
        return true;
    }else if(_humidityCondition == where::lessThan)
    {
        if(_humidity < _humidityThreshold)
            return true;
    }else if(_humidityCondition == where::lessOrEqualTo)
    {
        if(_humidity <= _humidityThreshold)
            return true;
    }else if(_humidityCondition == where::equalTo)
    {
        if(_humidity == _humidityThreshold)
            return true;
    }else if(_humidityCondition == where::greaterOrEqualTo)
    {
         if(_humidity >= _humidityThreshold)
            return true;
    }else if(_humidityCondition == where::greaterThan)
    {
        if(_humidity > _humidityThreshold)
            return true;
    }

    return false;
}



bool Table::conditionsMet()
{
    if(temperatureConditions() == false)
        return false;
    if(pressureConditions() == false)
        return false;
    if (humidityConditions() == false)
        return false;

    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////

void Table::delimeterSeparator(string str, char delimeter, double& att1, double& att2, double& att3)
{
    string temp = "";
    int delimeterCounter = 0;

    for(int i = 0; i < str.size(); i++)
    {
        if(str.at(i) != delimeter)
        {
            temp += str.at(i);
        }else if(str.at(i) == delimeter)
        {
            if(delimeterCounter == 0)
            {
                att1 = stod(temp);
                delimeterCounter++;
                temp = "";
            }else if(delimeterCounter == 1)
            {
                att2 = stod(temp);
                delimeterCounter++;
                temp = "";
            }
        }else if(delimeterCounter == 2 && i == str.size() - 1)
        {
            att3 = stod(temp);
        }
    }
}

void Table::run()
{
    input.open(_inputFileName);
    output.open("text1.txt");

    double temperature;
    double pressure;
    double humidity;


    while(input >> temperature  >> pressure  >> humidity)
    {


        _temperature  = temperature;
        _pressure =  pressure;
        _humidity =  humidity;

        if(_caseNum == 1)
        {
            _att1 = temperature;
        }else if(_caseNum == 2)
        {
            _att1 = pressure;
        }else if(_caseNum == 3)
        {
            _att1 = humidity;
        }else if(_caseNum == 4)
        {
            _att1 = temperature;
            _att2 = pressure;

        }else if(_caseNum == 5)
        {
            _att1 = temperature;
            _att2 = humidity;

        }else if(_caseNum == 6)
        {
            _att1 = pressure;
            _att2 = humidity;
        }

        if(_caseNum == 0 )
        {
            if(conditionsMet() == true)
            {
                output <<  temperature << "\t" << pressure << "\t" << humidity << endl;
                cout << temperature << "\t" << pressure << "\t" << humidity << endl;
            }

        }else if(_caseNum >=1 && _caseNum <= 3)
        {
            if(conditionsMet() == true)
            {
                output << _att1<< endl;
                cout << _att1 << endl;
            }

        } else if(_caseNum >=4 && _caseNum <= 6)
        {
            if(conditionsMet() == true)
            {
                output <<  _att1<< "\t" << _att2 << endl;
                cout << _att1<< "\t" << _att2 << endl;
            }

        }

    }
    cout << "Case number: " << _caseNum << endl;
    output.close();
    input.close();

}
