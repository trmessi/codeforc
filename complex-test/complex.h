#pragma once
#include <ostream>
#ifndef __COMPLEX__
#define __COMPLEX__
//防卫式声明以防头文件多次解析
using namespace std;
//相同class的各个objects互为friends
class complex
{
public:
	friend complex& __doapl(complex*, const complex&);
	complex(double r = 0, double i = 0):re(r),im(i) {}
	
	complex& operator +=(const complex&);
	double real() const { return re; }//不会改变数据的函数就加const  
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
//参数传递：尽量引用 pass by reference ,如果不希望改数据则const
//返回值传递：尽量 return by reference.不能的情况：

//传递者无需知道接收者是以reference接收的
inline complex&
complex::operator +=(const complex& r)
{
	return __doapl(this, r);
}
inline complex//值传递会触发拷贝构造函数，引用不会。
operator +(const complex& x, const complex& y)
{
	return complex(x.real() + y.real(), x.imag() + y.imag());//临时对象
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