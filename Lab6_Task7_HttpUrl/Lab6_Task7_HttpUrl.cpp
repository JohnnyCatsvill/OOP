#include <iostream>
#include "CHttpUrl.h"

using namespace std;
int main()
{
	string line;
	while (getline(cin, line))
	{
		try
		{
			CHttpUrl url(line);
		}
		catch (const CUrlParsingError& error)
		{
			std::cout << error.what() << endl;
			continue;
		}
		CHttpUrl url(line);
		cout << "-> " << url.GetURL() << endl;
	}
}
