#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class Complex {
	double re;
	double im;
public:
	explicit Complex(double re = 0, double im= 0) : re(re), im(im) {}
	Complex Sum(Complex n);
	Complex Subtract(Complex n);
	Complex Multi(Complex n);
	Complex Devision(Complex n);
	double Module();
	void print();
	friend void cmpExample();
};

#endif

