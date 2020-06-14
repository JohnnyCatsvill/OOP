#include "HtmlDecodeProgramm.h"

using namespace std;

int main()
{
    string input;
    string output;

    while (getline(cin, input))
    {
        output = HtmlDecode(input, "SymbolsMap.txt");
        cout << output << endl;
    }
}