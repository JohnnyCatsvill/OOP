#include "ISolidShape.h"
using namespace std;

uint32_t ISolidShape::GetFillColor()const
{
	return 0;
}
uint32_t ISolidShape::GetOutlineColor()const
{
	return 0;
}

double ISolidShape::GetArea()const
{
	return 0;
}
double ISolidShape::GetPerimeter()const
{
	return 0;
}
string ISolidShape::AppendSolidProperties()const
{
	return "";
}
string ISolidShape::AppendProperties()const
{
	return AppendSolidProperties() + " fillColor(" + Dec2Hex(GetFillColor()) + ")";
}
