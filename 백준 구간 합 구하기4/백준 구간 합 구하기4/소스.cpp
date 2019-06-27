#include<stdio.h>


int main() {

	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int*arr = new int[n+1];
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			scanf("%d",&arr[i]);
			
			continue;
		}
		int a;
		scanf("%d", &a);
		arr[i] = arr[i - 1] + a;
	}
	int*result = new int[m];
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d", &s);
		scanf("%d", &e);
		result[i] = arr[e] - arr[s-1];
	};
	for (int i = 0; i < m; i++) {
		printf("%d\n", result[i]);
		
	}


}