#include "Complex.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Complex a{}, summa{}, razn{}, umnoj{}, del{};

	string path = "Text.txt";
	string str1, str2, cntofnums, str;
	ifstream f;
	int i,n;

	f.open(path);
	if (!f.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{	
		getline(f, cntofnums); 
		int n = stoi(cntofnums);
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
			umnoj.print();
		}
		cout << endl;

		razn = mass[0];
		del = mass[0];
		for (i = 1; i < n; i++) {
			razn = razn.Subtract(mass[i]);
			del = del.Devision(mass[i]);
		}

		cout << "Сумма чисел: ";
		summa.print();
		cout << endl;

		cout << "Разность чисел: ";
		razn.print();
		cout << endl;

		cout << "Произведение чисел: ";
		umnoj.print();
		cout << endl;

		cout << "Частное чисел: ";
		del.print();
		cout << endl;

		delete[] mass;
	}
	
}