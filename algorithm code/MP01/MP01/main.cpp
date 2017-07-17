#include <iostream>
#include <string>
#include <fstream>



class Book
{
public:
	Book() {
//		m_Title = "";
		m_Year = 0;
	}

	//Book(std::string title, std::string author, int year) {
	//	m_Title = title;
	//	m_Author = author;
	//	m_Year = year;
	//}

	void setFile(std::string File) {
		m_File = File;
	}

	std::string getFIle() {
		return m_File;
	}
	void setenTitle(std::string File) {
		m_Title_eg = File;
	}

	std::string getenTitle() {
		return m_Title_eg;
	}
	void setTitleko(std::string File) {
		m_Title_ko = File;
	}

	std::string getTitleko() {
		return m_Title_ko;
	}
	void setDirec(std::string File) {
		m_Direc = File;
	}

	std::string getDirec() {
		return m_Direc;
	}
	void setActor(std::string File) {
		m_Actor = File;
	}

	std::string getActor() {
		return m_Actor;
	}
	void setYear(int File) {
		m_Year = File;
	}

	int getYear() {
		return m_Year;
	}
	void setSub(std::string File) {
		m_Sub = File;
	}

	std::string getSub() {
		return m_Sub;
	}
	void setFilename(std::string File) {
		m_Filename = File;
	}

	std::string getFIlename() {
		return m_Filename;
	}
	void setScreen(std::string File) {
		m_Screen = File;
	}

	std::string getScreen() {
		return m_Screen;
	}


protected:
	std::string m_File;
	std::string m_Title_eg;
	std::string m_Title_ko;
	std::string m_Direc;
	std::string m_Actor;
	int m_Year;
	std::string m_Sub;
	std::string m_Filename;
	std::string m_Screen;
public:
	std::string hwakjangja;
	

};

class BookManager
{
public:
	BookManager() 
	{
		m_Count = 0;
	}

	void load() {
		std::ifstream in("MovieMedia.data");
		
		std::string linestr;
		getline(in, linestr);
		m_Count = atoi(linestr.c_str());
		for (int i = 0; i < m_Count; i++) {
			
				getline(in, linestr);
				m_Books[i].setFile(linestr);
				getline(in, linestr);
				m_Books[i].setenTitle(linestr);
				getline(in, linestr);
				m_Books[i].setTitleko(linestr);
				getline(in, linestr);
				m_Books[i].setDirec(linestr);
				getline(in, linestr);
				m_Books[i].setActor(linestr);
				getline(in, linestr);
				m_Books[i].setYear(atoi(linestr.c_str()));
				getline(in, linestr);
				m_Books[i].setSub(linestr);
				getline(in, linestr);
				m_Books[i].hwakjangja = linestr.substr(linestr.length() - 3, 3);
				m_Books[i].setFilename(linestr);
				getline(in, linestr);
				m_Books[i].setScreen(linestr);

			
		}
		
	}

	void printAllBooks() {
		for (int i = 0; i < m_Count; i++) {
			printABook(m_Books[i]);
		}
	}

	void search(std::string s) {
		for (int i = 0; i < m_Count; i++) {
			if (m_Books[i].getenTitle().find(s) != std::string::npos || 
				m_Books[i].getTitleko().find(s) != std::string::npos ||
				m_Books[i].getFIlename().find(s) != std::string::npos ||
				m_Books[i].getDirec().find(s) != std::string::npos ||
				m_Books[i].getActor().find(s) != std::string::npos||
				m_Books[i].getYear() == atoi(s.c_str())||
				m_Books[i].getSub().find(s) != std::string::npos



				) {
				printABook(m_Books[i]);
			}
		}
	}
	

protected:
	void printABook(Book b) {
		std::cout << b.getFIle() << std::endl;
		std::cout << b.getenTitle() << std::endl;
		std::cout << b.getTitleko() << std::endl;
		std::cout << b.getDirec() << std::endl;
		std::cout << b.getActor() << std::endl;
		std::cout << b.getYear() << std::endl;
		std::cout << b.getSub() << std::endl;
		std::cout << b.getFIlename() << std::endl;
		std::cout << b.getScreen() << "\n\n";
		
	}

	Book m_Books[20];
	int m_Count;
};

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
class Application {
public:
	Application() 
	{ 
		m_BookManager.load();
	}

	void exec() {
		int menu = 0;
		while (true) {
			menu = printAndGetMenu();
			if (menu == 1) {
				m_BookManager.printAllBooks();
			}
			else if (menu == 2) {
				std::string aaa;
				std::cin >> aaa;
				m_BookManager.search(aaa);




			}
			else if (menu == 3) {
				break;
			}
		}
	}
protected:
	int printAndGetMenu() {
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
	

	BookManager m_BookManager;
};

int main()
{


	Application a;


	a.exec();
	return 0;
}