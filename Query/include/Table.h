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


    bool temperatureConditions(double value);
    bool pressureConditions(double value);
    bool HumidityConditions(double value);


    void delimeterSeparator(string str, char delimeter, double& att1, double& att2, double& att3);
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
};

#endif // TABLE_H
