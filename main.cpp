#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct complex_t
{
private:
	float real;
	float imag;
public:
	complex_t() {
		real = 0.0f;
		imag = 0.0f;
	}

	const complex_t add(complex_t other) const { 
		complex_t result;
		result.real = this->real + other.real;
		result.imag = this->imag + other.imag;
		return result;
	}

	complex_t sub(complex_t other) const {
		complex_t result;
		result.real = this->real - other.real;
		result.imag = this->imag - other.imag;
		return result;
	}

	complex_t mul(complex_t other) const {
		complex_t result;
		result.real = (this->real * other.real - this->imag*other.imag);
		result.imag = (this->imag *other.real + this->real * other.imag);
		return result;
	}

	complex_t div(complex_t other) const {
		complex_t result;
		float znam = (other.real*other.real + other.imag*other.imag);
		if (znam != 0) {
			result.real = ((this->real*other.real + this->imag*other.imag) / (other.real*other.real + other.imag*other.imag));
			result.imag = ((this->imag*other.real - this->real*other.imag) / (other.real*other.real + other.imag*other.imag));
		}
		else {
			cout << "fail"; 
			exit(0);
		}
		return result;
	}

	complex_t operand(char op, complex_t complex1, complex_t complex2) {
		complex_t res;
		switch (op) {
		case '+': {
			res=complex1.add(complex2);
			res.output(cout);
			break;
		}
		case '-': {
			res = complex1.sub(complex2);
			res.output(cout);
			break;
		}
		case '/': {
			res = complex1.div(complex2);
			res.output(cout);
			break;
		}
		case '*': {
			res = complex1.mul(complex2);
			res.output(cout);
			break;
		}
		default: {
			cout << "An error has occured while reading input data";
			cin.get();
			exit(0);
		}
		}
	}

	ostream & output(ostream & stream) {
		return  stream << '(' << real << ", " << imag << ')';
	}

	istream & read(istream & stream) {
		char op;
		if (stream >> op && op == '(' &&
			stream >> this->real &&
			stream >> op && op == ',' &&
			stream >> this->imag &&
			stream >> op && op == ')')
		{
			return stream;
		}
		else {
			cout << "An error has occured while reading input data";
			cin.get();
			exit(0);
		}
	}

	~complex_t() {

	}
};

int main()
{
	complex_t complex1;
	complex_t complex2;
	complex_t result;
	string str;
	char op;

	getline(cin, str);
	istringstream stream(str);
	if (complex1.read(stream) && stream >> op && complex2.read(stream)) {
		result.operand(op,complex1,complex2);
	}
	else {
		cout << endl << "An error has occured while reading input data";
	}
	cin.get();
	return 0;
}
