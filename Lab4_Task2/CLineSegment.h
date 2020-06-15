#pragma once
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(
		CPoint startPoint,
		CPoint endPoint,
		uint32_t outlineColor
	) : IShape()
	{
		this->m_startPoint = startPoint;
		this->m_endPoint = endPoint;
		this->m_outlineColor = outlineColor;
	}

	double GetArea()const;
	double GetPerimeter()const;
	CPoint GetStartPoint()const;
	CPoint GetEndPoint()const;
	uint32_t GetOutlineColor()const;

private:
	std::string AppendProperties()const override;
	CPoint m_startPoint;
	CPoint m_endPoint;
	uint32_t m_outlineColor;
};

