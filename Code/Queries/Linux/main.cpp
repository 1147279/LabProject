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
    string textFileName = "text";
    Table tableObject;

    tableObject.from(textFileName);
    tableObject.select(WeatherAttributes::All);
    tableObject.select(WeatherAttributes::Humidity, WeatherAttributes::Pressure);
    tableObject.run();

    return 0;
}
