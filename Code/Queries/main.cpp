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
