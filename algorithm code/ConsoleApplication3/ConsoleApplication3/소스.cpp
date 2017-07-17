#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> vl;
	
	vl.push_back(1);
	vl.push_back(2);
	vl.push_back(3);
	vl.push_back(4);
	vector<int>::iterator iter = vl.begin()+2;
	vl.insert(iter,5);
	for (int i = 0; i < vl.size(); i++) {
		cout << vl[i] << endl;
	}
}