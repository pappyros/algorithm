#include "DynamicArray.h"
#include <stdlib.h>
#include <iostream>

DynamicArray::DynamicArray()
{
	arr = NULL;
	size = 0;
	std::cout << "default constructor called\n";
}

DynamicArray::DynamicArray(int arraySize)
{
	// 동적으로 메모리를 할당한다.
	arr = new MovieMedia[arraySize];
	size = arraySize;
	std::cout << "arraySize constructor called\n";
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
	size = a.size;
	arr = new MovieMedia[size];
	for (int i = 0; i < size; i++) {
		arr[i] = a.arr[i];
	}
}

DynamicArray::~DynamicArray()
{
	// 메모리를 해제한다.
	if (NULL != arr)
		delete[] arr;
	std::cout << "Destructor called\n";
}

int DynamicArray::getSize()
{
	return size;
}

int* DynamicArray::getArrayPointer()
{
	return 0;
}