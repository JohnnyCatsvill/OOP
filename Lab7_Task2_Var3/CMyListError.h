#pragma once
#include <string>
#include <stdexcept> 

class CMyListError : public std::invalid_argument
{
public:
	CMyListError(std::string const& message)
		: std::invalid_argument(message)
	{}
};

