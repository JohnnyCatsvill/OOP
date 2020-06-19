
#include <iostream>
#include <vector>

using namespace std;

template < typename T >
bool FindMax(std::vector<T> const& arr, T& maxValue)
{
    if(arr.empty())
    {
        return false;
    }
    else
    {
        T maxElement = arr.front();
        for (typename std::vector<T>::const_iterator it = arr.begin(); it != arr.end(); it++)
        {
            if (maxElement < *it)
            {
                maxElement = *it;
            }
        }
        maxValue = maxElement;
        return true;
    }
}

template <>
bool FindMax<const char*>(std::vector<const char*> const& arr, const char*& maxValue)
{
    if (arr.empty())
    {
        return false;
    }
    else
    {
        const char* maxElement = arr.front();
        for (typename std::vector<const char*>::const_iterator it = arr.begin(); it != arr.end(); it++)
        {
            if (strcmp(*it, maxElement) > 0)
            {
                maxElement = *it;
            }
        }
        maxValue = maxElement;
        return true;
    }
}


int main()
{
    {
        vector<int> intV = { 5, 9, 8, 6, 1 };
        vector<double> doubleV = { 5.005, 12.36, 11.11, 0.001, -15.0 };
        vector<string> strV = { "There", "it", "was", "word", "for", "word", "1" };
        vector<const char *> charV = { "There", "it", "was", "word", "for", "word", "1" };
        int maxInt;
        double maxDouble;
        string maxStr;
        const char* maxChar;
        cout << FindMax(intV, maxInt);
        cout << FindMax(doubleV, maxDouble);
        cout << FindMax(strV, maxStr);
        cout << FindMax(charV, maxChar);
        cout << endl;
        cout << "maxInt - " << maxInt << endl;
        cout << "maxDouble - " << maxDouble << endl;
        cout << "maxStr - " << maxStr << endl;
        cout << "maxChar* - " << maxChar << endl << endl;
    }

    {
        vector<int> emptyIntV = {};
        vector<double> emptyDoubleV = {};
        vector<string> emptyStrV = {};
        vector<const char*> emptyCharV = {};
        int maxInt = 1;
        double maxDouble = 1;
        string maxStr = "not changed";
        const char* maxChar = "not changed";
        cout << FindMax(emptyIntV, maxInt);
        cout << FindMax(emptyDoubleV, maxDouble);
        cout << FindMax(emptyStrV, maxStr);
        cout << FindMax(emptyCharV, maxChar);
        cout << endl;
        cout << "maxInt - " << maxInt << endl;
        cout << "maxDouble - " << maxDouble << endl;
        cout << "maxStr - " << maxStr << endl;
        cout << "maxChar* - " << maxChar << endl;
    }
}
