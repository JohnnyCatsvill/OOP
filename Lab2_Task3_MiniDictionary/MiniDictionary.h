#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

const int DICTIONARY_OPENED = 0;
const int DICTIONARY_NOT_FOUND = 1;
const int DICTIONARY_UNDEFINED = 2;

const int TRANSLATION_WAS_FOUND = 3;
const int NO_TRANSLATION_FOUND = 4;
const int TRANSLATION_WAS_ADDED = 5;
const int TRANSLATION_WAS_NOT_ADDED = 6;

const int LINE_EMPTY = 7;
const int LINE_GIVEN = 8;

int WriteMap(const std::string& filePosition, const std::map<std::string, std::string>& dict);
int ReadMap(const std::string& filePosition, std::map<std::string, std::string>& dict);

int GetTranslation(const std::string& word, std::string& translation, std::map<std::string, std::string>& dict);
int AddTranslation(const std::string& word, const std::string& translation, std::map<std::string, std::string>& dict);

void MiniDictionary(std::istream& in, std::ostream& out);
