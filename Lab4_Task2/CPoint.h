#pragma once
#include <string>

class CPoint
{
public:
	CPoint(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}

	~CPoint() {}

	std::string ToString()const;

	double x;
	double y;
};