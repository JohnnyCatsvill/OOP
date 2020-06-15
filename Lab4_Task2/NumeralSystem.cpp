#include "NumeralSystem.h"
#include <sstream>

using namespace std;

const string Dec2Hex(const uint32_t i)
{
	 stringstream ss;
	 ss << hex << nouppercase << i;
	 return ss.str();
}

const uint32_t Hex2Dec(const string& i)
{
	 uint32_t output;
	 stringstream(i) >> hex >> output;
	 return output;
}