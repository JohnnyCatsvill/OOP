#include "catch2/catch.hpp"
#include "GeometricFiguresTest.h"
#include <iostream>

TEST_CASE("RectangleCreationTest")
{
	ShapeType figures;
	vector<string> data;
	split("rectangle 10.3 20.15 30.7 40.4 ff0000 00ffaa", ' ', data);
	ReadRectangle(data, figures);

	CHECK(figures[0]->GetArea() == 30.7 * 40.4);
	CHECK(figures[0]->GetPerimeter() == 2 * (30.7 + 40.4));
	CHECK(figures[0]->GetOutlineColor() == 0xff0000);
	CHECK(figures[0]->ToString() == "Rectangle 10.300000/20.150000 41.000000/60.550000");

	ISolidShape* solidFigure = dynamic_cast<ISolidShape*>(figures[0]);
	CHECK(solidFigure->GetFillColor() == 0x00ffaa);

	CRectangle* realFigure = dynamic_cast<CRectangle*>(solidFigure);
	CHECK(realFigure->GetHeight() == 40.4);
	CHECK(realFigure->GetWidth() == 30.7);
	CHECK(realFigure->GetLeftTop().x == 10.3);
	CHECK(realFigure->GetLeftTop().y == 20.15);
	CHECK(realFigure->GetRightBottom().x == 41.0);
	CHECK(realFigure->GetRightBottom().y == 60.55);
}

TEST_CASE("TirangleCreationTest")
{
	ShapeType figures;
	vector<string> data;
	split("triangle 10.3 20.15 30.7 40.4 10.3 40.4 ff0000 00ffaa", ' ', data);
	ReadTriangle(data, figures);

	CHECK(figures[0]->GetArea() == abs(0.5 * ((10.3 - 10.3) * (40.4 - 40.4) - (20.15 - 40.4) * (30.7 - 10.3))));
	CHECK(figures[0]->GetPerimeter() == 
		sqrt(pow(10.3 - 30.7, 2) + pow(20.15 - 40.4, 2)) +
		sqrt(pow(30.7 - 10.3, 2) + pow(40.4 - 40.4, 2)) +
		sqrt(pow(10.3 - 10.3, 2) + pow(20.15 - 40.4, 2)));
	CHECK(figures[0]->GetOutlineColor() == 0xff0000);
	CHECK(figures[0]->ToString() == "Triangle 10.300000/20.150000 30.700000/40.400000 10.300000/40.400000");

	ISolidShape* solidFigure = dynamic_cast<ISolidShape*>(figures[0]);
	CHECK(solidFigure->GetFillColor() == 0x00ffaa);

	CTriangle* realFigure = dynamic_cast<CTriangle*>(solidFigure);
	CHECK(realFigure->GetVertex1().x == 10.3);
	CHECK(realFigure->GetVertex1().y == 20.15);
	CHECK(realFigure->GetVertex2().x == 30.7);
	CHECK(realFigure->GetVertex2().y == 40.4);
	CHECK(realFigure->GetVertex3().x == 10.3);
	CHECK(realFigure->GetVertex3().y == 40.4);
}

TEST_CASE("CircleCreationTest")
{
	ShapeType figures;
	vector<string> data;
	split("circle 10.3 20.15 10 ff0000 00ffaa", ' ', data);
	ReadCircle(data, figures);

	CHECK(figures[0]->GetArea() == 3.14159265358979323846 * pow(10, 2));
	CHECK(figures[0]->GetPerimeter() == 2 * 3.14159265358979323846 * 10);
	CHECK(figures[0]->GetOutlineColor() == 0xff0000);
	CHECK(figures[0]->ToString() == "Circle 10.300000/20.150000 10.000000");

	ISolidShape* solidFigure = dynamic_cast<ISolidShape*>(figures[0]);
	CHECK(solidFigure->GetFillColor() == 0x00ffaa);

	CCircle* realFigure = dynamic_cast<CCircle*>(solidFigure);
	CHECK(realFigure->GetCenter().x == 10.3);
	CHECK(realFigure->GetCenter().y == 20.15);
	CHECK(realFigure->GetRadius() == 10);
}

TEST_CASE("LineCreationTest")
{
	ShapeType figures;
	vector<string> data;
	split("line 10.3 20.15 30.7 40.4 ff00aa", ' ', data);
	ReadLine(data, figures);

	CHECK(figures[0]->GetArea() == sqrt(pow(30.7 - 10.3, 2) + pow(40.4 - 20.15, 2)));
	CHECK(figures[0]->GetPerimeter() == 2 * sqrt(pow(30.7 - 10.3, 2) + pow(40.4 - 20.15, 2)));
	CHECK(figures[0]->GetOutlineColor() == 0xff00aa);
	CHECK(figures[0]->ToString() == "Line 10.300000/20.150000 30.700000/40.400000");

	CLineSegment* realFigure = dynamic_cast<CLineSegment*>(figures[0]);
	CHECK(realFigure->GetStartPoint().x == 10.3);
	CHECK(realFigure->GetStartPoint().y == 20.15);
	CHECK(realFigure->GetEndPoint().x == 30.7);
	CHECK(realFigure->GetEndPoint().y == 40.4);
}

TEST_CASE("FindFigureWithBiggestArea")
{
	ShapeType figures;
	vector<string> data;
	split("line 10.3 20.15 30.7 40.4 ff00aa", ' ', data);
	ReadLine(data, figures);

	CHECK(BiggestAreaIndex(figures) == 0);

	split("rectangle 10.3 20.15 30.7 40.4 ff0000 00ffaa", ' ', data);
	ReadRectangle(data, figures);

	CHECK(BiggestAreaIndex(figures) == 1);

	split("triangle 10.3 20.15 30.7 40.4 10.3 40.4 ff0000 00ffaa", ' ', data);
	ReadTriangle(data, figures);

	CHECK(BiggestAreaIndex(figures) == 1);

	split("circle 10.3 20.15 10 ff0000 00ffaa", ' ', data);
	ReadCircle(data, figures);

	CHECK(BiggestAreaIndex(figures) == 3);
}

TEST_CASE("FindFigureWithSmallestPerimeter")
{
	ShapeType figures;
	vector<string> data;
	split("rectangle 10.3 20.15 30.7 40.4 ff0000 00ffaa", ' ', data);
	ReadRectangle(data, figures);

	CHECK(SmallestPerimeterIndex(figures) == 0);

	split("triangle 10.3 20.15 30.7 40.4 10.3 40.4 ff0000 00ffaa", ' ', data);
	ReadTriangle(data, figures);

	CHECK(SmallestPerimeterIndex(figures) == 1);

	split("line 10.3 20.15 30.7 40.4 ff00aa", ' ', data);
	ReadLine(data, figures);

	CHECK(SmallestPerimeterIndex(figures) == 2);

	split("circle 10.3 20.15 10 ff0000 00ffaa", ' ', data);
	ReadCircle(data, figures);

	CHECK(SmallestPerimeterIndex(figures) == 2);
}