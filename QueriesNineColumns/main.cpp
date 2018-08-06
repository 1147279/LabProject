#include <iostream>
#include "Table.h"

using namespace std;

int main()
{
	Table t1;
	t1.from("textA");
	t1.selection(Type::Year, Type::Location, Type::Hour, Type::Day);
	t1.getYearConditions(where::lessThan, 25);
	t1.run();
	return 0;
}


/*
enum class Type
{
	All, Location, Year, Month, Day, Hour, Minute, Humidity, Pressure, Temperature
};

enum class where
{
    lessThan,
    lessOrEqualTo,
    equalTo,
    greaterOrEqualTo,
    greaterThan,
    All
};
*/
