#include <iostream>
#include "Shape.h"

namespace shapelib
{

	Shape::Shape()
	{
		m_X = 0;
		m_Y = 0;
	}

	Shape::Shape(int x, int y)
	{
		m_X = x;
		m_Y = y;
	}

	void Shape::move(int x, int y)
	{
		m_X += x;
		m_Y += y;
	}

	void Shape::draw() const
	{
		std::cout << "[Shape] Position = (" << m_X << ", " << m_Y << ")\n";
	}
}