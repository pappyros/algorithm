#include <iostream>
#include "WinRectangle.h"

WinRectangle::WinRectangle() : shapelib::Rectangle()
{
}

WinRectangle::WinRectangle(int x, int y, int width, int height) 
    : shapelib::Rectangle(x, y, width, height)
{
}

void WinRectangle::draw(HDC hdc) const
{
	::Rectangle(hdc, m_X, m_Y, m_X + m_Width, m_Y + m_Height);
}

bool WinRectangle::isInside(int x, int y) const
{
	return (x >= m_X && x <= m_X + m_Width && y >= m_Y && y <= m_Y + m_Height);
}
