#include <iostream>
#include <string>
#include <fstream>
#include "MovieMedia.h"
#include "MovieMediaManager.h"
#include "Application.h"




// ��� 1
//class Application {
//public:
//	Application() { }
//
//	void exec() {
//		int menu = 0;
//		do {
//			menu = printAndGetMenu();
//			if (menu == 1) {
//				std::cout << "1�� �޴� ���õ�\n";
//			}
//			else if (menu == 2) {
//				std::cout << "2�� �޴� ���õ�\n";
//			}
//		} while (menu != 3);
//	}
//
//protected:
//	int printAndGetMenu() {
//		int menu;
//		std::cout << "1. ��ü ����Ʈ ���\n";
//		std::cout << "2. �˻�\n";
//		std::cout << "3. ����\n";
//		std::cout << std::endl;
//		std::cout << "�޴� ��ȣ �Է�: ";
//
//		std::cin >> menu;
//		return menu;
//	}
//};

// ��� 2
//class Application {
//public:
//	Application() { }
//
//	void exec() {
//		int menu = 0;
//		while (menu != 3) {
//			menu = printAndGetMenu();
//			if (menu == 1) {
//				std::cout << "1�� �޴� ���õ�\n";
//			}
//			else if (menu == 2) {
//				std::cout << "2�� �޴� ���õ�\n";
//			}
//		}
//	}
//
//protected:
//	int printAndGetMenu() {
//		int menu;
//		std::cout << "1. ��ü ����Ʈ ���\n";
//		std::cout << "2. �˻�\n";
//		std::cout << "3. ����\n";
//		std::cout << std::endl;
//		std::cout << "�޴� ��ȣ �Է�: ";
//
//		std::cin >> menu;
//		return menu;
//	}
//};

// ��� 3


int main()
{
	Application a;
	a.exec();
	return 0;
}