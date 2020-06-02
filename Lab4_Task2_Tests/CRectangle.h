#pragma once
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle
	(
		CPoint leftTop,
		CPoint rightBottom,
		uint32_t outlineColor,
		uint32_t fillColor
	) : ISolidShape
	(
		outlineColor,
		fillColor
	)
	{
		this->leftTop = leftTop;
		this->rightBottom = rightBottom;
	}

	virtual double GetArea();
	virtual double GetPerimeter();
	CPoint GetLeftTop();
	CPoint GetRightBottom();
	virtual string ToString();
	double GetWidth();
	double GetHeight();

protected:
	CPoint leftTop;
	CPoint rightBottom;
};


