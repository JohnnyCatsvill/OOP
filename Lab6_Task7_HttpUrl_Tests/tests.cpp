#define CATCH_CONFIG_MAIN 
#include "catch2/catch.hpp"
#include "../Lab6_Task7_HttpUrl/CHttpUrl.h"

using namespace std;
TEST_CASE("Positive only domain")
{
	string expected = "https://google.com";
	string actual = "";
	try
	{
		CHttpUrl url(expected);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(expected);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "google.com");
		CHECK(url.GetPort() == 0);
		CHECK(url.GetDocument() == "");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive domain and path")
{
	string expected = "https://vk.com/oop.blog";
	string actual = "";
	try
	{
		CHttpUrl url(expected);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(expected);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "vk.com");
		CHECK(url.GetPort() == 0);
		CHECK(url.GetDocument() == "/oop.blog");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive domain and port and path")
{
	string expected = "http://www.example.com:8080/path/";
	string actual = "";
	try
	{
		CHttpUrl url(expected);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(expected);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTP);
		CHECK(url.GetDomain() == "www.example.com");
		CHECK(url.GetPort() == 8080);
		CHECK(url.GetDocument() == "/path/");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive domain and port and path Port == Protocol")
{
	string input = "http://www.example.com:80/path/";
	string expected = "http://www.example.com/path/";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTP);
		CHECK(url.GetDomain() == "www.example.com");
		CHECK(url.GetPort() == 80);
		CHECK(url.GetDocument() == "/path/");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive only protocol and path with slash")
{
	string input = "http:/path";
	string expected = "http:/path";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTP);
		CHECK(url.GetDomain() == "");
		CHECK(url.GetPort() == 0);
		CHECK(url.GetDocument() == "/path");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive only protocol and path without slash")
{
	string input = "http:path";
	string expected = "http:/path";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTP);
		CHECK(url.GetDomain() == "");
		CHECK(url.GetPort() == 0);
		CHECK(url.GetDocument() == "/path");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive domain and port and path url mess")
{
	string input = "hTtP://wWw.ExAmPlE.cOm/pAtH/";
	string expected = "hTtP://wWw.ExAmPlE.cOm/pAtH/";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTP);
		CHECK(url.GetDomain() == "wWw.ExAmPlE.cOm");
		CHECK(url.GetPort() == 0);
		CHECK(url.GetDocument() == "/pAtH/");
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative Empty String")
{
	string input = "";
	string expected = "Entered url is empty";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative Only protocol")
{
	string input = "https";
	string expected = "Sourse of page must be provided";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative Wrong Protocol")
{
	string input = "httq://www.example.com:80/path/";
	string expected = "Invalid Protocol. Only HTTP & HTTPS allowed";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative No Protocol")
{
	string input = "www.example.com:80/path/";
	string expected = "Invalid Protocol. Only HTTP & HTTPS allowed";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative Protocol partly written")
{
	string input = "https:www.example.com:80/path/";
	string expected = "Document contains invalid characters. Valid characters are: A-Z a-z 0-9 . /";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative Domain Only First Level")
{
	string input = "https://com/path/";
	string expected = "Entered domain consist of only one top-level, it must have at least 2 levels";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative Domain First Level with dot")
{
	string input = "https://.com/path/";
	string expected = "Domain starts with invalid characters. Valid characters are: A-Z a-z 0-9";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative No Domain")
{
	string input = "https:///path/";
	string expected = "Domain empty";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative No Domain With Port")
{
	string input = "https://:85/path/";
	string expected = "Domain empty";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative Port Out Of Range")
{
	string input = "https://google.com:0";
	string expected = "Invalid Port. Must be between 1 and 65535";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative Port Out Of Range In Minus")
{
	string input = "https://google.com:-15";
	string expected = "Invalid Port. Must be between 1 and 65535";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}
TEST_CASE("Negative Document written with wrong characters")
{
	string input = "https://google.com/a*";
	string expected = "Document contains invalid characters. Valid characters are: A-Z a-z 0-9 . /";
	string actual = "";
	try
	{
		CHttpUrl url(input);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url(input);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}


TEST_CASE("Positive via parameters without port")
{
	string expected = "https://vk.com/oop.blog";
	string actual = "";
	try
	{
		CHttpUrl url("vk.com", "oop.blog", HTTPS);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url("vk.com", "oop.blog", HTTPS);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "vk.com");
		CHECK(url.GetPort() == 0);
		CHECK(url.GetDocument() == "/oop.blog");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive via parameters with port")
{
	string expected = "https://vk.com/oop.blog";
	string actual = "";
	try
	{
		CHttpUrl url("vk.com", "oop.blog", HTTPS, 443);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url("vk.com", "oop.blog", HTTPS, 443);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "vk.com");
		CHECK(url.GetPort() == 443);
		CHECK(url.GetDocument() == "/oop.blog");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive via parameters empty domain")
{
	string expected = "https:/oop.doc";
	string actual = "";
	try
	{
		CHttpUrl url("", "oop.doc", HTTPS);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url("", "oop.doc", HTTPS);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "");
		CHECK(url.GetPort() == 0);
		CHECK(url.GetDocument() == "/oop.doc");
	}
	CHECK(actual == expected);
}

TEST_CASE("Positive via parameters empty document")
{
	string expected = "https://google.com/";
	string actual = "";
	try
	{
		CHttpUrl url("google.com", "", HTTPS);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url("google.com", "", HTTPS);
		actual = url.GetURL();
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "google.com");
		CHECK(url.GetPort() == 0);
		CHECK(url.GetDocument() == "/");
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative via parameters bad document")
{
	string expected = "Document contains invalid characters. Valid characters are: A-Z a-z 0-9 . /";
	string actual = "";
	try
	{
		CHttpUrl url("google.com", "*", HTTPS);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url("google.com", "", HTTPS);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}

TEST_CASE("Negative via parameters bad domain")
{
	string expected = "Entered domain consist of only one top-level, it must have at least 2 levels";
	string actual = "";
	try
	{
		CHttpUrl url("google", "/home", HTTPS);
	}
	catch (const CUrlParsingError& error)
	{
		actual = error.what();
	}
	if (actual.empty())
	{
		CHttpUrl url("google.com", "", HTTPS);
		actual = url.GetURL();
	}
	CHECK(actual == expected);
}


