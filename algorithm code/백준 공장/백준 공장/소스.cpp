#include<iostream>
#include<vector>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
class mmm {
public:
	int index, value;
	bool operator > (const mmm& rhs) const { return (value > rhs.value); };
	
};
bool ttt(mmm m1, mmm m2) {
	return(m1.value < m2.value);
}
int bins(mmm*mrr, int a, int start, int end) {
	int mid = (start + end) / 2;
	if (start >= end) {
		return mrr[start].index;
	}

	if (a <= mrr[mid].value) {
		bins(mrr, a, start, mid);
	}
	else {
		bins(mrr, a, mid+1, end);

	}

}


int main() {
	int n;
	cin >> n;
	
	int *arr = new int[n];
	mmm *brr = new mmm[n];
	for (int i = 0; i < n; i++) {
	
		cin >> arr[i];
		
	}
	
	for (int i = 0; i < n; i++) {

		int index, value;
		cin >> value;
		index = i + 1;
		mmm m1;
		m1.index = index;
		m1.value = value;
		brr[i] = m1;

	}
	sort(brr, brr + n,ttt);

	for (int i = 0; i < n; i++) {

		arr[i] = bins(brr, arr[i], 0, n - 1);
		

	}
	//vector<int>imsi;
	priority_queue<int> heap;
	priority_queue<int> imsiheap;
	int dap = 0;
	//imsi.push_back(arr[0]);
	heap.push(arr[0]);
	for (int i = 1; i < n; i++) {
		if (heap.top() < arr[i]) {
			heap.push(arr[i]);
			//imsi.push_back(arr[i]);
		}
		else {
			dap++;
			imsiheap = heap;
			imsiheap.pop();
			while (!imsiheap.empty()) {
				if (imsiheap.top() < arr[i]) {
					break;
				}
				else {
					imsiheap.pop();
					dap++;
				}
			}
			heap.push(arr[i]);

		}
		


	}
	

	
	cout << dap;

}