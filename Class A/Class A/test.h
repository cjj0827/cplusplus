#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>


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
	B(int a, int& ref)
		:_a(a)
		,_b(ref)
		,_c(10)
	{}

private:
	A _a;//�Զ���
	int& _b;//����
	const int _c;//const����
};