#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void load(string fileName);

class Application {
public:
	void exect() {
		while (true) {
			cout << "1.��ü ����Ʈ ���" << endl;
			cout << "2 �˻�" << endl;
			cout << " 3 ����" << endl;


			cout << "�޴� ��ȣ �Է� :";
			int a;
			cin >> a;

			if (a == 1) {

			}
			else if (a == 2) {

			}
			else if (a == 3) {
				cout << "�����";
				break;
			}
		}

	}
};

int main()
{

	load("MovieMedia2.data");
	
	return 0;
}
void load(string filename) {
	std::ifstream in(filename);
	int num = 1;

	//char temp[256];
	//in.getline(temp, 256);
	//num = atoi(temp);
	//std::cout << num << std::endl;
	//in.getline(temp, 256);
	//std::cout << temp << std::endl;
	//in.getline(temp, 256);
	//std::cout << temp << std::endl;
	//std::string s;
	//getline(in, s);
	//num = atoi(s.c_str());
	//std::cout << num << std::endl;
	//getline(in, s);
	//std::cout << s << std::endl;
	//getline(in, s);
	//std::cout << s << std::endl;
	//in >> num;
	//std::cout << num << std::endl;
	//in >> s;
	//std::cout << s << std::endl;
	//in >> s;
	//std::cout << s << std::endl;
	//in >> s;
	//std::cout << s << std::endl;

	Application app;
	app.exect();
	std::string s;
	bool swit = true;
	int bun=-10;
	while (in) {
		if (bun == -1) {
			break;
		}
		s = "";
		getline(in, s);
		if (swit == true) {
			bun = atoi(s.c_str()) * 9;
			swit = false;
		}
		std::cout << s << std::endl;
		bun--;
	}
	//char temp[256];
	//while (in) {
	//	in.getline(temp, 256);
	//	std::cout << temp << std::endl;
	//}
	in.close();



}