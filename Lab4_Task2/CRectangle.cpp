#include "CRectangle.h"

double CRectangle::GetArea()const
{
	return abs((m_rightBottom.x - m_leftTop.x) * (m_rightBottom.y - m_leftTop.y));
}
double CRectangle::GetPerimeter()const
{
	return 2 * (abs(m_rightBottom.x - m_leftTop.x) + abs(m_rightBottom.y - m_leftTop.y));
}
CPoint CRectangle::GetLeftTop()const
{
	return m_leftTop;
}
CPoint CRectangle::GetRightBottom()const
{
	return m_rightBottom;
}
double CRectangle::GetWidth()const
{
	return abs(m_rightBottom.x - m_leftTop.x);
}
double CRectangle::GetHeight()const
{
	return abs(m_rightBottom.y - m_leftTop.y);
}
uint32_t CRectangle::GetFillColor()const
{
	return m_fillColor;
}
uint32_t CRectangle::GetOutlineColor()const
{
	return m_outlineColor;
}
std::string CRectangle::AppendSolidProperties()const
{
	return "Rectangle leftTop(" + m_leftTop.ToString() + ") rightBottom(" + m_rightBottom.ToString() + ")";
}