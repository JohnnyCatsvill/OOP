#include "CPoint.h"

std::string CPoint::GetPoint()
{
	return std::to_string(x) + "/" + std::to_string(y);
}
