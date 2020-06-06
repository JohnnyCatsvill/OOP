#pragma once
#include <cmath>
#include <istream>
#include <string>
#include <sstream>
#include <iostream>

class CComplex
{
private:
	double real;
	double image;

public:
	// ������������� ������������ ����� ���������� �������������� � ������ ������
	CComplex(double real = 0, double image = 0) 
	{
		this->real = real;
		this->image = image;
	}
	// ���������� �������������� ����� ������������ �����
	double Re()const;

	// ���������� ������ ����� ������������ �����
	double Im()const;

	// ���������� ������ ������������ �����
	double GetMagnitude()const;

	// ���������� �������� ������������ �����
	double GetArgument()const;

	friend const CComplex operator+(const CComplex& first, const CComplex& second);
	friend const CComplex operator-(const CComplex& first, const CComplex& second);
	friend const CComplex operator*(const CComplex& first, const CComplex& second);
	friend const CComplex operator/(const CComplex& first, const CComplex& second);

	friend const CComplex operator+(const CComplex& first);
	friend const CComplex operator-(const CComplex& first);

	CComplex operator+=(const CComplex& first);
	CComplex operator-=(const CComplex& first);
	CComplex operator*=(const CComplex& first);
	CComplex operator/=(const CComplex& first);

	friend const bool operator==(const CComplex& first, const CComplex& second);
	friend const bool operator!=(const CComplex& first, const CComplex& second);

	friend const std::ostream& operator<<(std::ostream& out, const CComplex& first);
	friend const std::istream& operator>>(std::istream& in, CComplex& first);
};


