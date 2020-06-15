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

    cout << "Наибольшая площадь фигуры" << endl;
    figures.GiveShapeInfo(figures.BiggestAreaFigure(), cout);
    cout << endl << endl;

    cout << "Наименьший периметр фигуры" << endl;
    figures.GiveShapeInfo(figures.SmallestPerimeterFigure(), cout);
    cout << endl;
}