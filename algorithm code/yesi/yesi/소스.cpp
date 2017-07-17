#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

//#pragma warning(disable:4996)
using namespace std;
class node {
public:
	int visit = 0;

};
class siva {
public:
	int index, value;
	bool operator > (const siva& rhs) const { return (value > rhs.value); };
};
int main() {

	priority_queue<siva, vector<siva>, greater<siva>>heap;

	siva s1;
	s1.index = 1;
	s1.value = 10;
	siva s2;
	s2.index = 2;
	s2.value = 5;
	siva s3;
	s3.index = 3;
	s3.value = 6;
	siva s4;
	s4.index = 4;
	s4.value = 2;
	heap.push(s1);
	heap.push(s2);
	heap.push(s3);
	heap.push(s4);
	vector<siva>ccc;
	while (!heap.empty()) {
		ccc.push_back(heap.top());
		heap.pop();
	}
	for (int i = 0; i < ccc.size(); i++) {
		cout << ccc[i].index << endl;
	}

}