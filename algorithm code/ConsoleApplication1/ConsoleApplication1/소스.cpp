#include <iostream>
#include <string>
using namespace std;

int main()
{
	string hans = "# ���ư����������������� c++ ���α׷����� ���迡 ù ���� �����! #";
	int len = hans.length();
	
	for (int i = 0; i < len; i++) {
		cout << '#';
	}
	cout << endl;
	cout << hans;
	cout << endl;
	for (int i = 0; i < len; i++) {
		cout << '#';
	}
	cout << endl;
	
	return 0;
}