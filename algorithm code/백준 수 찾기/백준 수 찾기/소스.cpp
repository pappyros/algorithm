#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int binarysearch(int *arr, int s, int e, int f) {
	int m = (s + e) / 2;
	if (arr[m] == f) {
		return 1;
	}
	else if (s >= e) {
		return 0;
	}

	if (arr[m] < f) {
		binarysearch(arr, m + 1, e, f);
	}
	else if (arr[m] > f) {
		binarysearch(arr, s, m - 1, f);
	}
}

int main(){
	
	int a;
	scanf("%d", &a);
	int *arr = new int[a];
	for (int i = 0; i < a; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr, arr + a);
	int b;
	scanf("%d", &b);
	
	for (int i = 0; i < b; i++) { 
		int A;
		scanf("%d", &A);
		printf("%d\n", binarysearch(arr, 0, a - 1, A));
	}
	


	
}