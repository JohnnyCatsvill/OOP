#pragma once
#include "ISolidShape.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle
	(
		CPoint vertex1,
		CPoint vertex2,
		CPoint vertex3,
		uint32_t outlineColor,
		uint32_t fillColor
	) : ISolidShape()
	{
		this->m_vertex1 = vertex1;
		this->m_vertex2 = vertex2;
		this->m_vertex3 = vertex3;
		this->m_outlineColor = outlineColor;
		this->m_fillColor = fillColor;
	}

	double GetArea()const;
	double GetPerimeter()const;
	CPoint GetVertex1()const;
	CPoint GetVertex2()const;
	CPoint GetVertex3()const;
	uint32_t GetOutlineColor()const;
	uint32_t GetFillColor()const;

private:
	std::string AppendSolidProperties()const override;
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};

