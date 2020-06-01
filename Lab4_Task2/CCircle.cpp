#include "CCircle.h"

const double PI = 3.14159265358979323846;

double CCircle::GetArea()
{
	return PI * pow(radius, 2);
}
double CCircle::GetPerimeter()
{
	return 2 * PI * radius;
}
CPoint CCircle::GetCenter()
{
	return center;
}
double CCircle::GetRadius()
{
	return radius;
}
string CCircle::ToString()
{
	stringstream ss;
	string output;

	ss << "Circle " << center.GetPoint() << " " << to_string(radius);

	getline(ss, output);
	return output;
}