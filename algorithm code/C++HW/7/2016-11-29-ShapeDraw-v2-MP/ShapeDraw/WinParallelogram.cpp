#include <iostream>
#include "WinRectangle.h"
#include "WinParallelogram.h"

WinParallelogram::WinParallelogram() : shapelib::Rectangle()
{
	X2 = 0;
	Y2 = 0;
}

WinParallelogram::WinParallelogram(int x1, int y1, int x2, int y2, int width, int height) : shapelib::Rectangle(x1, y1, width, height)
{
	X2 = x2;
	Y2 = y2;
}

void WinParallelogram::draw(HDC hdc) const
{
	MoveToEx(hdc, m_X, m_Y, NULL);
	LineTo(hdc, m_X+m_Width, m_Y);
	LineTo(hdc, X2, Y2);
	LineTo(hdc, X2- m_Width,Y2);
	LineTo(hdc, m_X, m_Y);
}

bool WinParallelogram::isInside(int x, int y) const
{
	
	
	return (x >= m_X && x <= m_X + m_Width && y >= m_Y && y <= m_Y + m_Height);
}

void WinParallelogram::move(int x, int y)
{
	shapelib::Shape::move(x, y);
	X2 += x;
	Y2 += y;
}

