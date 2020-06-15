#pragma once

#include <string>
#include "CPoint.h"
#include "NumeralSystem.h"
#include <sstream>

class IShape
{
public:
	virtual ~IShape() {};

	virtual double GetArea()const;
	virtual double GetPerimeter()const;
	virtual uint32_t GetOutlineColor()const;
	virtual std::string ToString()const;

private:
	virtual std::string AppendProperties()const;
};

