#include<iostream>
#include<vector>

using namespace std;
int soon = 1;
class stack {
public:
	vector<int>arr;
	void push(int a) {
		arr.push_back(a);
	}
	void pop() {
		arr.erase(arr.begin() + arr.size()-1);
	}
};
int main() {

	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack good;
	stack bad;
	for (int i = 0; i < n; i++) {
		if (arr[i] == soon) {
			good.push(arr[i]);
			soon++;
		}
		else {
			if ((bad.arr.size()!=0)&&bad.arr[bad.arr.size() - 1] == soon) {
				bad.pop();
				i--;
				soon++;
			}
			else {
				bad.push(arr[i]);
			}

		}
	}
	while (true) {
		if (bad.arr.size() == 0) {
			cout << "Nice";
			break;
		}

		if (soon == bad.arr[bad.arr.size() - 1]) {
			bad.pop();
			soon++;

		}
		else {
			cout << "Sad";
			break;
		}
	}

	
}