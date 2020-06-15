#include "CGeometricFigures.h"

using namespace std;

void CGeometricFigures::ReadLine(std::stringstream& input)
{
    CPoint start;
    CPoint end;
    uint32_t outlineColor;

    input >> start.x;
    input >> start.y;
    input >> end.x;
    input >> end.y;
    input >> hex >> outlineColor;

    shared_ptr<CLineSegment> line = make_shared<CLineSegment>(start, end, outlineColor);
    m_figures.push_back(line);
}

void CGeometricFigures::ReadCircle(std::stringstream& input)
{
    CPoint center;
    double radius;
    uint32_t outlineColor;
    uint32_t fillColor;

    input >> center.x;
    input >> center.y;
    input >> radius;
    input >> hex >> outlineColor;
    input >> hex >> fillColor;

    shared_ptr<CCircle> circle = make_shared<CCircle>(center, radius, outlineColor, fillColor);
    m_figures.push_back(circle);
}

void CGeometricFigures::ReadTriangle(std::stringstream& input)
{
    CPoint vertex1;
    CPoint vertex2;
    CPoint vertex3;
    uint32_t outlineColor;
    uint32_t fillColor;

    input >> vertex1.x;
    input >> vertex1.y;
    input >> vertex2.x;
    input >> vertex2.y;
    input >> vertex3.x;
    input >> vertex3.y;
    input >> hex >> outlineColor;
    input >> hex >> fillColor;

    shared_ptr<CTriangle> triangle = make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
    m_figures.push_back(triangle);
}

void CGeometricFigures::ReadRectangle(std::stringstream& input)
{
    CPoint leftTop;
    double width;
    double height;
    uint32_t outlineColor;
    uint32_t fillColor;

    input >> leftTop.x;
    input >> leftTop.y;
    input >> width;
    input >> height;
    input >> hex >> outlineColor;
    input >> hex >> fillColor;

    CPoint rightBottom(leftTop.x + width, leftTop.y + height);
    shared_ptr<CRectangle> rect = make_shared<CRectangle>(leftTop, rightBottom, outlineColor, fillColor);
    m_figures.push_back(rect);
}

void CGeometricFigures::ReadFigure(std::istream& input)
{
    string line;
    getline(input, line, '\n');
    stringstream ss(line);
    string word;
    ss >> word;

    if (!line.empty())
    {
        if (word == "rectangle")
        {
            ReadRectangle(ss);
        }
        else if (word == "triangle")
        {
            ReadTriangle(ss);
        }
        else if (word == "circle")
        {
            ReadCircle(ss);
        }
        else if (word == "line")
        {
            ReadLine(ss);
        }
    }
}

void CGeometricFigures::GiveShapeInfo(const shared_ptr<IShape> figure, std::ostream& out) const
{
    out << figure->ToString();
}

std::shared_ptr<IShape> CGeometricFigures::Begin() const
{
    return *m_figures.begin();
}

std::shared_ptr<IShape> CGeometricFigures::End() const
{
    return *m_figures.end();
}

bool CompareAreas(const shared_ptr<IShape> const first, const shared_ptr<IShape> const second)
{
    return(first->GetArea() <= second->GetArea());
}

bool ComparePerimeters(const shared_ptr<IShape> const first, const shared_ptr<IShape> const second)
{
    return(first->GetPerimeter() <= second->GetPerimeter());
}

shared_ptr<IShape> CGeometricFigures::BiggestAreaFigure()const
{
    auto it = max_element(m_figures.begin(), m_figures.end(), CompareAreas);
    return *it;
}

shared_ptr<IShape> CGeometricFigures::SmallestPerimeterFigure()const
{
    auto it = min_element(m_figures.begin(), m_figures.end(), ComparePerimeters);
    return *it;
}


