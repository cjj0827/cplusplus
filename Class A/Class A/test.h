#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>


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
	B(int a, int& ref)
		:_a(a)
		,_b(ref)
		,_c(10)
	{}

private:
	A _a;//自定义
	int& _b;//引用
	const int _c;//const修饰
};