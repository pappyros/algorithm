#include <iostream>
#include <string>
using namespace std;

int main()
{
	string hans = "# 으아가갹ㄱㄱㄷ갹강ㄷㄱ c++ 프로그래밍의 세계에 첫 발을 내딛다! #";
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