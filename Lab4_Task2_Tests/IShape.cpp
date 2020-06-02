#include "IShape.h"

uint32_t IShape::GetOutlineColor()
{
	return outlineColor;
}

double IShape::GetArea()
{
	return 0;
}
double IShape::GetPerimeter()
{
	return 0;
}
string IShape::ToString()
{
	return "basicShape";
}