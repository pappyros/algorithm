#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable :4996)

using namespace std;



int main() {

	int num;
	scanf("%d",&num);
	int *arr = new int[num];
	int *mrr = new int[num];
	int imsi = 0;

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	
	imsi = 0;
	for (int i = 0; i < num; i++) {
		for (int k = i; k < num; k++) {
			if (k == i) {
				mrr[i] = arr[i];
				imsi = arr[i];
				continue;
			}
			imsi = imsi+arr[k];
			if (imsi > mrr[i]) {
				mrr[i] = imsi;
			}

		}
	}
	int max;
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			max = mrr[i];
			continue;
		}
		if (mrr[i] > max) {
			max = mrr[i];
		}
	}
	
	printf("%d",max);

}