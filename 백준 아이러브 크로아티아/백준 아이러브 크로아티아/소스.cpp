#include<iostream>
using namespace std;


int main() {
	int person, question;
	cin >> person >> question;
	person = person - 1;
	int bomb = 210;
	int swit = 0;
	int result;
	for (int i = 0; i < question; i++) {
		int time;
		char answer;
		cin >> time >> answer;
		bomb -= time;
		if (bomb < 0&&swit==0) {
			result=person+1;
			swit = 1;
			
		}
		if (answer == 'N') {
			continue;
		}
		else if (answer == 'P') {
			continue;
		}
		else if (answer == 'T') {
			person = (person + 1) % 8;

		}

	}

	cout << result;
}