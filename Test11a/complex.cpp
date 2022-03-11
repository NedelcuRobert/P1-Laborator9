#include "complex.h"


CComplex::CComplex(double r, double i)
{
	real = r;
	imag = i;
}

CComplex CComplex::operator=(CComplex z) {
	real = z.real;
	imag = z.imag;
	return z;
}

CComplex CComplex::operator+(CComplex z) {
	return CComplex(real + z.real, imag + z.imag);
}

CComplex CComplex::operator-(CComplex z) {
	return CComplex(real - z.real, imag - z.imag);
}

double operator~(CComplex z) {
	return sqrt(pow(z.real, 2) + pow(z.imag, 2));
}

CComplex CComplex::operator*(CComplex a) {
	CComplex rez;
	rez.real = real * a.real - imag * a.imag;
	rez.imag = real * a.imag + a.real * imag;
	return rez;
}

CComplex CComplex::operator/(CComplex a) {
	CComplex rez;
	rez.real = (real * a.real + imag * a.imag) / (a.real * a.real + a.imag * a.imag);
	rez.imag = (imag * a.real - real * a.imag) / (a.real * a.real + a.imag * a.imag);
	return rez;
}

ostream& operator<<(ostream& out,CComplex &a) {
	out << a.real << "+" << a.imag;
	return out;
}

istream& operator>>(istream& in,CComplex &a) {
	in >> a.real >> a.imag;
	return in;
}
