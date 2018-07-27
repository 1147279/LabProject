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
    void conditions(WeatherAttributes att, where con, WeatherAttributes att2);
    void run();

private:
    ifstream input;
    ofstream output;

    double _temperature;
    double _pressure;
    double _humidity;

    string _inputFileName;

    int _caseNum;

    double _att1;
    double _att2;
};

#endif // TABLE_H
