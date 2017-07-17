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
	// �������� �޸𸮸� �Ҵ��Ѵ�.
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
	// �޸𸮸� �����Ѵ�.
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