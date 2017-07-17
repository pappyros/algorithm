#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
class point {
public:
	int x, y;
	int sum;
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
	for (int i = 0; i < tc; i++) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		arr[i].x = a;
		arr[i].y = b;
		arr[i].sum = 1000000 * b + a;
	}
	sort(arr, arr + tc, func);
	for (int i = 0; i < tc; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
}