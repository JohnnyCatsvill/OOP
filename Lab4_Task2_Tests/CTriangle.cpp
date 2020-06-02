#include "CTriangle.h"

double CTriangle::GetArea()
{
	return abs(0.5 * ((vertex1.x - vertex3.x) * (vertex2.y - vertex3.y) - (vertex1.y - vertex3.y) * (vertex2.x - vertex3.x)));
}
double CTriangle::GetPerimeter()
{
	return sqrt(pow(vertex1.x - vertex2.x, 2) + pow(vertex1.y - vertex2.y, 2)) +
		sqrt(pow(vertex2.x - vertex3.x, 2) + pow(vertex2.y - vertex3.y, 2)) +
		sqrt(pow(vertex1.x - vertex3.x, 2) + pow(vertex1.y - vertex3.y, 2));
}
CPoint CTriangle::GetVertex1()
{
	return vertex1;
}
CPoint CTriangle::GetVertex2()
{
	return vertex2;
}
CPoint CTriangle::GetVertex3()
{
	return vertex3;
}
string CTriangle::ToString()
{
	stringstream ss;
	string output;

	ss << "Triangle " << vertex1.GetPoint() << " " << vertex2.GetPoint() << " " << vertex3.GetPoint();

	getline(ss, output);
	return output;
}