
#include "GeometricFiguresTest.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

using namespace std;

void split(const string& s, char delim, vector<string>& elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
}

void ReadLine(vector<string>& elems, ShapeType& figures)
{
    CPoint start;
    CPoint end;
    uint32_t outlineColor;

    isNumber(elems[1]) ? start.x = stod(elems[1]) : start.x = 0;
    isNumber(elems[2]) ? start.y = stod(elems[2]) : start.y = 0;
    isNumber(elems[3]) ? end.x = stod(elems[3]) : end.x = 0;
    isNumber(elems[4]) ? end.y = stod(elems[4]) : end.y = 0;

    isHexNumber(elems[5]) ? outlineColor = hex2dec(elems[5]) : outlineColor = hex2dec("000000");

    CLineSegment* line = new CLineSegment(start, end, outlineColor);
    figures.push_back(line);
}

void ReadCircle(vector<string>& elems, ShapeType& figures)
{
    CPoint center;
    double radius;
    uint32_t outlineColor;
    uint32_t fillColor;

    isNumber(elems[1]) ? center.x = stod(elems[1]) : center.x = 0;
    isNumber(elems[2]) ? center.y = stod(elems[2]) : center.y = 0;
    isNumber(elems[3]) ? radius = stod(elems[3]) : radius = 0;

    isHexNumber(elems[4]) ? outlineColor = hex2dec(elems[4]) : outlineColor = hex2dec("000000");
    isHexNumber(elems[5]) ? fillColor = hex2dec(elems[5]) : fillColor = hex2dec("FFFFFF");

    CCircle* circle = new CCircle(center, radius, outlineColor, fillColor);
    figures.push_back(circle);
}

void ReadTriangle(vector<string>& elems, ShapeType& figures)
{
    CPoint vertex1;
    CPoint vertex2;
    CPoint vertex3;
    uint32_t outlineColor;
    uint32_t fillColor;

    isNumber(elems[1]) ? vertex1.x = stod(elems[1]) : vertex1.x = 0;
    isNumber(elems[2]) ? vertex1.y = stod(elems[2]) : vertex1.y = 0;
    isNumber(elems[3]) ? vertex2.x = stod(elems[3]) : vertex2.x = 0;
    isNumber(elems[4]) ? vertex2.y = stod(elems[4]) : vertex2.y = 0;
    isNumber(elems[5]) ? vertex3.x = stod(elems[5]) : vertex3.x = 0;
    isNumber(elems[6]) ? vertex3.y = stod(elems[6]) : vertex3.y = 0;

    isHexNumber(elems[7]) ? outlineColor = hex2dec(elems[7]) : outlineColor = hex2dec("000000");
    isHexNumber(elems[8]) ? fillColor = hex2dec(elems[8]) : fillColor = hex2dec("FFFFFF");

    CTriangle* triangle = new CTriangle(vertex1, vertex2, vertex3, outlineColor, fillColor);
    figures.push_back(triangle);
}

void ReadRectangle(vector<string>& elems, ShapeType& figures)
{
    CPoint leftTop;
    double width;
    double height;
    uint32_t outlineColor;
    uint32_t fillColor;

    isNumber(elems[1]) ? leftTop.x = stod(elems[1]) : leftTop.x = 0;
    isNumber(elems[2]) ? leftTop.y = stod(elems[2]) : leftTop.y = 0;
    isNumber(elems[3]) ? width = stod(elems[3]) : width = 0;
    isNumber(elems[4]) ? height = stod(elems[4]) : height = 0;

    isHexNumber(elems[5]) ? outlineColor = hex2dec(elems[5]) : outlineColor = hex2dec("000000");
    isHexNumber(elems[6]) ? fillColor = hex2dec(elems[6]) : fillColor = hex2dec("FFFFFF");

    CPoint rightBottom(leftTop.x + width, leftTop.y + height);
    CRectangle* rect = new CRectangle(leftTop, rightBottom, outlineColor, fillColor);
    figures.push_back(rect);
}

int BiggestAreaIndex(ShapeType& figures)
{
    int index = 0;
    double area = 0;
    int i = 0;
    for (IShape* obj : figures)
    {
        double nextArea = obj->GetArea();
        if (area < nextArea)
        {
            area = nextArea;
            index = i;
        }
        i++;
    }
    return index;
}

int SmallestPerimeterIndex(ShapeType& figures)
{
    int index = 0;
    double perimeter = figures[0]->GetPerimeter();
    int i = 0;
    for (IShape* obj : figures)
    {
        double nextPerimeter = obj->GetPerimeter();
        if (perimeter > nextPerimeter)
        {
            perimeter = nextPerimeter;
            index = i;
        }
        i++;
    }
    return index;
}

void GiveShapeInfo(IShape& figure)
{
    IShape* elem = &figure;
    cout << elem->ToString() << endl;
    cout << "Её площадь - " << elem->GetArea() << ", и периметр - " << elem->GetPerimeter() << endl;
    cout << "Цвет её обводки - " << dec2hex(elem->GetOutlineColor());

    ISolidShape* child = dynamic_cast<ISolidShape*>(elem);
    if (child)
    {
        cout << " a, цвет её заливки - " << dec2hex(child->GetFillColor()) << endl;
    }
    else
    {
        cout << endl;
    }
}

