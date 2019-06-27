#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#pragma warning(disable:4996)
using namespace std;
class siva {
public:
	int value;

	bool operator > (const siva& rhs) const { return (value > rhs.value); };
};



int main() {
	priority_queue<siva, vector<siva>, greater<siva>>heap;
	int n;
	scanf("%d", &n);
	vector<int>result;
	for (int i = 0; i < n; i++) {
		int query;
		scanf("%d", &query);
		if (query == 0) {
			if (heap.empty()) {
				result.push_back(0);
			}
			else {
				result.push_back(heap.top().value);
				heap.pop();
			}

		}
		else {
			siva siv;
			siv.value = query;
			heap.push(siv);

		}
	}

	for (int i = 0; i < result.size(); i++) {
		printf("%d\n", result[i]);
	}



}
