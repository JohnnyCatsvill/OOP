#include <catch2/catch.hpp>
#include "Vector.h"
#include <iostream>

TEST_CASE("SortVector should sort vector by ascending")
{
	vector<float> containerActual;
	containerActual.push_back(3.12);
	containerActual.push_back(-3.01);
	containerActual.push_back(6);
	containerActual.push_back(12.0);
	containerActual.push_back(12.111);
	containerActual.push_back(-0);

	vector<float> containerExpected;
	containerExpected.push_back(-3.01);
	containerExpected.push_back(0);
	containerExpected.push_back(3.12);
	containerExpected.push_back(6);
	containerExpected.push_back(12.0);
	containerExpected.push_back(12.111);

	SortVector(containerActual);

	CHECK(containerExpected == containerActual);
}

TEST_CASE("MinElement should return smallest element")
{
	vector<float> container;
	container.push_back(3.12);
	container.push_back(-3.01);
	container.push_back(6);
	container.push_back(12.0);
	container.push_back(12.111);
	container.push_back(-12.21);
	container.push_back(-0);

	const float expectedNumber = -12.21;
	float actualNumber = MinElement(container);

	CHECK(expectedNumber == actualNumber);
}

TEST_CASE("MultiplyEveryElementToNumber should change vector to what it tells")
{
	vector<float> containerActual;
	containerActual.push_back(3.1);
	containerActual.push_back(-3.0);
	containerActual.push_back(6);
	containerActual.push_back(12.0);
	containerActual.push_back(12.1);
	containerActual.push_back(0);

	const float multiplyer = -3.1;
	MultiplyEveryElementToNumber(containerActual, multiplyer);

	vector<float> containerExpected;
	containerExpected.push_back(3.1 * multiplyer);
	containerExpected.push_back(-3.0 * multiplyer);
	containerExpected.push_back(6 * multiplyer);
	containerExpected.push_back(12.0 * multiplyer);
	containerExpected.push_back(12.1 * multiplyer);
	containerExpected.push_back(0 * multiplyer);

	CHECK(containerActual == containerExpected);
}
