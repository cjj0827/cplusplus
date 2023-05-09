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
//	//����
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
	//�޲ι��� 
	//Data()
	//{}
	Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()const//���ε���*this
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void Init(int year, int month, int day);
	
	//���Ǵ�ֵ�ͻ���������ݹ�  һֱ���п�������
	//����������û���漰��Դ����ʱ д��д������ 
	//��������Դ����δд  1.���������� ��д������   2.һ���ı� ��һ��Ҳ�����ı䣨ָ��ͬһ����ַ��
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��ֵ����������ǳ�Ա���� �������ʾʵ�� ������������һ��Ĭ�ϵ� ���ȫ�ֵ����� ������ͻ
	Data operator=(const Data& d)//��������thisָ��
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//���ص���*this  this���˾�����
	}
	//ǰ��++
	Data& operator++()
	{
		_day += 1;
		return *this;
	}
	//����++
	Data operator++(int)
	{
		Data temp(*this);
		_day += 1;
		return temp;//temp�ᱻ�������� ֻ����ֵ����ʽ����
	}
	//��ȡÿ���µ�����
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
	//��Ĭ�ϵ�ֵ�൱������   ���ǳ�ʼ��
	/*int _year=1;
	int _month=1;
	int _day=1;*/
	//��������
	int _year;
	int _month;
	int _day;
	//�Զ�������
	//Time t;
};

//	bool operator==(const Data& d1��const Data&d2);  
//�������Data�� *this�������� 
//������������Ԫ  ���Կ��Է���˽�еĳ�Ա

