#pragma once

#include "IShape.h"
using namespace std;

class ISolidShape : public IShape
{
protected:
	uint32_t fillColor;

	ISolidShape(uint32_t outlineColor,	uint32_t fillColor) : IShape(outlineColor)
	{
		this->fillColor = fillColor;
	}

	virtual ~ISolidShape() {};

public:
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual string ToString();
	uint32_t GetFillColor();
};

