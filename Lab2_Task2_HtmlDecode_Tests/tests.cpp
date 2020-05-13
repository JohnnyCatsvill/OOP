#include <catch2/catch.hpp>
#include "HtmlDecode.h"
#include <iostream>;

TEST_CASE("TranslateSpecialSymbol must turn strings to char")
{
	char expectedChar;
	char actualChar;

	expectedChar = '"';
	actualChar = TranslateSpecialSymbol("quot");
	CHECK(expectedChar == actualChar);

	expectedChar = '\'';
	actualChar = TranslateSpecialSymbol("apos");
	CHECK(expectedChar == actualChar);

	expectedChar = '&';
	actualChar = TranslateSpecialSymbol("amp");
	CHECK(expectedChar == actualChar);

	expectedChar = 'n';
	actualChar = TranslateSpecialSymbol("notKnown");
	CHECK(expectedChar == actualChar);
}

TEST_CASE("HtmlDecode should return string without &smth; constructions")
{
	string expectedString("Cat <says> \"Meow\". M&M's");
	string actualString = HtmlDecode("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s");

	CHECK(expectedString == actualString);
}