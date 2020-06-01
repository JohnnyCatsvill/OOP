#include "CRectangle.h"

double CRectangle::GetArea()
{
	return abs((rightBottom.x - leftTop.x) * (rightBottom.y - leftTop.y));
}
double CRectangle::GetPerimeter()
{
	return 2 * (abs(rightBottom.x - leftTop.x) + abs(rightBottom.y - leftTop.y));
}
CPoint CRectangle::GetLeftTop()
{
	return leftTop;
}
CPoint CRectangle::GetRightBottom()
{
	return rightBottom;
}
string CRectangle::ToString()
{
	stringstream ss;
	string output;

	ss << "Rectangle " << leftTop.GetPoint() << " " << rightBottom.GetPoint();

	getline(ss, output);
	return output;
}
double CRectangle::GetWidth()
{
	return abs(rightBottom.x - leftTop.x);
}
double CRectangle::GetHeight()
{
	return abs(rightBottom.y - leftTop.y);
}