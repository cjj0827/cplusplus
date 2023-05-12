#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
class Time
{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		,_second(second)
	{}

	
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;//Time 类的成员
};


class A
{
private:
	int k;
	static int b;
public:
	class B//B天生就是A的友元
	{
	public:
		void printA(const A& a)
		{
			cout << b << endl;//直接访问静态成员变量
			cout << a.k << endl;
		}
	};
};

int A::b = 1;

class C
{
public:
	int func(int a)
	{
		return a;
	}
};


int main()
{
	C().func(1);//匿名对象   这个是有默认构造函数
	//若是没有则要传参 
	//匿名对象即用即销毁
	const C& ra = C();//匿名对象具有常性 

	return 0;
}