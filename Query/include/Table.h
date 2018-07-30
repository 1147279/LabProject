#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


enum class WeatherAttributes
{
    Temperature,
    Pressure,
    Humidity,
    All
};

enum class where
{
    lessThan,
    lessOrEqualTo,
    equalTo,
    greaterOrEqualTo,
    greaterThan,
    any
};


class Table
{
public:
    Table();
    ~Table();
    void from(string& fileName);
    void select(WeatherAttributes att);
    void select(WeatherAttributes att, WeatherAttributes att2);

    void getTemperatureConditions(where con, double value);
    void getPressureConditions(where con, double value);
    void getHumidityConditions(where con, double value);


    bool temperatureConditions();
    bool pressureConditions();
    bool humidityConditions();
    bool conditionsMet();

    void getDelimeter(char del) {_delimeter = del;}

    int numOfDelimters(string str, char delimeter);
    double stringToDouble(string str);
    double powerFunction(double multiplier, int power);
    void delimeterSeparation(string str, double *arr, char delimeter, int delimeterCounter);

    void run();

private:
    ifstream input;
    ofstream output;

    double _temperature;
    double _pressure;
    double _humidity;


    where _temperatureCondition;
    where _pressureCondition;
    where _humidityCondition;

    double _temperatureThreshold;
    double _pressureThreshold;
    double _humidityThreshold;

    string _inputFileName;

    int _caseNum;

    double _att1;
    double _att2;


    char _delimeter;
};

#endif // TABLE_H
