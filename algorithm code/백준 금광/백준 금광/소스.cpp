#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
class point {
public:
	int x, y;
	int value;
	
};
bool func(point a, point b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}

int main() {

	int tc;


	scanf("%d", &tc);
	point *arr = new point[tc];
	int *Max = new int[tc];

	for (int i = 0; i < tc; i++) {
		int a, b, c;
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		arr[i].x = a;
		arr[i].y = b;
		arr[i].value = c;
		
	}
	sort(arr, arr + tc, func);

	for (int i = 0; i < tc; i++) {
		int max;
		int real;
		for (int k = 0; k < tc; k++) {
			if (k == 0) {
				max = arr[k].value;
				real = arr[k].value;
				continue;
			}
			real += arr[k].value;
			if (real > max) {
				max = real;
			}

		}

		Max[i] = max;
	}

	sort(Max, Max + tc);
	cout << Max[tc - 1];

	
}