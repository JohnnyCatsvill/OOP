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
	) : ISolidShape()
	{
		this->m_center = center;
		this->m_radius = radius;
		this->m_outlineColor = outlineColor;
		this->m_fillColor = fillColor;
	}

	double GetArea()const;
	double GetPerimeter()const;
	CPoint GetCenter()const;
	double GetRadius()const;
	uint32_t GetOutlineColor()const;
	uint32_t GetFillColor()const;

private:
	std::string AppendSolidProperties()const override;
	CPoint m_center;
	double m_radius;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};

