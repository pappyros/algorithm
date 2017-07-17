#include "ShapeManager.h"
#include "WinCircle.h"
using namespace std;
ShapeManager::~ShapeManager()
{
}

void ShapeManager::add(shared_ptr<WinShape> s)
{
	m_Shapes.push_back(s);
}

shared_ptr<WinShape> ShapeManager::get(int index)
{
	return m_Shapes.at(index);
}

void ShapeManager::draw(HDC hdc) 
{
	std::vector<shared_ptr<WinShape>>::iterator s;
	for (s = m_Shapes.begin(); s!= m_Shapes.end(); s++) 
	{
		(*s)->draw(hdc);
	}
	


	


}

WinShape* ShapeManager::findShape(int x, int y)
{
	
	for (auto i = m_Shapes.rbegin(); i != m_Shapes.rend(); i++) {
		if ((*i)->isInside(x,y)) 
		{
			return (*i).get();
		}

	}
		
	
}