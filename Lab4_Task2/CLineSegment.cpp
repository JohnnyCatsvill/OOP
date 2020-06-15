#include "CLineSegment.h"

double CLineSegment::GetArea()const
{
	return 0;
}
double CLineSegment::GetPerimeter()const
{
	return std::hypot(m_endPoint.x - m_startPoint.x, m_endPoint.y - m_startPoint.y);
}
CPoint CLineSegment::GetStartPoint()const
{
	return m_startPoint;
}
CPoint CLineSegment::GetEndPoint()const
{
	return m_endPoint;
}
uint32_t CLineSegment::GetOutlineColor()const
{
	return m_outlineColor;
}
std::string CLineSegment::AppendProperties()const
{
	return "Line start(" + m_startPoint.ToString() + ") end(" + m_endPoint.ToString() + ")";
}