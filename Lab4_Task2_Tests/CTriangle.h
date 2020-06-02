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
	) : ISolidShape
	(
		outlineColor,
		fillColor
	)
	{
		this->vertex1 = vertex1;
		this->vertex2 = vertex2;
		this->vertex3 = vertex3;
	}

	double GetArea();
	double GetPerimeter();
	CPoint GetVertex1();
	CPoint GetVertex2();
	CPoint GetVertex3();
	string ToString();

private:
	CPoint vertex1;
	CPoint vertex2;
	CPoint vertex3;
};

