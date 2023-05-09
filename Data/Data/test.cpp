#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"

Data Test(Data d)
{
	Data temp(d);
	return temp;//返回的时候是值 会调用拷贝构造  若是要返回的时候返回引用  要求出了作用域还存在  比如加上static
}
int main()
{
	//Data d1;//此为函数声明
	//d1.Init(2023, 5, 8);
	//Data d1(2023,5,8);
	//d1.print();
	Data d2(2023,5,8);
	Data d3(d2);//拷贝构造
	//Test(d3);//以值的方式进行传递 会调用拷贝构造产生d  可以传引用
	
	//cout << (d2 == d3) << endl;
	//相当于
	//cout << (operator == (d2, d3)) << endl;
	d2.operator+(100);
	//d2.print();
	cout << d2 << endl;
	return 0;
}
