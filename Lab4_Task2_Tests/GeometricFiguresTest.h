#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CPoint.h"
#include "CTriangle.h"

typedef vector<IShape*> ShapeType;

void split(const string& s, char delim, vector<string>& elems);
void ReadLine(vector<string>& elems, ShapeType& figures);
void ReadCircle(vector<string>& elems, ShapeType& figures);
void ReadTriangle(vector<string>& elems, ShapeType& figures);
void ReadRectangle(vector<string>& elems, ShapeType& figures);
int BiggestAreaIndex(ShapeType& figures);
int SmallestPerimeterIndex(ShapeType& figures);
void GiveShapeInfo(IShape& figure);