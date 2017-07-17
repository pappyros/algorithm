#ifndef WIN_PARALLELOGRAM_H
#define WIN_PARALLELOGRAM_H

#include "Rectangle.h"
#include "WinShape.h"

class WinParallelogram : public shapelib::Rectangle, public WinShape
{
public:
	WinParallelogram();
	WinParallelogram(int x1, int y1, int x2, int y2, int width, int height);

	virtual void draw(HDC hdc) const;
	virtual bool isInside(int x, int y) const;
	virtual void move(int x, int y);

protected:
	int X2, Y2;
};

#endif
