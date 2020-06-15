#include "CComplex.h"

using namespace std;

bool NumbersAreEqual(double number1, double number2)
{
	return (fabs(number1 - number2) < DBL_EPSILON);
}

bool IsFailed(istream& in)
{
	return in.fail() ? true : false;
}

double CComplex::Re()const
{
	return m_real;
}

double CComplex::Im()const
{
	return m_image;
}

double CComplex::GetMagnitude()const
{
	return sqrt(pow(m_real, 2) + pow(m_image, 2));
}

double CComplex::GetArgument()const
{
	double arccos = acos(m_real / GetMagnitude());
	double arcsin = asin(m_image / GetMagnitude());

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
	return CComplex(first.m_real + second.m_real, first.m_image + second.m_image);
}

const CComplex operator-(const CComplex& first, const CComplex& second)
{
	return CComplex(first.m_real - second.m_real, first.m_image - second.m_image);
}

const CComplex operator*(const CComplex& first, const CComplex& second)
{
	return CComplex(first.m_real * second.m_real - first.m_image * second.m_image, first.m_real * second.m_image + first.m_image * second.m_real);
}

const CComplex operator/(const CComplex& first, const CComplex& second)
{
	if (second.m_real == 0 && second.m_real == 0)
	{
		cout << "Деление на ноль\n";
		return CComplex(0, 0);
	}
	else
	{
		return CComplex((first.m_real * second.m_real + first.m_image * second.m_image) / (pow(second.m_real, 2) + pow(second.m_image, 2)), (second.m_real * first.m_image - first.m_real * second.m_image) / (pow(second.m_real, 2) + pow(second.m_image, 2)));
	}
}

const CComplex operator+(const CComplex& first)
{
	return first;
}

const CComplex operator-(const CComplex& first)
{
	return CComplex(-first.m_real, -first.m_image);
}

CComplex CComplex::operator+=(const CComplex& first)
{
	this->m_real += first.m_real;
	this->m_image += first.m_image;
	return *this;
}

CComplex CComplex::operator-=(const CComplex& first)
{
	this->m_real -= first.m_real;
	this->m_image -= first.m_image;
	return *this;
}

CComplex CComplex::operator*=(const CComplex& first)
{
	double tempReal = first.m_real * this->m_real - first.m_image * this->m_image;
	double tempImage = this->m_real * first.m_image + this->m_image * first.m_real;
	this->m_real = tempReal;
	this->m_image = tempImage;
	return *this;
}

CComplex CComplex::operator/=(const CComplex& first)
{
	double tempReal = (this->m_real * first.m_real + this->m_image * first.m_image) / (pow(first.m_real, 2) + pow(first.m_image, 2));
	double tempImage = (first.m_real * this->m_image - this->m_real * first.m_image) / (pow(first.m_real, 2) + pow(first.m_image, 2));
	this->m_real = tempReal;
	this->m_image = tempImage;
	return *this;
}

const bool operator==(const CComplex& first, const CComplex& second)
{
	return (NumbersAreEqual(first.m_real, second.m_real) && NumbersAreEqual(first.m_image, second.m_image));
}

const bool operator!=(const CComplex& first, const CComplex& second)
{
	return (!NumbersAreEqual(first.m_real, second.m_real) || !NumbersAreEqual(first.m_image, second.m_image));
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
	double m_real;
	double m_image;
	char ch;

	string wholeString;
	getline(in, wholeString);
	stringstream ss(wholeString);


	if (!ss.eof())
	{
		ss >> m_real;
		if (!IsFailed(ss))
		{
			if (ss.peek() != EOF)
			{

			}
			first.m_real = m_real;
			if (!ss.eof())
			{
				ss >> m_image;
				if (!IsFailed(ss))
				{
					first.m_image = m_image;
					if (!ss.eof())
					{
						ss >> ch;
						if (IsFailed(ss) || ch != 'i')
						{
							first.m_image = 0;
						}
					}
					else
					{
						first.m_image = 0;
					}
				}
			}
		}
	}
	return in;
}

