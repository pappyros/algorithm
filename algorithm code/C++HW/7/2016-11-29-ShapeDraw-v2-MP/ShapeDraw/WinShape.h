#ifndef WIN_SHAPE_H
#define WIN_SHAPE_H

#include <Windows.h>

class WinShape
{
public:
	virtual ~WinShape() {}
	virtual void draw(HDC hdc) const = 0;
	virtual bool isInside(int x, int y) const = 0;
};

#endif