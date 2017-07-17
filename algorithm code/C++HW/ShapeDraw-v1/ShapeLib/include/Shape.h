#ifndef SHAPE_H
#define SHAPE_H

namespace shapelib
{
	class Shape
	{
	public:
		Shape();
		Shape(int x, int y);

		virtual void move(int x, int y);
		virtual void draw() const;

	protected:
		int m_X, m_Y;
	};
}

#endif