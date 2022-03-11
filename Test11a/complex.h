#include <iostream>
#include <math.h>

using namespace std;

class CComplex
{
private:
	double real;
	double imag;
public:
	CComplex(double=0, double = 0);
	~CComplex() {};

	CComplex operator=(CComplex);
	CComplex operator+(CComplex);
	CComplex operator-(CComplex);

	friend double operator~(CComplex);

	CComplex operator*(CComplex);
	CComplex operator/(CComplex);

	void citire();
	void afisare();

	friend ostream & operator<<(ostream &out,CComplex &a);
	friend istream & operator>>(istream &in,CComplex &a);
};
