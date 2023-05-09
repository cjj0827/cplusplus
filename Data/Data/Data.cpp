#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
bool operator==(const Data& d1, const Data& d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}
void Data::Init(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
ostream& operator<<(ostream& out, const Data& d)
{
	out << d._year << "Äê" << d._month << "ÔÂ" << d._day << "ÈÕ" << endl;
	return out;
}



istream& operator>>(istream& in, Data& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

