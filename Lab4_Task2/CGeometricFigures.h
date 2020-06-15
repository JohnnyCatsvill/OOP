#pragma once
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CPoint.h"
#include "CTriangle.h"
#include <vector>
#include <istream>
#include <ostream>
#include <algorithm>

class CGeometricFigures
{
public:
	CGeometricFigures() {}

	void ReadFigure(std::istream& input);
	void GiveShapeInfo(const std::shared_ptr<IShape> figure, std::ostream& out)const;
	std::shared_ptr<IShape> Begin()const;
	std::shared_ptr<IShape> End()const;
	std::shared_ptr<IShape> BiggestAreaFigure()const;
	std::shared_ptr<IShape> SmallestPerimeterFigure()const;

private:
	std::vector<std::shared_ptr<IShape>> m_figures;

	void ReadLine(std::stringstream& input);
	void ReadCircle(std::stringstream& input);
	void ReadTriangle(std::stringstream& input);
	void ReadRectangle(std::stringstream& input);
};

