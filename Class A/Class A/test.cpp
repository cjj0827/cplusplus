#define _CRT_SECURE_NO_WARNINGS 1
//#include"test.h"
#include<iostream>
using namespace std;
class A
{
public:
	A(int a)//没有默认的构造   必须传参  默认的构造函数  1.编译器默认默认生成的2.缺省3.无参
		:_a(a)
	{}

private:
	int _a;
	//int _a=0;  在这里给的值是缺省值 是给初始化列表的
};


class B
{
public:
	B(int a, int& ref)
		:_a(a)//注意尽量保持声明和初始化的顺序是一致的  避免出现随机值
		, _b(ref)
		, _c(10)
	{}

private:
	A _a;//自定义
	int& _b;//引用
	const int _c;//const修饰
};
//实现一个类 计算出创建多少类对象
class c
{
public:
	c() { ++_count; }
	c(const c& t) { ++_count; }
	~c() { --_count; }
	static int Getcount() { return _count; }
private:
	static int _count;
};
int c::_count = 0;

//设计一个类 只能在栈或者堆上创建对象

class d
{
public:
	static d Getstack()//由于调用成员函数需要 this  所以
	{
		d dd;
		return dd;
	}
	static d* Getheap()
	{
		return new d;
	}
private:
	//将构造函数设置为私有
	d()
	{}
	int _a = 1;
	int _b = 2;
};


int main()
{
	/*int y= 1;
	B b1(2, y);*/

	cout << c::Getcount() << endl;
	c a, d;
	c c(a);
	cout << c::Getcount() << endl;
	 d::Getstack();
	return 0;
}


