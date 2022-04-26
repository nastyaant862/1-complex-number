#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

struct Complex {
	double re;
	double im;

	Complex Sum(Complex n);
	Complex Subtract(Complex n);
	Complex Multi(Complex n);
	Complex Devision(Complex n);
	void print();
};

#endif

