#ifndef WIN_RECTANGLE_H
#define WIN_RECTANGLE_H

#include "Rectangle.h"
#include "WinShape.h"

class WinRectangle : public shapelib::Rectangle, public WinShape
{
public:
	WinRectangle();
	WinRectangle(int x, int y, int width, int height);

	virtual void draw(HDC hdc) const;
	virtual bool isInside(int x, int y) const;
};


#endif