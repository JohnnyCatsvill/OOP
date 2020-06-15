#include "CGeometricFigures.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    CGeometricFigures figures;

    string line;
    while (!cin.eof())
    {
        figures.ReadFigure(cin);
    }

    cout << "���������� ������� ������" << endl;
    figures.GiveShapeInfo(figures.BiggestAreaFigure(), cout);
    cout << endl << endl;

    cout << "���������� �������� ������" << endl;
    figures.GiveShapeInfo(figures.SmallestPerimeterFigure(), cout);
    cout << endl;
}