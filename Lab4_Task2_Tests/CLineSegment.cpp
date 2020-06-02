#include "CLineSegment.h"

double CLineSegment::GetArea()
{
	return sqrt(pow(endPoint.x - startPoint.x, 2) + pow(endPoint.y - startPoint.y, 2));
}
double CLineSegment::GetPerimeter()
{
	return 2* sqrt(pow(endPoint.x - startPoint.x, 2) + pow(endPoint.y - startPoint.y, 2));
}
CPoint CLineSegment::GetStartPoint()
{
	return startPoint;
}
CPoint CLineSegment::GetEndPoint()
{
	return endPoint;
}
string CLineSegment::ToString()
{
	stringstream ss;
	string output;

	ss << "Line " << startPoint.GetPoint() << " " << endPoint.GetPoint();

	getline(ss, output);
	return output;
}