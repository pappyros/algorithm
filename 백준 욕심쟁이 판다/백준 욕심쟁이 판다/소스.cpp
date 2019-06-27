#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;


class ball {
public:
	vector<int>child;
};

int func(ball* brr,int index,int* score) {
	//int k;
	if (score[index] != 0) {
		return score[index];
	}
	int imsi[4] = { 0,0,0,0 };
	if (brr[index].child.size() == 0) {
		return 1;
	}
	for (int i = 0; i < brr[index].child.size(); i++) {
		imsi[i]=func(brr, brr[index].child[i],score);
	}
	sort(imsi, imsi + 4);
	score[index] = imsi[3] + 1;
	return imsi[3]+1;

}

int main() {
	
	int n;
	scanf("%d", &n);

	ball* brr = new ball[n*n];
	int *score = new int[n*n];
	for (int i = 0; i < n*n; i++) {
		score[i] = 0;
	}
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int k = 0; k < n; k++) {
			scanf("%d", &arr[i][k]);
		}
	}

	for (int i = 0; i < n; i++) {
	
		for (int k = 0; k < n; k++) {
			int compare = arr[i][k];
			//╩С
			if (i != 0) {
				if (arr[i - 1][k] > compare) {
					brr[i*n + k].child.push_back((i - 1)*n + k);
				}
		

			}
			//©Л
			if (k != n - 1) {
				if (arr[i][k+1] > compare) {
					brr[i*n + k].child.push_back(i*n+k+1);
				}

			}
			//го
			if (i != n - 1) {
				if (arr[i +1][k] > compare) {
					brr[i*n + k].child.push_back((i + 1)*n + k);
				}

			}
			//аб
			if (k != 0) {
				if (arr[i][k-1] > compare) {
					brr[i*n + k].child.push_back((i)*n + k-1);
				}

			}



		}
	}
	int dap = 0;
	for (int i = 0; i < n; i++) {

		for (int k = 0; k < n; k++)
		{
			int imsi = func(brr, i*n + k,score);
			score[i*n + k] = imsi;
			if (imsi > dap) {
				dap = imsi;
			}
		}
		
	}
	printf("%d", dap);

}