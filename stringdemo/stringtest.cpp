#include<iostream>
using namespace std;
#include"string.h"

int main()
{
	String s1("world");
	String s2("hello");
	String s3(s1);//拷贝构造函数
	cout << s3 << endl;
	s3 = s2;//赋值构造函数,如果是类带指针不能用编译器默认构造函数，要自己写。
	cout << s3 << endl;

}