#include "HtmlDecodeProgramm.h"

const int MAX_ENCODED_SYMBOL_LENGTH = 32;

using namespace std;

int ReadMapFromFile(map<string, char> &mp, string filePos)
{
    string str;
    char ch;
    ifstream file(filePos);
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> str;
            file >> ch;
            mp.insert(pair<string, char>(str, ch));
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

string HtmlDecode(string html, string symbolsFile)
{
    string output;
    string encodedSymbol;
    bool inEncodedSymbol = false;
    int symbolLength = 0;

    static map<string, char> symbols;

    if (symbols.empty())
    {
        if (ReadMapFromFile(symbols, symbolsFile) == 1)
        {
            cout << "Missing map file";
            exit(1);
        }
    }

    for (char ch : html)
    {
        if (ch == '&') //Нашли составной символ
        {
            if (inEncodedSymbol)
            {
                output += '&';
                output += encodedSymbol;
            }
            inEncodedSymbol = true;
            symbolLength = 0;
            encodedSymbol.clear();
        }
        else if (ch == ';' && inEncodedSymbol) //Вышли из составного символа
        {
            if (symbols.find(encodedSymbol) != symbols.end())
            {
                output += symbols[encodedSymbol];
            }
            else
            {
                output += '&';
                output += encodedSymbol;
                output += ';';
            }
            inEncodedSymbol = false;
        }
        else if (inEncodedSymbol) //Сидим в составном символе
        {
            encodedSymbol += ch;
            symbolLength++;
            if (symbolLength > MAX_ENCODED_SYMBOL_LENGTH)
            {
                inEncodedSymbol = false;
                output += '&';
                output += encodedSymbol;
            }
        }
        else //Вне составного символа
        {
            output += ch;
        }
    }
    if (inEncodedSymbol) 
    {
        output += '&';
        output += encodedSymbol;
    }
    return output;
}
