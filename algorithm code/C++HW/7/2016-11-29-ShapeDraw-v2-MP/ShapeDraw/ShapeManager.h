#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H

#include <vector>
#include <memory>
#include "WinShape.h"
using namespace std;
class ShapeManager
{
public:
	virtual ~ShapeManager();
	void add(std::shared_ptr<WinShape> shape); // shape �߰�
	std::shared_ptr<WinShape> get(int n); // return n��° Shape
	void draw(HDC hdc);
	WinShape* findShape(int x, int y);

protected:
	vector<shared_ptr<WinShape>> m_Shapes;
};
#endif