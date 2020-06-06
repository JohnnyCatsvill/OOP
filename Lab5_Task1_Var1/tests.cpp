
#define _USE_MATH_DEFINES
#include "catch2/catch.hpp"
#include "CComplex.h"
#include <cmath>
#include <sstream>

using namespace std;

TEST_CASE("CComplexCreation")
{
	CComplex number = CComplex(15.25, -36);
	CHECK(number.Re() == 15.25);
	CHECK(number.Im() == -36);
	CHECK(number.GetMagnitude() - sqrt(pow(15.25, 2) + pow(-36, 2)) < DBL_EPSILON);
	CHECK(number.GetArgument() -  atan(15.25 / -36) < DBL_EPSILON);
}

TEST_CASE("CComplexCreationBadArgumentPoints")
{
	CComplex number = CComplex(1, 0);
	CHECK(number.GetArgument() - 0 < DBL_EPSILON);

	number = CComplex(0, 1);
	CHECK(number.GetArgument() - M_PI / 2 < DBL_EPSILON);

	number = CComplex(0, -1);
	CHECK(number.GetArgument() - (-M_PI / 2) < DBL_EPSILON);

	number = CComplex(-1, 0);
	CHECK(number.GetArgument() - M_PI < DBL_EPSILON);

	number = CComplex(-1, -1);
	CHECK(number.GetArgument() - (-3 * M_PI / 4) < DBL_EPSILON);
}

TEST_CASE("CComplexTesting'=='")
{
	CHECK(CComplex(12, -1) == CComplex(12, -1));
	CHECK(CComplex(0, 0) == CComplex(0, 0));
	CHECK(CComplex(0.1234567890123456, 0) == CComplex(0.1234567890123457, 0));
	CHECK(!(CComplex(0.123456789012345, 0) == CComplex(0.123456789012346, 0)));
}

TEST_CASE("CComplexTesting'!='")
{
	CHECK(!(CComplex(12, -1) != CComplex(12, -1)));
	CHECK(!(CComplex(0, 0) != CComplex(0, 0)));
	CHECK(!(CComplex(0.1234567890123456, 0) != CComplex(0.1234567890123457, 0)));
	CHECK(CComplex(0.123456789012345, 0) != CComplex(0.123456789012346, 0));
}

TEST_CASE("CComplexTesting'+'")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);
	double pos = 3;
	double neg = -1;

	CHECK(zeroZero + oneOne == oneOne);
	CHECK(negPos + oneOne == CComplex(-2, 6));
	CHECK(zeroZero + neg == CComplex(-1, 0));
	CHECK(negPos + pos == CComplex(0, 5));
}

TEST_CASE("CComplexTesting'-'")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);
	double pos = 3;
	double neg = -1;

	CHECK(zeroZero - oneOne == CComplex(-1, -1));
	CHECK(negPos - oneOne == CComplex(-4, 4));
	CHECK(zeroZero - neg == CComplex(1, 0));
	CHECK(negPos - pos == CComplex(-6, 5));
}

TEST_CASE("CComplexTesting'*'")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);
	double pos = 3;
	double neg = -1;

	CHECK(zeroZero * oneOne == CComplex(0, 0));
	CHECK(negPos * oneOne == CComplex(-8, 2));
	CHECK(zeroZero * neg == CComplex(0, 0));
	CHECK(negPos * pos == CComplex(-9, 15));
}

TEST_CASE("CComplexTesting'/'")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);
	double pos = 3;
	double neg = -1;

	CHECK(zeroZero / oneOne == CComplex(0, 0));
	CHECK(negPos / oneOne == CComplex(1, 4));
	CHECK(zeroZero / neg == CComplex(0, 0));
	CHECK(negPos / pos == CComplex(-1, 1.66666666666666666666));
}

TEST_CASE("CComplexTesting'+='")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);
	double pos = 3;
	double neg = -1;

	zeroZero += oneOne;
	CHECK(zeroZero == oneOne);

	negPos += oneOne;
	CHECK(negPos == CComplex(-2, 6));

	zeroZero = CComplex(0, 0);
	zeroZero += neg;
	CHECK(zeroZero == CComplex(-1, 0));

	negPos = CComplex(-3, 5);
	negPos += pos;
	CHECK(negPos == CComplex(0, 5));
}

TEST_CASE("CComplexTesting'-='")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);
	double pos = 3;
	double neg = -1;

	zeroZero -= oneOne;
	CHECK(zeroZero == CComplex(-1, -1));

	negPos -= oneOne;
	CHECK(negPos == CComplex(-4, 4));

	zeroZero = CComplex(0, 0);
	zeroZero -= neg;
	CHECK(zeroZero == CComplex(1, 0));

	negPos = CComplex(-3, 5);
	negPos -= pos;
	CHECK(negPos == CComplex(-6, 5));
}

TEST_CASE("CComplexTesting'*='")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);
	double pos = 3;
	double neg = -1;

	zeroZero *= oneOne;
	CHECK(zeroZero == CComplex(0, 0));

	negPos *= oneOne;
	CHECK(negPos == CComplex(-8, 2));

	zeroZero = CComplex(0, 0);
	zeroZero *= neg;
	CHECK(zeroZero == CComplex(0, 0));

	negPos = CComplex(-3, 5);
	negPos *= pos;
	CHECK(negPos == CComplex(-9, 15));
}

TEST_CASE("CComplexTesting'/='")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);
	double pos = 3;
	double neg = -1;

	zeroZero /= oneOne;
	CHECK(zeroZero == CComplex(0, 0));

	negPos /= oneOne;
	CHECK(negPos == CComplex(1, 4));

	zeroZero = CComplex(0, 0);
	zeroZero /= neg;
	CHECK(zeroZero == CComplex(0, 0));

	negPos = CComplex(-3, 5);
	negPos /= pos;
	CHECK(negPos == CComplex(-1, 1.66666666666666666666));
}

TEST_CASE("CComplexTesting'-'Unary")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);

	CHECK(zeroZero == -zeroZero);
	CHECK(zeroZero - oneOne == -oneOne);
	CHECK(-negPos == CComplex(3, -5));
}

TEST_CASE("CComplexTesting'+'Unary")
{
	CComplex zeroZero = CComplex(0, 0);
	CComplex oneOne = CComplex(1, 1);
	CComplex negPos = CComplex(-3, 5);

	CHECK(zeroZero == +zeroZero);
	CHECK(zeroZero + oneOne == +oneOne);
	CHECK(+negPos == CComplex(-3, 5));
}

TEST_CASE("CComplexTesting'>>'")
{
	CComplex complexNumber1;
	CComplex complexNumber2;
	CComplex complexNumber3;
	CComplex complexNumber4;
	CComplex complexNumber5;
	string input = "-2+5i\n0-3i\n5\n0\n5+3\n";
	stringstream ss(input);

	ss >> complexNumber1;
	ss >> complexNumber2;
	ss >> complexNumber3;
	ss >> complexNumber4;
	ss >> complexNumber5;

	CHECK(complexNumber1 == CComplex(-2, 5));
	CHECK(complexNumber2 == CComplex(0, -3));
	CHECK(complexNumber3 == CComplex(5, 0));
	CHECK(complexNumber4 == CComplex(0, 0));
	CHECK(complexNumber5 == CComplex(5, 0));
}

TEST_CASE("CComplexTesting'<<'")
{
	CComplex complexNumber1 = CComplex(-2, 5);
	CComplex complexNumber2 = CComplex(0, -3);
	CComplex complexNumber3 = CComplex(5, 0);
	CComplex complexNumber4 = CComplex(0, 0);
	string expected = "-2+5i|0-3i|5+0i|0+0i";
	stringstream ss;

	ss << complexNumber1;
	ss << '|';
	ss << complexNumber2;
	ss << '|';
	ss << complexNumber3;
	ss << '|';
	ss << complexNumber4;
	
	string actual;
	ss >> actual;

	CHECK(expected == actual);
}