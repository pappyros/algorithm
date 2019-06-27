#include<iostream>
#include<string>
using namespace std;

int main() {
	int num;
	cin >> num;

	string *arr = new string[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	int now = 0;


	while(arr[0] != "KBS1") {


		if (arr[now] != "KBS1") {
			now += 1;
			cout << "1";

		}

		else if (arr[now] == "KBS1") {
			swap(arr[now], arr[now - 1]);
			now -= 1;
			
			cout << "4";
		}

	}
	now = 0;




	while (arr[1] != "KBS2") {

		if (arr[now] != "KBS2") {
			now += 1;
			cout << "1";
		}
		else if (arr[now] == "KBS2") {
			swap(arr[now], arr[now - 1]);
			now -= 1;
			
			cout << "4";
		}

	}
}