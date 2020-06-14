#include <iostream>
#include <string>
#include <map>
#include <fstream>

std::string HtmlDecode(std::string html, std::string symbolsFile);
int ReadMapFromFile(std::map<std::string, char>& mp, std::string filePos);