#include"Application.h"
#include<string>
#include<iostream>


Application::Application()
{
	m_MovieMediaManager.load();
}
void Application::exec() {
	int menu = 0;
	while (true) {
		menu = printAndGetMenu();
		if (menu == 1) {
			m_MovieMediaManager.printAllMovieMedias();
		}
		else if (menu == 2) {
			std::string s;
			std::cout << "검색할 문자열을 입력하세요:";
			getline(std::cin, s);
			getline(std::cin, s);
			m_MovieMediaManager.search(s);
		}
		else if (menu == 3) {
			break; // 또는 return ;
		}
	}
}



int Application::printAndGetMenu() {
	int menu;
	std::cout << "1. 전체 리스트 출력\n";
	std::cout << "2. 검색\n";
	std::cout << "3. 종료\n";
	std::cout << std::endl;
	std::cout << "메뉴 번호 입력: ";

	std::cin >> menu;
	std::cout << std::endl;
	return menu;
}