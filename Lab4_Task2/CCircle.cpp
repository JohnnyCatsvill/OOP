#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

double CCircle::GetArea()const
{
	return M_PI * pow(m_radius, 2);
}
double CCircle::GetPerimeter()const
{
	return 2 * M_PI * m_radius;
}
CPoint CCircle::GetCenter()const
{
	return m_center;
}
double CCircle::GetRadius()const
{
	return m_radius;
}

uint32_t CCircle::GetFillColor()const
{
	return m_fillColor;
}
uint32_t CCircle::GetOutlineColor()const
{
	return m_outlineColor;
}

std::string CCircle::AppendSolidProperties()const
{
	return "Circle center(" + m_center.ToString() + ") radius(" + std::to_string(m_radius) + ")";
}