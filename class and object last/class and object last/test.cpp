#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
class Time
{
	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա
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
		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;//Time ��ĳ�Ա
};


class A
{
private:
	int k;
	static int b;
public:
	class B//B��������A����Ԫ
	{
	public:
		void printA(const A& a)
		{
			cout << b << endl;//ֱ�ӷ��ʾ�̬��Ա����
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
	C().func(1);//��������   �������Ĭ�Ϲ��캯��
	//����û����Ҫ���� 
	//���������ü�����
	const C& ra = C();//����������г��� 

	return 0;
}