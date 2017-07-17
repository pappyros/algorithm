#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H

#include <vector>
#include "WinShape.h"

class ShapeManager
{
public:
	virtual ~ShapeManager();
	void add(WinShape* shape); // shape �߰�
	WinShape* get(int n); // return n��° Shape
	void draw(HDC hdc);

protected:
	std::vector<WinShape*> m_Shapes;
};

#endif