#define _CRT_SECURE_NO_WARNINGS 1
//#include"test.h"
#include<iostream>
using namespace std;
class A
{
public:
	A(int a)//û��Ĭ�ϵĹ���   ���봫��  Ĭ�ϵĹ��캯��  1.������Ĭ��Ĭ�����ɵ�2.ȱʡ3.�޲�
		:_a(a)
	{}

private:
	int _a;
	//int _a=0;  ���������ֵ��ȱʡֵ �Ǹ���ʼ���б��
};


class B
{
public:
	B(int a, int& ref)
		:_a(a)//ע�⾡�����������ͳ�ʼ����˳����һ�µ�  ����������ֵ
		, _b(ref)
		, _c(10)
	{}

private:
	A _a;//�Զ���
	int& _b;//����
	const int _c;//const����
};
//ʵ��һ���� ������������������
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

//���һ���� ֻ����ջ���߶��ϴ�������

class d
{
public:
	static d Getstack()//���ڵ��ó�Ա������Ҫ this  ����
	{
		d dd;
		return dd;
	}
	static d* Getheap()
	{
		return new d;
	}
private:
	//�����캯������Ϊ˽��
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


