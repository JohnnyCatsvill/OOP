#define CATCH_CONFIG_MAIN 
#include "catch2/catch.hpp"
#include "../Lab4_Task2/CGeometricFigures.h"
#include <iostream>

using namespace std;

TEST_CASE("RectangleCreationTest")
{
	CGeometricFigures figures;
	stringstream in;
	stringstream actual;
	stringstream expected;
	in << "rectangle 10.3 20.15 30.7 40.4 ff0000 00ffaa";
	expected << "Rectangle leftTop(10.300000/20.150000) rightBottom(41.000000/60.550000) fillColor(ffaa) outColor(ff0000) area(1240.28) perimeter(142.2)";

	figures.ReadFigure(in);
	figures.GiveShapeInfo(figures.Begin(), actual);

	CHECK(expected.str() == actual.str());
}

TEST_CASE("TriangleCreationTest")
{
	CGeometricFigures figures;
	stringstream in;
	stringstream actual;
	stringstream expected;
	in << "triangle 10.3 20.15 30.7 40.4 10.3 40.4 ff0000 00ffaa";
	expected << "Triangle vertex1(10.300000/20.150000) vertex2(30.700000/40.400000) vertex3(10.300000/40.400000) fillColor(ffaa) outColor(ff0000) area(206.55) perimeter(69.3941)";

	figures.ReadFigure(in);
	figures.GiveShapeInfo(figures.Begin(), actual);

	CHECK(expected.str() == actual.str());
}

TEST_CASE("LineCreationTest")
{
	CGeometricFigures figures;
	stringstream in;
	stringstream actual;
	stringstream expected;
	in << "line 10.3 20.15 30.7 40.4 ff00aa";
	expected << "Line start(10.300000/20.150000) end(30.700000/40.400000) outColor(ff00aa) area(0) perimeter(28.7441)";

	figures.ReadFigure(in);
	figures.GiveShapeInfo(figures.Begin(), actual);

	CHECK(expected.str() == actual.str());
}
TEST_CASE("CircleCreationTest")
{
	CGeometricFigures figures;
	stringstream in;
	stringstream actual;
	stringstream expected;
	in << "circle 10.3 20.15 10 ff0000 00ffaa";
	expected << "Circle center(10.300000/20.150000) radius(10.000000) fillColor(ffaa) outColor(ff0000) area(314.159) perimeter(62.8319)";

	figures.ReadFigure(in);
	figures.GiveShapeInfo(figures.Begin(), actual);

	CHECK(expected.str() == actual.str());
}


TEST_CASE("FindFigureWithBiggestArea")
{
	CGeometricFigures figures;
	stringstream in;
	in << "line 10.3 20.15 30.7 40.4 ff00aa\n"
		<< "rectangle 10.3 20.15 30.7 40.4 ff0000 00ffaa\n"
		<< "triangle 10.3 20.15 30.7 40.4 10.3 40.4 ff0000 00ffaa\n"
		<< "circle 10.3 20.15 10 ff0000 00ffaa\n";
	for (int i = 0; i < 4; i++)
	{
		figures.ReadFigure(in);
	}

	stringstream expected;
	stringstream actual;
	expected << "Rectangle leftTop(10.300000/20.150000) rightBottom(41.000000/60.550000) fillColor(ffaa) outColor(ff0000) area(1240.28) perimeter(142.2)";
	figures.GiveShapeInfo(figures.BiggestAreaFigure(), actual);

	CHECK(expected.str() == actual.str());
}

TEST_CASE("FindFigureWithSmallestPerimeter")
{
	CGeometricFigures figures;
	stringstream in;
	in << "line 10.3 20.15 30.7 40.4 ff00aa\n"
		<< "rectangle 10.3 20.15 30.7 40.4 ff0000 00ffaa\n"
		<< "triangle 10.3 20.15 30.7 40.4 10.3 40.4 ff0000 00ffaa\n"
		<< "circle 10.3 20.15 10 ff0000 00ffaa\n";
	for (int i = 0; i < 4; i++)
	{
		figures.ReadFigure(in);
	}

	stringstream expected;
	stringstream actual;
	expected << "Line start(10.300000/20.150000) end(30.700000/40.400000) outColor(ff00aa) area(0) perimeter(28.7441)";
	figures.GiveShapeInfo(figures.SmallestPerimeterFigure(), actual);

	CHECK(expected.str() == actual.str());
}