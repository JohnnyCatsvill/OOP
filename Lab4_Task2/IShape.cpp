#include "IShape.h"
using namespace std;

uint32_t IShape::GetOutlineColor()const
{
	return 0;
}

double IShape::GetArea()const
{
	return 0;
}
double IShape::GetPerimeter()const
{
	return 0;
}
string IShape::AppendProperties()const
{
	return "";
}
string IShape::ToString()const
{
	stringstream ss;
	ss << AppendProperties() << " outColor(" << Dec2Hex(GetOutlineColor()) << ") area(" << GetArea() << ") perimeter(" << GetPerimeter() << ")";
	return ss.str();
}