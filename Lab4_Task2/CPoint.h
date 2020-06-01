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

	std::string GetPoint();

	double x;
	double y;
};