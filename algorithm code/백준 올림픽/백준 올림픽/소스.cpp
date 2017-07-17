#include<iostream>
#include<algorithm>
using namespace std;


class nation {
public:
	int bun;
	int rank;
	long long int score;
};
bool st(nation a, nation b) {
	return a.score > b.score;
}
int main() {
	int num, re;

	cin >> num >> re;
	nation *arr = new nation[num];
	for (int i = 0; i < num; i++) {
		int n, g, s, c;
		cin >> n >> g >> s >> c;
		arr[i].bun = n;
		arr[i].score = 1000000000000 * g + 1000000 * s + c;
	}
	sort(arr, arr + num, st);
	int s = 1;
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			arr[i].rank = s;
			if (arr[i].bun == re) {
				cout << arr[i].rank;
				break;
			}
			continue;
		}


		if (arr[i].score == arr[i - 1].score) {
			arr[i].rank = arr[i - 1].rank;
			if (arr[i].bun == re) {
				cout << arr[i].rank;
				break;
			}
		}
		else {
			arr[i].rank = i + 1;
			if (arr[i].bun == re) {
				cout << arr[i].rank;
				break;
			}
		}
	}

}