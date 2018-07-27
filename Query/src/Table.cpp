#include "Table.h"

Table::Table()
{
    _temperature = 0;
    _pressure = 0;
    _humidity = 0;
    _caseNum = 0;

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

void Table::run()
{
    input.open(_inputFileName);
    output.open("text1.txt");

    double temperature;
    double pressure;
    double humidity;


    while(input >> temperature  >> pressure  >> humidity)
    {

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

        if(_caseNum == 0)
        {
            output <<  temperature << "\t" << pressure << "\t" << humidity << endl;
            cout << temperature << "\t" << pressure << "\t" << humidity << endl;
        }else if(_caseNum >=1 && _caseNum <= 3)
        {
            output << _att1<< endl;
            cout << _att1 << endl;
        } else if(_caseNum >=4 && _caseNum <= 6)
        {
            output <<  _att1<< "\t" << _att2 << endl;
            cout << _att1<< "\t" << _att2 << endl;
        }

    }
    cout << "Case number: " << _caseNum << endl;
    output.close();
    input.close();

}
