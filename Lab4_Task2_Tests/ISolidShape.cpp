#include "ISolidShape.h"

uint32_t ISolidShape::GetFillColor()
{
	return fillColor;
}

double ISolidShape::GetArea()
{
	return 0;
}
double ISolidShape::GetPerimeter()
{
	return 0;
}
string ISolidShape::ToString()
{
	return "advancedShape";
}