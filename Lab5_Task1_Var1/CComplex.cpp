#include "CComplex.h"
#include <corecrt_math_defines.h>

using namespace std;

bool NumbersAreEqual(double number1, double number2)
{
	return (fabs(number1 - number2) < DBL_EPSILON);
}

bool isFailed(istream& in)
{
	return in.fail() ? true : false;
}

double CComplex::Re()const
{
	return real;
}

double CComplex::Im()const
{
	return image;
}

double CComplex::GetMagnitude()const
{
	return sqrt(pow(real, 2) + pow(image, 2));
}

double CComplex::GetArgument()const
{
	double arccos = acos(real / GetMagnitude());
	double arcsin = asin(image / GetMagnitude());

	if (arcsin >= 0)
	{
		return arccos;
	}
	else
	{
		return -arccos;
	}
}


const CComplex operator+(const CComplex& first, const CComplex& second)
{
	return CComplex(first.real + second.real, first.image + second.image);
}

const CComplex operator-(const CComplex& first, const CComplex& second)
{
	return CComplex(first.real - second.real, first.image - second.image);
}

const CComplex operator*(const CComplex& first, const CComplex& second)
{
	return CComplex(first.real * second.real - first.image * second.image, first.real * second.image + first.image * second.real);
}

const CComplex operator/(const CComplex& first, const CComplex& second)
{
	if (second.real == 0 && second.real == 0)
	{
		cout << "Деление на ноль\n";
		return CComplex(0, 0);
	}
	else
	{
		return CComplex((first.real * second.real + first.image * second.image) / (pow(second.real, 2) + pow(second.image, 2)), (second.real * first.image - first.real * second.image) / (pow(second.real, 2) + pow(second.image, 2)));
	}
}

const CComplex operator+(const CComplex& first)
{
	return first;
}

const CComplex operator-(const CComplex& first)
{
	return CComplex(-first.real, -first.image);
}

CComplex CComplex::operator+=(const CComplex& first)
{
	this->real += first.real;
	this->image += first.image;
	return *this;
}

CComplex CComplex::operator-=(const CComplex& first)
{
	this->real -= first.real;
	this->image -= first.image;
	return *this;
}

CComplex CComplex::operator*=(const CComplex& first)
{
	double tempReal = first.real * this->real - first.image * this->image;
	double tempImage = this->real * first.image + this->image * first.real;
	this->real = tempReal;
	this->image = tempImage;
	return *this;
}

CComplex CComplex::operator/=(const CComplex& first)
{
	double tempReal = (this->real * first.real + this->image * first.image) / (pow(first.real, 2) + pow(first.image, 2));
	double tempImage = (first.real * this->image - this->real * first.image) / (pow(first.real, 2) + pow(first.image, 2));
	this->real = tempReal;
	this->image = tempImage;
	return *this;
}

const bool operator==(const CComplex& first, const CComplex& second)
{
	return (NumbersAreEqual(first.real, second.real) && NumbersAreEqual(first.image, second.image));
}

const bool operator!=(const CComplex& first, const CComplex& second)
{
	return (!NumbersAreEqual(first.real, second.real) || !NumbersAreEqual(first.image, second.image));
}

const std::ostream& operator<<(std::ostream& out, const CComplex& first)
{
	out << first.Re();

	if (first.Im() >= 0)
	{
		out << '+' << first.Im() << 'i';
	}
	else
	{
		out << first.Im() << 'i';
	}

	return out;
}

const std::istream& operator>>(std::istream& in, CComplex& first)
{
	double real;
	double image;
	char ch;

	string wholeString;
	getline(in, wholeString);
	stringstream ss(wholeString);


	if (!ss.eof())
	{
		ss >> real;
		if (!isFailed(ss))
		{
			if (ss.peek() != EOF)
			{

			}
			first.real = real;
			if (!ss.eof())
			{
				ss >> image;
				if (!isFailed(ss))
				{
					first.image = image;
					if (!ss.eof())
					{
						ss >> ch;
						if (isFailed(ss) || ch != 'i')
						{
							first.image = 0;
						}
					}
					else
					{
						first.image = 0;
					}
				}
			}
		}
	}
	return in;
}

