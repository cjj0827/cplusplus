#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"

Data Test(Data d)
{
	Data temp(d);
	return temp;//���ص�ʱ����ֵ ����ÿ�������  ����Ҫ���ص�ʱ�򷵻�����  Ҫ����������򻹴���  �������static
}
int main()
{
	//Data d1;//��Ϊ��������
	//d1.Init(2023, 5, 8);
	//Data d1(2023,5,8);
	//d1.print();
	Data d2(2023,5,8);
	Data d3(d2);//��������
	//Test(d3);//��ֵ�ķ�ʽ���д��� ����ÿ����������d  ���Դ�����
	
	//cout << (d2 == d3) << endl;
	//�൱��
	//cout << (operator == (d2, d3)) << endl;
	d2.operator+(100);
	//d2.print();
	cout << d2 << endl;
	return 0;
}
