#include<iostream>
using namespace std;

int main() {

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	int now = S;
	int result = 0;
	while (true) {
		if (G > S) {
			if (now + U > F||now==now+U) {
				cout << "use the stairs";
				break;
			}
			now += U;
			result++;
			

		}
		else if (G == S) {
			cout << result;
			break;

		}
		else if(G < S) {
			if (now - D <1||now==now-D) {
				cout << "use the stairs";
				break;
			}
			now - +D;
			result++  ;

		}
	}
}