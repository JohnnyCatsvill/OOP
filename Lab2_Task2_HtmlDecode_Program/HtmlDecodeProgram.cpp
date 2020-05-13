
#include <iostream>
#include <string>

using namespace std;

char TranslateSpecialSymbol(const string& specialSymbol)
{
    if (specialSymbol == "quot")
    {
        return '"';
    }
    else if (specialSymbol == "apos")
    {
        return '\'';
    }
    else if (specialSymbol == "lt")
    {
        return '<';
    }
    else if (specialSymbol == "gt")
    {
        return '>';
    }
    else if (specialSymbol == "amp")
    {
        return '&';
    }
    else
    {
        return 'n';
    }
}

const int MAX_ENCODED_SYMBOL_LENGTH = 32;

string HtmlDecode(string const& html)
{
    string output;
    string encodedSymbol;
    bool inEncodedSymbol = false;
    int symbolLength = 0;

    for (char ch : html)
    {
        if (ch == '&') //Нашли составной символ
        {
            inEncodedSymbol = true;
            symbolLength = 0;
            encodedSymbol.clear();
        }
        else if (ch == ';' && inEncodedSymbol) //Вышли из составного символа
        {
            char translatedSymbol = TranslateSpecialSymbol(encodedSymbol);
            if (translatedSymbol != 'n')
            {
                output += translatedSymbol;
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
            }
        }
        else //Вне составного символа
        {
            output += ch;
        }
    }
    return output;
}


#include <iostream>

int main()
{
    string input;
    string output;

    while (getline(cin, input))
    {
        output = HtmlDecode(input);
        cout << output << endl;
    }
}
