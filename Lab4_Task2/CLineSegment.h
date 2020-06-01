#pragma once
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(
		CPoint startPoint,
		CPoint endPoint,
		uint32_t outlineColor
	) : IShape
	(
		outlineColor
	)
	{
		this->startPoint = startPoint;
		this->endPoint = endPoint;
	}

	double GetArea();
	double GetPerimeter();
	CPoint GetStartPoint();
	CPoint GetEndPoint();
	string ToString();

private:
	CPoint startPoint;
	CPoint endPoint;
};

