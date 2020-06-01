#pragma once

#include <string>
#include "CPoint.h"
#include "NumeralSystem.h"
#include <sstream>
using namespace std;

class IShape
{
protected:
	uint32_t outlineColor;

	IShape(uint32_t outlineColor)
	{
		this->outlineColor = outlineColor;
	}
	virtual ~IShape() {};

public:
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual string ToString();
	uint32_t GetOutlineColor();
};

