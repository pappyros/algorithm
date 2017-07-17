#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include "MovieMedia.h"
#include <stdlib.h>
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(int arraySize);
	DynamicArray(const DynamicArray& a);
	virtual ~DynamicArray();

	int getSize();
	int* getArrayPointer();


	MovieMedia* arr;
	int size;
};

#endif