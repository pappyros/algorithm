#ifndef WIN_CIRCLE_H
#define WIN_CIRCLE_H

#include "circle.h"
#include "WinShape.h"

class WinCircle : public shapelib::Circle, public WinShape
{
public:
	WinCircle();
	WinCircle(int x, int y, int radius);

	virtual void draw(HDC hdc) const;
	virtual bool isInside(int x, int y) const;
};

#endif
