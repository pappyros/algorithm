#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H

#include <vector>
#include "WinShape.h"

class ShapeManager
{
public:
	virtual ~ShapeManager();
	void add(WinShape* shape); // shape 추가
	WinShape* get(int n); // return n번째 Shape
	void draw(HDC hdc);

protected:
	std::vector<WinShape*> m_Shapes;
};

#endif