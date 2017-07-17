#include <iostream>
#include "Rectangle.h"

namespace shapelib
{

	Rectangle::Rectangle() : Shape()
	{
	}

	Rectangle::Rectangle(int x, int y, int width, int height) : Shape(x, y)
	{
		m_Width = width;
		m_Height = height;
	}

	void Rectangle::draw() const
	{
		std::cout << "[Rectangle] Position = (" << m_X << ", " << m_Y
			<< ") Size = (" << m_Width << ", " << m_Height << ")\n";
	}

	void Rectangle::resize(int width, int height)
	{
		m_Width = width;
		m_Height = height;
	}

}