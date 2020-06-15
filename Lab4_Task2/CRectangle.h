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
	) : ISolidShape()
	{
		this->m_leftTop = leftTop;
		this->m_rightBottom = rightBottom;
		this->m_outlineColor = outlineColor;
		this->m_fillColor = fillColor;
	}

	double GetArea()const;
	double GetPerimeter()const;
	CPoint GetLeftTop()const;
	CPoint GetRightBottom()const;
	double GetWidth()const;
	double GetHeight()const;
	uint32_t GetOutlineColor()const;
	uint32_t GetFillColor()const;

private:
	std::string AppendSolidProperties()const override;
	CPoint m_leftTop;
	CPoint m_rightBottom;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};


