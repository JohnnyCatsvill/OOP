#include "CTriangle.h"

double CTriangle::GetArea()const
{
	return abs(0.5 * ((m_vertex1.x - m_vertex3.x) * (m_vertex2.y - m_vertex3.y) - (m_vertex1.y - m_vertex3.y) * (m_vertex2.x - m_vertex3.x)));
}
double CTriangle::GetPerimeter()const
{
	return std::hypot(m_vertex1.x - m_vertex2.x, m_vertex1.y - m_vertex2.y) +
		std::hypot(m_vertex2.x - m_vertex3.x, m_vertex2.y - m_vertex3.y) +
		std::hypot(m_vertex1.x - m_vertex3.x, m_vertex1.y - m_vertex3.y);
}
CPoint CTriangle::GetVertex1()const
{
	return m_vertex1;
}
CPoint CTriangle::GetVertex2()const
{
	return m_vertex2;
}
CPoint CTriangle::GetVertex3()const
{
	return m_vertex3;
}
uint32_t CTriangle::GetFillColor()const
{
	return m_fillColor;
}
uint32_t CTriangle::GetOutlineColor()const
{
	return m_outlineColor;
}
std::string CTriangle::AppendSolidProperties()const
{
	return "Triangle vertex1(" + m_vertex1.ToString() + ") vertex2(" + m_vertex2.ToString() + ") vertex3(" + m_vertex3.ToString() + ")";
}