#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

#pragma warning(disable:4996)

using namespace std;

class siva {
public:
	int index;
	int value;
	bool operator > (const siva& rhs) const { return (value > rhs.value); };
};

int main() {
	int num,cha;
	scanf("%d%d", &num,&cha);
	int *arr = new int[num + 1];
	int *min = new int[num + 1];
	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}
	
	priority_queue<siva, vector<siva>, greater<siva>>heap;
	int start, end;
	end = 0;
	start = end - cha + 1;

	for (int i = 1; i <= num; i++) {
		start++; end++;
		siva s1;
		s1.value = arr[i];
		s1.index = i;
		heap.push(s1);
		while (!(start <= heap.top().index&&end >= heap.top().index)) {
			heap.pop();
		}
		min[i] = heap.top().value;
			
	

	}

	for (int i = 1; i <= num; i++) {
		printf("%d ", min[i]);
	}
}