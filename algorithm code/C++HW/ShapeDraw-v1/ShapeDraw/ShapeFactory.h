#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <string>
#include "WinRectangle.h"
#include "WinCircle.h"

class ShapeFactory
{
public:
	static WinShape* create(const std::string& type, int x, int y) {
		if (type == "Rectangle") {
			return new WinRectangle(x, y, 100, 100);
		}
		else if (type == "Circle") {
			return new WinCircle(x, y, 50);
		}
		else
			return NULL;
	}
};

#endif

