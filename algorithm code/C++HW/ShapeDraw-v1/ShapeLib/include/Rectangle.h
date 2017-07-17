#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

namespace shapelib
{

	class Rectangle : public Shape
	{
	public:
		Rectangle();
		Rectangle(int x, int y, int width, int height);

		void draw() const;
		void resize(int width, int height);

	protected:
		int m_Width;
		int m_Height;
	};

}

#endif