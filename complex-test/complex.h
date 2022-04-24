#pragma once
#include <ostream>
#ifndef __COMPLEX__
#define __COMPLEX__
//����ʽ�����Է�ͷ�ļ���ν���
using namespace std;
//��ͬclass�ĸ���objects��Ϊfriends
class complex
{
public:
	friend complex& __doapl(complex*, const complex&);
	complex(double r = 0, double i = 0):re(r),im(i) {}
	
	complex& operator +=(const complex&);
	double real() const { return re; }//����ı����ݵĺ����ͼ�const  
	double imag() const { return im; }
private:
	double re, im;


};

#endif // !__COMPLEX__
inline complex&
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}
//�������ݣ��������� pass by reference ,�����ϣ����������const
//����ֵ���ݣ����� return by reference.���ܵ������

//����������֪������������reference���յ�
inline complex&
complex::operator +=(const complex& r)
{
	return __doapl(this, r);
}
inline complex//ֵ���ݻᴥ���������캯�������ò��ᡣ
operator +(const complex& x, const complex& y)
{
	return complex(x.real() + y.real(), x.imag() + y.imag());//��ʱ����
}
inline const complex&
operator + (const complex & x)
{
	return x;
}
inline complex
operator - (const complex& x)
{
	return complex(-x.real(),-x.imag());
}
std::ostream&
operator << (ostream& os, const complex& x)
{
	return os << '(' << x.real() << ',' << x.imag() << ')';
}