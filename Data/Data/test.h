#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//	//析构
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
class Data
{
	friend bool operator==(const Data& d1, const Data& d2);
	friend ostream& operator<<(ostream& out, const Data& d);
	friend istream& operator>>(istream& in, Data& d);
public:
	//无参构造 
	//Data()
	//{}
	Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()const//修饰的是*this
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void Init(int year, int month, int day);
	
	//若是传值就会引发无穷递归  一直进行拷贝构造
	//在类中若是没有涉及资源分配时 写不写都可以 
	//若是有资源分配未写  1.会析构两次 后写先析构   2.一个改变 另一个也发生改变（指向同一个地址）
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符必须是成员函数 如果不显示实现 编译器会生成一个默认的 会和全局的重载 发生冲突
	Data operator=(const Data& d)//在这里有this指针
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//返回的是*this  this出了就销毁
	}
	//前置++
	Data& operator++()
	{
		_day += 1;
		return *this;
	}
	//后置++
	Data operator++(int)
	{
		Data temp(*this);
		_day += 1;
		return temp;//temp会被销毁所以 只能以值的形式返回
	}
	//获取每个月的天数
	int GetmonthDay(int year, int month)
	{
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,30 };
		int day = days[month];
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			day += 1;
		}
		return day;
	}
	Data operator+=(int day)
	{
		_day += day;
		while (_day > GetmonthDay(_year, _month))
		{
			_day -= GetmonthDay(_year, _month);
			_month += 1;
			if (_month > 12)
			{
				_year += 1;
				_month = 1;
			}
		}
		return *this;
	}
	Data operator+(int day)
	{
		Data temp(*this);
		temp += day;
		return temp;
	}
	bool operator>(const Data d)
	{
		if (_year >d._year)
		{
			return true;
		}
		else if (_year == d._month && _month > d._month)
		{
			return true;
		}
		else if (_year == d._month && _month == d._month && _day > d._day)
		{
			return true;
		}
		return false;
	}
	bool operator>=(const Data d)
	{
		return *this > d || *this == d;
	}
	bool operator<=(const Data d)
	{
		return !(*this > d);

	}
	bool operator<(const Data d)
	{
		return !(*this >= d);
	}
	bool operator!=(const Data d)
	{
		return !(*this == d);
	}



private:
	//给默认的值相当于声明   不是初始化
	/*int _year=1;
	int _month=1;
	int _day=1;*/
	//内置类型
	int _year;
	int _month;
	int _day;
	//自定义类型
	//Time t;
};

//	bool operator==(const Data& d1，const Data&d2);  
//这里出了Data域 *this不起作用 
//在上面用了友元  所以可以访问私有的成员

