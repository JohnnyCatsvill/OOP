#define CATCH_CONFIG_MAIN 
#include "../Lab2_Task2_HtmlDecode_Program/HtmlDecodeProgramm.h"
#include "catch2/catch.hpp"

using namespace std;

TEST_CASE("HtmlDecode should return string without &smth; constructions")
{
	string expectedString("Cat <says> \"Meow\". M&M's");
	string actualString = HtmlDecode("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s", "SymbolsMap.txt");

	CHECK(expectedString == actualString);
}

TEST_CASE("HtmlDecode should write back unused &smth; constructions")
{
	string expectedString("Cat &alter;says &who knows;");
	string actualString = HtmlDecode("Cat &alter;says &who knows;", "SymbolsMap.txt");

	CHECK(expectedString == actualString);
}

TEST_CASE("HtmlDecode should write back unfinished &smth constructions")
{
	string expectedString("Cat &alter says > &hello");
	string actualString = HtmlDecode("Cat &alter says &gt; &hello", "SymbolsMap.txt");

	CHECK(expectedString == actualString);
}