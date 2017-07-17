#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int moon;
	cin >> moon;
	vector<int> stack;
	vector<int> result;

	for (int i = 0; i < moon; i++) {
		string ques;
		cin >> ques;

		if (ques == "push") {
			int a;
			cin >> a;
			stack.push_back(a);

		}
		else if (ques == "pop") {
			if (stack.empty()) {
				result.push_back(-1);
			}
			else {
				result.push_back(stack[stack.size() - 1]);
				stack.pop_back();
			}

		}
		else if (ques == "top") {
			if (stack.empty()) {
				result.push_back(-1);
			}
			else {
				result.push_back(stack[stack.size() - 1]);
				
			}

		}
		else if (ques == "size") {
			result.push_back(stack.size());

		}
		else if (ques == "empty") {
			result.push_back(stack.empty());

		}
		
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}