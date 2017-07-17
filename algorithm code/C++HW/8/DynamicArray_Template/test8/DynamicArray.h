#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include "IndexOutOfRangeException.h"


class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(int arraySize, int increaseSize);
	DynamicArray(const DynamicArray& a);
	virtual ~DynamicArray();

	int size() const;

	void push_back(T element);
	T at(int index) const;
	void erase(int index);
	void insert(int pos, T element);
	T operator[](int index) const;
	T& operator[](int index);

private:
	T* m_Arr;
	int m_CurrentIndex;
	int m_IncreaseSize;
	int m_BufferSize;
	T m_Error;
	void resizeArray();
};

template <typename T>
DynamicArray<T>::DynamicArray()
{
	m_Arr = NULL;
	m_CurrentIndex = 0;
	m_IncreaseSize = 0;
	m_BufferSize = 0;
	m_Error = 0;
	std::cout << "default constructor called\n";
}

template <typename T>
DynamicArray<T>::DynamicArray(int arraySize, int increaseSize)
{
	// 동적으로 메모리를 할당한다.
	m_Arr = new T[arraySize];
	m_BufferSize = arraySize;
	m_CurrentIndex = 0;
	m_Error = 0;
	m_IncreaseSize = increaseSize;
	std::cout << "DynamicArray constructor called\n";
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& a)
{
	m_BufferSize = a.m_BufferSize;
	m_CurrentIndex = a.m_CurrentIndex;
	m_IncreaseSize = a.m_IncreaseSize;
	m_Error = a.m_Error;
	m_Arr = new T[m_BufferSize];
	memcpy(m_Arr, a.m_Arr, a.m_CurrentIndex * sizeof(T));
	//for (int i = 0; i < m_CurrentIndex; i++) {
	//	m_Arr[i] = a.m_Arr[i];
	//}
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	// 메모리를 해제한다.
	if (NULL != m_Arr)
		delete[] m_Arr;
	std::cout << "Destructor called\n";
}

template <typename T>
int DynamicArray<T>::size() const
{
	return m_CurrentIndex;
}

template <typename T>
void DynamicArray<T>::push_back(T element)
{
	if (m_CurrentIndex == m_BufferSize) {
		resizeArray();
	}
	m_Arr[m_CurrentIndex] = element;
	m_CurrentIndex++;
}

template <typename T>
void DynamicArray<T>::resizeArray()
{
	T* temp = new T[m_BufferSize + m_IncreaseSize];
	for (int i = 0; i < m_BufferSize; i++) {
		temp[i] = m_Arr[i];
	}
	delete[] m_Arr;
	m_Arr = temp;
	m_BufferSize += m_IncreaseSize;
}

template <typename T>
T DynamicArray<T>::at(int index) const
{
	try {
		if (index < 0 || index >= m_CurrentIndex) {
			IndexOutOfRangeException ie(index);
			throw ie
		}
		else
			return m_Arr[index];
	}
	catch (IndexOutOfRangeException ie) {
		ie.print();
		
	}
}

template <typename T>
T DynamicArray<T>::operator[](int index) const
{
	return at(index);
}

template <typename T>
T& DynamicArray<T>::operator[](int index)

try {
	if (index < 0 || index >= m_CurrentIndex) {
		IndexOutOfRangeException ie(index);
		throw ie

	}
	else
		return m_Arr[index];
}
catch(IndexOutOfRangeException ie){
	ie.print();
}

template <typename T>
void DynamicArray<T>::insert(int pos, T element)
{
	try {
		if (size() > 0 && pos >= 0 && pos < m_CurrentIndex) {
			if (m_CurrentIndex == m_BufferSize) {
				resizeArray();
			}
			for (int i = m_CurrentIndex - 1; i >= pos; i--) {
				m_Arr[i + 1] = m_Arr[i];
			}
			m_Arr[pos] = element;
			m_CurrentIndex++;
		}
		else {
			IndexOutOfRangeException ie(pos);
			throw ie;

		}
	}
	catch (IndexOutOfRangeException ie) {
		ie.print();

	}
}

template <typename T>
void DynamicArray<T>::erase(int pos)
{
	if (size() > 0 && pos >= 0 && pos < m_CurrentIndex) {
		for (int i = pos + 1; i < m_CurrentIndex; i++) {
			m_Arr[i - 1] = m_Arr[i];
		}
		m_CurrentIndex--;
	}
	else {
		IndexOutOfRangeException ie(pos);
		cout << ie;
	}
}

#endif