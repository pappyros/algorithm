#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

namespace shapelib
{
	class Circle : public Shape
	{
	public:
		Circle();
		Circle(int x, int y, int radius);

		void draw() const;
		void setRadius(int radius);

	protected:
		int m_Radius;
	};
}

#endif
