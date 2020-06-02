#include "NumeralSystem.h"
#include <sstream>

using namespace std;

string dec2hex(uint32_t i)
{
	 stringstream ss;
	 ss << hex << nouppercase << i;
	 return ss.str();
}

 uint32_t hex2dec(string i)
{
	 uint32_t output;
	 stringstream(i) >> hex >> output;
	 return output;
}

 bool isNumber(string& number)
 {
	 return number[0] >= '0' && number[0] <= '9';
 }

 bool isHexNumber(string& number)
 {
	 return number[0] >= '0' && number[0] <= '9' || tolower(number[0]) >= 'a' && tolower(number[0]) <= 'f';
 }