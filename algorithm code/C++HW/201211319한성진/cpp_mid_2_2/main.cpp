#include "DynamicArray.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	
	ifstream in("MovieMedia.data");
	std::string linestr;
	getline(in, linestr);
	DynamicArray da(atoi(linestr.c_str()));
	
	
	for (int i = 0; i < da.size; i++) {
		getline(in, linestr);
		da.arr[i].setType(linestr);
		getline(in, linestr);
		da.arr[i].setTitle(linestr);
		getline(in, linestr);
		da.arr[i].setKoreanTitle(linestr);
		getline(in, linestr);
		da.arr[i].setDirector(linestr);
		getline(in, linestr);
		da.arr[i].setActors(linestr);
		getline(in, linestr);
		da.arr[i].setYear(atoi(linestr.c_str()));
		getline(in, linestr);
		da.arr[i].setSubtitle(linestr);
		getline(in, linestr);
		da.arr[i].setFileName(linestr);
		getline(in, linestr);
		da.arr[i].setResolution(linestr);
	}

	for (int i = 0; i < da.size; i++){
		std::cout << da.arr[i].getType() << std::endl;
		std::cout << da.arr[i].getTitle() << std::endl;
		std::cout << da.arr[i].getKoreanTitle() << std::endl;
		std::cout << da.arr[i].getDirector() << std::endl;
		std::cout << da.arr[i].getActors() << std::endl;
		std::cout << da.arr[i].getYear() << "\n\n";
		std::cout << da.arr[i].getSubtitle() << std::endl;
		std::cout << da.arr[i].getFileName() << std::endl;
		std::cout << da.arr[i].getResolution() << std::endl;
	}
	

	
}
