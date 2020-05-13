
#include <iostream>
#include <vector>
#include <algorithm>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "Vector.h"

using namespace std;

void ReadStreamAndPushToVector(istream& in, vector<float> &container)
{
    float nextNumber;
    while (in >> nextNumber)
    {
        container.push_back(nextNumber);
    }
}

void PrintVector(ostream& out, const vector<float>& container)
{
    for (float nextNumber : container)
    {
        out << nextNumber << ' ';
    }
    out << endl;
}

void SortVector(vector<float>& container)
{
    sort(container.begin(), container.end());
}

float MinElement(const vector<float>& container)
{
    float smallest = FLT_MAX;
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] < smallest)
        {
            smallest = container[i];
        }
    }
    return smallest;
}

void MultiplyEveryElementToNumber(vector<float>& container, float number)
{
    for (int i = 0; i < container.size(); i++)
    {
        container[i] *= number;
    }
}

void VectorSecondVariant()
{
    vector<float> container;
    ReadStreamAndPushToVector(cin, container);
    float smallestNum = MinElement(container);
    MultiplyEveryElementToNumber(container, smallestNum);
    SortVector(container);
    PrintVector(cout, container);
}
