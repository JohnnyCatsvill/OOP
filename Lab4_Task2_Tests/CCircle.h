#pragma once
#include "ISolidShape.h"

class CCircle : public ISolidShape
{
public:
	CCircle
	(
		CPoint center,
		double radius,
		uint32_t outlineColor,
		uint32_t fillColor
	) : ISolidShape
	(
		outlineColor,
		fillColor
	)
	{
		this->center = center;
		this->radius = radius;
	}

	double GetArea();
	double GetPerimeter();
	CPoint GetCenter();
	double GetRadius();
	string ToString();

private:
	CPoint center;
	double radius;
};

