#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
class DynamicArray
{
public:
	DynamicArray();
	//DynamicArray(int arraySize);
	DynamicArray(const DynamicArray& a);
	DynamicArray(int initialSize, int increaseSize);
	int at(int index)const;
	void push_back(int element);
	void erase(int index);
	void insert(int pos, int element);
	void result();
	int operator[](int idx)const;
	int& operator[](int idx);

	virtual ~DynamicArray();

	int Size()const;
	//int* getArrayPointer();

public:
	int* arr;
	int size;
	int current;
	int inc;
};

#endif