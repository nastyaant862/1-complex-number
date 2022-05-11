#include "Complex.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void cmpExample() {
	setlocale(LC_ALL, "ru");
	Complex a{}, summa{}, razn{}, umnoj{}, del{};

	string path = "Text.txt";
	string str1, str2, cntofnums, str;
	ifstream f;
	int i, n;

	f.open(path);
	if (!f.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		getline(f, cntofnums);
		n = stoi(cntofnums);
		Complex* mass = new Complex[n];

		for (i = 0; i < n; i++) {
			getline(f, str);

			string::size_type sz;
			a.re = stod(str, &sz);
			a.im = stod(str.substr(sz));

			mass[i] = a;
		}

		summa.re = 0;
		summa.im = 0;
		for (i = 0; i < n; i++) {
			summa = summa.Sum(mass[i]);
		}

		umnoj = mass[0];
		for (i = 1; i < n; i++) {
			umnoj = umnoj.Multi(mass[i]);
		}
		cout << endl;

		razn = mass[0];
		del = mass[0];
		for (i = 1; i < n; i++) {
			razn = razn.Subtract(mass[i]);
			del = del.Devision(mass[i]);
		}

		cout << "Sum of numbers: ";
		summa.print();
		cout << endl;

		cout << "Number difference: ";
		razn.print();
		cout << endl;

		cout << "Product of numbers: ";
		umnoj.print();
		cout << endl;

		cout << "Quotient of numbers: ";
		del.print();
		cout << endl;

		double* modulemass = new double[n];
		for (int i = 0; i < n; i++) {
			modulemass[i] = mass[i].Module();
		}

		double maxmodule = 0;
		int indmaxmod = 0;

		for (int i = 0; i < n; i++) {
			if (modulemass[i] > maxmodule) {
				maxmodule = modulemass[i];
				indmaxmod = i;
			}

		}

		cout << "The number with the largest modulus: ";
		mass[indmaxmod].print();
		cout << "It's length: " << modulemass[indmaxmod] << endl;

		delete[] mass;
		delete[] modulemass;
	}

}

int main() {
	cmpExample();
}