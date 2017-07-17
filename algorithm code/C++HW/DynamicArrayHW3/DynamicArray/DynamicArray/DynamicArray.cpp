#include "DynamicArray.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

DynamicArray::DynamicArray()
{
	arr = NULL;
	size = 0;
	std::cout << "default constructor called\n";
	current = 0;
}
/*
DynamicArray::DynamicArray(int arraySize)
{
	// 동적으로 메모리를 할당한다.
	arr = new int[arraySize];
	current = 0;
	size = arraySize;
	std::cout << "arraySize constructor called\n";
}*/

DynamicArray::DynamicArray(const DynamicArray& a)
{
	size = a.size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = a.arr[i];
	}
	current = a.current;
	cout << "arraySize constructor called" << endl;
}

DynamicArray::~DynamicArray()
{
	// 메모리를 해제한다.
	if (NULL != arr)
		delete[] arr;
	std::cout << "Destructor called\n";
}

int DynamicArray::Size()const
{
	return current;  
}
int& DynamicArray::operator[](int idx) {
	int q = 0;
	
	if (idx<current) {
		return arr[idx];
	}
	else {
		cout << "DynamicArray::at: Out of index" << endl;
		return q;
	}
	

}
DynamicArray::DynamicArray(int initialSize, int increaseSize=10) {
	size = initialSize;
	arr = new int[initialSize];
	inc = increaseSize;
	current = 0;
	cout << "arraySize constructor called" << endl;

}
int DynamicArray::at(int index)const {
	if (index<current) {
		return *(arr + index);
	}
	else {
		return 0;
	}
};
void DynamicArray::push_back(int element) {
	if (current + 1 <= size) {
		*(arr + current) = element;
		current++;

	}
	else {
		int *imsi = new int[size + inc];
		
		for (int i = 0; i <= size; i++) {
			imsi[i] = arr[i];
		}
		size = size + inc;
		arr = imsi;
		arr[current++] = element;


	}
};
int DynamicArray::operator[](int idx) const{
	if (idx<current) {
		
		return arr[idx];
	}
	else {
		return 0;
	}
	
};
void DynamicArray::erase(int index) {
	for (int i = index; i < size-1; i++) {
		arr[i] = arr[i + 1];
		
		
	}
	current--;

}
void DynamicArray::insert(int pos, int element) {
	if (current + 1 <= size) {

		for (int i = current; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos] = element;
		
		current++;

	}
	else {
		int *imsi = new int[size + inc];
		
		for (int i = 0; i <= size; i++) {
			imsi[i] = arr[i];
		}
		size = size + inc;
		for (int i = current; i > pos; i--) {
			imsi[i] = imsi[i - 1];
		}
		
		arr = imsi;

		arr[pos] = element;
		current++;


	}
	


}
void DynamicArray::result() {
	cout << endl;
	for (int i = 0; i < current; i++) {
		cout << arr[i] << endl;
	}
}


/*
int* DynamicArray::getArrayPointer()
{
	return arr;
}*/