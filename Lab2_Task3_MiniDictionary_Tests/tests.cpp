#define CATCH_CONFIG_MAIN 
#include "../Lab2_Task3_MiniDictionary/MiniDictionary.h"
#include "catch2/catch.hpp"
#include <sstream>

using namespace std;

TEST_CASE("GetTranslation should give translation to word")
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	map<string, string> dict;
	dict.insert(pair<string, string>("apple", "яблоко"));

	string expected = "яблоко";
	string actual;

	GetTranslation("apple", actual, dict);

	CHECK(expected == actual);
}

TEST_CASE("AddTranslation should add translation to word")
{
	map<string, string> dict;
	AddTranslation("apple", "яблоко", dict);

	string expected = "яблоко";
	string actual;

	GetTranslation("apple", actual, dict);

	CHECK(expected == actual);
}

TEST_CASE("ReadMap should take all words to map")
{
	map<string, string> dict;
	string actual;
	
	ReadMap("slovar.txt", dict);

	GetTranslation("apple", actual, dict);
	CHECK("яблоко" == actual);

	GetTranslation("the Red Square", actual, dict);
	CHECK("Красная Площадь" == actual);
}

TEST_CASE("WriteMap should take all words to map")
{
	map<string, string> dict;
	map<string, string> dict2;
	string actual;

	AddTranslation("apple", "яблоко", dict);
	AddTranslation("ball", "мяч", dict);
	AddTranslation("banana", "банан", dict);
	AddTranslation("cat", "кот, кошка", dict);
	AddTranslation("lemon", "лимон", dict);

	WriteMap("slovar2.txt", dict);
	ReadMap("slovar2.txt", dict2);
	
	GetTranslation("apple", actual, dict);
	CHECK("яблоко" == actual);

	GetTranslation("lemon", actual, dict);
	CHECK("лимон" == actual);

	remove("slovar2.txt");
}

TEST_CASE("GetTranslation should give answers no matter to lower/uppercase")
{
	map<string, string> dict;
	AddTranslation("яблоко", "apple", dict);
	AddTranslation("Красная Площадь", "the Red Square", dict);

	string actual;

	GetTranslation("ЯблоКО", actual, dict);
	CHECK("apple" == actual);

	GetTranslation("кРАСНАЯ пЛОЩАДЬ", actual, dict);
	CHECK("the Red Square" == actual);
}

TEST_CASE("AddTranslation should add word no matter to lower/uppercase but translation should matter")
{
	map<string, string> dict;
	AddTranslation("ЯблОКО", "apple", dict);
	AddTranslation("КрАСНая ПлОЩадЬ", "the Red Square", dict);

	string actual;

	GetTranslation("яблоко", actual, dict);
	CHECK("apple" == actual);

	GetTranslation("красная площадь", actual, dict);
	CHECK("the Red Square" == actual);
}
