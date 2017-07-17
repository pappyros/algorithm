#include<iostream>
#include<vector>
#include<string>
using namespace std;

class stack {
public:
	
	vector<string>arr;

	void push(string a) {
		if (a == ")") {
			if (arr.size() == 0) {
				arr.push_back(")");
			}
			else if (arr[arr.size() - 1] == "(") {
				arr.pop_back();
			}
			else {
				arr.push_back(")");
			}
		}
		else {
			arr.push_back(a);
		}

	}
	void pop() {
		arr.erase(arr.begin()+arr.size()-1);
	}



};

int main() {
	int n;
	cin >> n;

	int *result = new int[n];
	for (int i = 0; i < n; i++) {
		stack sta;
		string imsi;
		cin >> imsi;
		for (int k = 0; k < imsi.size(); k++) {
			sta.push(imsi.substr(k, 1));
		}

		if (sta.arr.size() == 0) {
			result[i] = 1;
		}
		else {
			result[i] = 0;
		}






	}

	for (int i = 0; i < n; i++) {
		if (result[i] == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	

	
}