#include <iostream>
#include "WinCircle.h"

WinCircle::WinCircle() : shapelib::Circle()
{
}

WinCircle::WinCircle(int x, int y, int radius)
    : shapelib::Circle(x, y, radius)
{
	m_Radius = radius;
}

void WinCircle::draw(HDC hdc) const
{
	Ellipse(hdc, m_X - m_Radius, m_Y - m_Radius, m_X + m_Radius, m_Y + m_Radius);
}

bool WinCircle::isInside(int x, int y) const
{
	int newX = x - m_X;
	int newY = y - m_Y;
	return ((newX * newX + newY * newY) <= (m_Radius * m_Radius));
}
