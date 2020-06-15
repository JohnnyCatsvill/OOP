#pragma once

#include "IShape.h"

class ISolidShape : public IShape
{
public:
	virtual ~ISolidShape() {};

	virtual double GetArea()const;
	virtual double GetPerimeter()const;
	virtual uint32_t GetOutlineColor()const;
	virtual uint32_t GetFillColor()const;

private:
	 virtual std::string AppendProperties()const override;
	 virtual std::string AppendSolidProperties()const;
};

