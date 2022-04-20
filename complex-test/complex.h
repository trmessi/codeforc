#pragma once
#include <ostream>
#ifndef __COMPLEX__
#define __COMPLEX__
//����ʽ�����Է�ͷ�ļ���ν���


class complex
{
public:
	friend complex& __doapl(complex*, const complex&);
	complex(double r = 0, double i = 0):re(r),im(i) {}
	complex& operator +=(const complex);
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
/*ostream&
operator<<(ostream& os, const complex& x)
{
	return os << '(' << real(x) << '.'
		<< imag(x) << ')';
}
*/