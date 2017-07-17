#pragma once
#ifndef application
#define application

#include"MovieMediaManager.h"
class Application {
public:
	Application();
	
	void exec();

protected:
	int printAndGetMenu();

	MovieMediaManager m_MovieMediaManager;
};
#endif