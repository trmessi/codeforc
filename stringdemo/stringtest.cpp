#include<iostream>

#include"string.h"
using namespace std;
int main()
{
	String s1();
	String s2("hello");
	String s3(s1);//�������캯��
	cout << s3 << endl;
	s3 = s2;//��ֵ���캯��,��������ָ�벻���ñ�����Ĭ�Ϲ��캯����Ҫ�Լ�д��
	cout << s3 << endl;

}