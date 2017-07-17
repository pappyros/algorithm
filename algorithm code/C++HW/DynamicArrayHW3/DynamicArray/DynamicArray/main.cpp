#include "DynamicArray.h"
#include <iostream>

using namespace std;
void printAll(const DynamicArray& da, bool useAtFunc = false)
{
	if (useAtFunc) {
		for (int i = 0; i < da.Size(); i++)
			std::cout << da.at(i) << " ";
	}
	else {
		for (int i = 0; i < da.Size(); i++)
			std::cout << da[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	// 필요한 만큼의 메모리를 준비한다.
	DynamicArray da(3, 2);

	std::cout << "test push_back" << std::endl;
	for (int i = 0; i < 4; i++) // add 0, 1, 2, 3
		da.push_back(i);
	for (int i = 8; i < 10; i++) // add 8, 9
		da.push_back(i);

	std::cout << "test size: 6이 출력되어야 함" << std::endl;
	std::cout << "size = " << da.Size() << std::endl;

	std::cout << "test insert" << std::endl;
	for (int i = 4; i < 8; i++)  // insert 4, 5, 6, 7
		da.insert(i, i);

	std::cout << "test size: 10이 출력되어야 함" << std::endl;
	std::cout << "size = " << da.Size() << std::endl;

	std::cout << "test at" << std::endl;
	std::cout << "0부터 9까지 순서대로 출력되어야 함" << std::endl;
	for (int i = 0; i < da.Size(); i++)
		std::cout << da.at(i) << " ";
	std::cout << std::endl;

	std::cout << "test at (out of range)" << std::endl;
	std::cout << "0이 출력되면 됨" << std::endl;
	std::cout << da.at(13) << " " << std::endl;

	std::cout << "test operator[]" << std::endl;
	std::cout << "0부터 9까지 순서대로 출력되어야 함" << std::endl;
	printAll(da);

	std::cout << "test & operator[]" << std::endl;
	std::cout << "5부터 14까지 순서대로 출력되어야 함" << std::endl;
	for (int i = 0; i < da.Size(); i++)
		da[i] += 5;
	printAll(da);

	std::cout << "test operator[] (out of range)" << std::endl;
	std::cout << "0이 출력되면 됨" << std::endl;
	std::cout << da[13] << " " << std::endl;

	std::cout << "test erase" << std::endl;
	std::cout << "8, 11을 제외하고 5부터 14까지 순서대로 출력되어야 함" << std::endl;
	da.erase(3);
	da.erase(5);
	printAll(da);
	

	std::cout << "test size: 8이 출력되어야 함" << std::endl;
	std::cout << "size = " << da.Size() << std::endl;

	std::cout << "test [] (out of range)" << std::endl;
	std::cout << "0이 출력되면 됨" << std::endl;
	std::cout << da[da.Size()] << std::endl;  // out of range. 0이 출력됨
	return 0;
}
