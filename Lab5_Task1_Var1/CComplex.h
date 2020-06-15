#pragma once
#include <cmath>
#include <istream>
#include <string>
#include <sstream>
#include <iostream>
#include <corecrt_math_defines.h>

class CComplex
{
private:
	double m_real;
	double m_image;

public:
	// инициализация комплексного числа значениями действительной и мнимой частей
	CComplex(double real = 0, double image = 0) 
	{
		this->m_real = real;
		this->m_image = image;
	}
	// возвращает действительную часть комплексного числа
	double Re()const;

	// возвращает мнимую часть комплексного числа
	double Im()const;

	// возвращает модуль комплексного числа
	double GetMagnitude()const;

	// возвращает аргумент комплексного числа
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


