#include "DynamicArray.h"
#include <iostream>

template <typename T>
void printAll(const DynamicArray<T>& da, bool useAtFunc = false)
{
	if (useAtFunc) {
		for (int i = 0; i < da.size(); i++)
			std::cout << da.at(i) << " ";
	}
	else {
		for (int i = 0; i < da.size(); i++)
			std::cout << da[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	// �ʿ��� ��ŭ�� �޸𸮸� �غ��Ѵ�.
	DynamicArray<double> da(3, 2);
	da.push_back(3);
	
	da.erase(10);
	
	//da.insert(0, 1);
	//std::cout << "test push_back" << std::endl;
	//for (int i = 0; i < 4; i++) // add 0, 1, 2, 3
	//    da.push_back(i);
	//for (int i = 8; i < 10; i++) // add 8, 9
	//	da.push_back(i);

	//std::cout << "test size: 6�� ��µǾ�� ��" << std::endl;
	//std::cout << "size = " << da.size() << std::endl;

	//printAll(da);

	//std::cout << "test insert" << std::endl;
	//for (int i = 4; i < 8; i++)  // insert 4, 5, 6, 7
	//	da.insert(i, i);

	//std::cout << "test size: 10�� ��µǾ�� ��" << std::endl;
	//std::cout << "size = " << da.size() << std::endl;
	//printAll(da);

	//std::cout << "test at" << std::endl;
	//std::cout << "0���� 9���� ������� ��µǾ�� ��" << std::endl;
	//for (int i = 0; i < da.size(); i++)
	//	std::cout << da.at(i) << " ";
	//std::cout << std::endl;

	//std::cout << "test at (out of range)" << std::endl;
	//std::cout << "0�� ��µǸ� ��" << std::endl;
	//std::cout << da.at(13) << " " << std::endl;

	//std::cout << "test operator[]" << std::endl;
	//std::cout << "0���� 9���� ������� ��µǾ�� ��" << std::endl;
	//printAll(da);

	//std::cout << "test & operator[]" << std::endl;
	//std::cout << "5���� 14���� ������� ��µǾ�� ��" << std::endl;
	//for (int i = 0; i < da.size(); i++) 
	//	da[i] += 5;
	//printAll(da);

	//std::cout << "test operator[] (out of range)" << std::endl;
	//std::cout << "0�� ��µǸ� ��" << std::endl;
	//std::cout << da[13] << " " << std::endl;

	//std::cout << "test erase" << std::endl;
	//std::cout << "8, 11�� �����ϰ� 5���� 14���� ������� ��µǾ�� ��" << std::endl;
	//da.erase(3);
	//da.erase(5);
	//printAll(da);

	//std::cout << "test size: 8�� ��µǾ�� ��" << std::endl;
	//std::cout << "size = " << da.size() << std::endl;

	//std::cout << "test [] (out of range)" << std::endl;
	//std::cout << "0�� ��µǸ� ��" << std::endl;
	//std::cout << da[da.size()] << std::endl;  // out of range. 0�� ��µ�
	return 0;
}
