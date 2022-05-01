#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class Complex {

public:
	double re;
	double im;

	Complex Sum(Complex n);
	Complex Subtract(Complex n);
	Complex Multi(Complex n);
	Complex Devision(Complex n);
	double Module();
	void print();
};

#endif

