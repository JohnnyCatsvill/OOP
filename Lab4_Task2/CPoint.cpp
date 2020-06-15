#include "CPoint.h"

std::string CPoint::ToString()const
{
	return std::to_string(x) + "/" + std::to_string(y);
}
