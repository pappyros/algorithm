#ifndef NEW_SHAPE_FACTORY_H
#define NEW_SHAPE_FACTORY_H

#include "ShapeFactory.h"

class NewShapeFactory : public ShapeFactory
{
public:
	static WinShape* create(const std::string& type, int x, int y) {
		WinShape* s = ShapeFactory::create(type, x, y);
		if (type == "Parallelogram") {
			return new WinRectangle(x, y, 100, 100);
		}
		else if (type == "Trapezoid") {
			return new WinCircle(x, y, 50);
		}
		return NULL;
	}
};

#endif
