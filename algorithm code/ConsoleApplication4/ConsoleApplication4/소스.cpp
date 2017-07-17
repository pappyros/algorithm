#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(3);
	v.push_back(50);
	vector<int>::reverse_iterator iter;

	sort(v.begin(), v.end());



	for (iter = v.rbegin(); iter != v.rend(); iter++){
		cout << *iter << endl;
}

	return 0;
}
