#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>



using namespace std;
int main() {

	int tc;
	cin >> tc;
	int *result = new int[tc];
	for (int p = 0; p < tc; p++) {
		int n;
		cin >> n;
		int *arr = new int[n];
		priority_queue<int, vector<int>, greater<int>>heap;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			heap.push(arr[i]);
		}

		int sum = 0;
		while (!heap.empty()) {
			int first = heap.top();
			heap.pop();
			int second = heap.top();
			heap.pop();
			sum += first + second;
			if (heap.empty()) {
				break;
			}
			heap.push(first + second);
		}
		result[p] = sum;
		


	}

	for (int p = 0; p < tc; p++) {
		cout << result[p] << "\n";
	}
}