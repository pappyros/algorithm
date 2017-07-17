#ifndef NEW_SHAPE_FACTORY_H
#define NEW_SHAPE_FACTORY_H
#include "WinParallelogram.h"
#include "ShapeFactory.h"
using namespace std;
class NewShapeFactory : public ShapeFactory
{
public:
	static shared_ptr<WinShape> create(const std::string& type, int x, int y) 
	{
		
		if (type == "Parallelogram") { 

			shared_ptr<WinShape> a(new WinParallelogram(x, y, x+80, y+100, RECT_SIZE, RECT_SIZE));
			return a;
		}
		else {
			shared_ptr<WinShape> a(ShapeFactory::create(type, x, y));
			return a;

		}
		
	}
};

#endif
