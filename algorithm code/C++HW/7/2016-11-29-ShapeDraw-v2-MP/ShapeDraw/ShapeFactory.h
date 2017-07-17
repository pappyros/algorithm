#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <string>
#include "WinRectangle.h"
#include "WinCircle.h"
using namespace std;
class ShapeFactory
{
public:
	static const int RECT_SIZE = 100;
	static const int CIRCLE_RADIUS = RECT_SIZE / 2;
	static shared_ptr<WinShape> create(const std::string& type, int x, int y) 
	{
		if (type == "Rectangle") {
			shared_ptr<WinShape> a(new WinRectangle(x, y, RECT_SIZE, RECT_SIZE));
				return a;
		}

		else if (type == "Circle") {
			shared_ptr<WinShape> a(new WinCircle(x, y, CIRCLE_RADIUS));
			return a;
		}
		
	}
};

#endif

