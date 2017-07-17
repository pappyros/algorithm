#include "ShapeManager.h"

ShapeManager::~ShapeManager()
{

}

void ShapeManager::add(WinShape* s)
{
	m_Shapes.push_back(s);
}

WinShape* ShapeManager::get(int index) 
{
	return m_Shapes[index];
}

void ShapeManager::draw(HDC hdc) 
{
	for (int i = 0; i < m_Shapes.size(); i++) {
		m_Shapes[i]->draw(hdc);
	}
}
