#include <iostream>
#include "Circle.h"

namespace shapelib
{

Circle::Circle() : Shape()
{
}

Circle::Circle(int x, int y, int radius) : Shape(x, y)
{
	m_Radius = radius;
}

void Circle::draw() const
{
	std::cout << "[Circle] Position = (" << m_X << ", " << m_Y
		<< ") Radius = " << m_Radius << "\n";

}
void Circle::setRadius(int radius)
{
	m_Radius = radius;
}

}
