#include <iostream>
#include <string>
#include <fstream>
#include "MovieMedia.h"
#include "MovieMediaManager.h"
#include "Application.h"




// 방법 1
//class Application {
//public:
//	Application() { }
//
//	void exec() {
//		int menu = 0;
//		do {
//			menu = printAndGetMenu();
//			if (menu == 1) {
//				std::cout << "1번 메뉴 선택됨\n";
//			}
//			else if (menu == 2) {
//				std::cout << "2번 메뉴 선택됨\n";
//			}
//		} while (menu != 3);
//	}
//
//protected:
//	int printAndGetMenu() {
//		int menu;
//		std::cout << "1. 전체 리스트 출력\n";
//		std::cout << "2. 검색\n";
//		std::cout << "3. 종료\n";
//		std::cout << std::endl;
//		std::cout << "메뉴 번호 입력: ";
//
//		std::cin >> menu;
//		return menu;
//	}
//};

// 방법 2
//class Application {
//public:
//	Application() { }
//
//	void exec() {
//		int menu = 0;
//		while (menu != 3) {
//			menu = printAndGetMenu();
//			if (menu == 1) {
//				std::cout << "1번 메뉴 선택됨\n";
//			}
//			else if (menu == 2) {
//				std::cout << "2번 메뉴 선택됨\n";
//			}
//		}
//	}
//
//protected:
//	int printAndGetMenu() {
//		int menu;
//		std::cout << "1. 전체 리스트 출력\n";
//		std::cout << "2. 검색\n";
//		std::cout << "3. 종료\n";
//		std::cout << std::endl;
//		std::cout << "메뉴 번호 입력: ";
//
//		std::cin >> menu;
//		return menu;
//	}
//};

// 방법 3


int main()
{
	Application a;
	a.exec();
	return 0;
}