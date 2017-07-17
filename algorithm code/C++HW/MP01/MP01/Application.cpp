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
			std::cout << "�˻��� ���ڿ��� �Է��ϼ���:";
			getline(std::cin, s);
			getline(std::cin, s);
			m_MovieMediaManager.search(s);
		}
		else if (menu == 3) {
			break; // �Ǵ� return ;
		}
	}
}



int Application::printAndGetMenu() {
	int menu;
	std::cout << "1. ��ü ����Ʈ ���\n";
	std::cout << "2. �˻�\n";
	std::cout << "3. ����\n";
	std::cout << std::endl;
	std::cout << "�޴� ��ȣ �Է�: ";

	std::cin >> menu;
	std::cout << std::endl;
	return menu;
}