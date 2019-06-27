#include<iostream>
#include<algorithm>
using namespace std;
class house {
public:
	int arr[3];
	
};
int func(house a[] ,int num, int value, int depth, int prenum) {
	if (depth == num) {
		return value;
	};
	if (depth == 0) {
		int ar[3];
		ar[0] = func(a, num, value + a[depth].arr[0], depth + 1,0);
		ar[1] = func(a, num, value + a[depth].arr[1], depth + 1, 1);
		ar[2] = func(a, num, value + a[depth].arr[2], depth + 1, 2);
		sort(ar, ar + 3);
		return ar[0];
	}
	else {
		if (prenum == 0) {
			int q = func(a, num, value + a[depth].arr[1], depth + 1, 1);
			int w = func(a, num, value + a[depth].arr[2], depth + 1, 2);
			if (q >= w) {
				return w;
			}
			else {
				return q;
			}

		}
		else if (prenum == 1) {
			int q = func(a, num, value + a[depth].arr[0], depth + 1, 0);
			int w = func(a, num, value + a[depth].arr[2], depth + 1, 2);
			if (q >= w) {
				return w;
			}
			else {
				return q;
			}

		}
		else if (prenum == 2 ) {
			int q = func(a, num, value + a[depth].arr[1], depth + 1, 1);
			int w = func(a, num, value + a[depth].arr[0], depth + 1, 0);
			if (q >= w) {
				return w;
			}
			else {
				return q;
			}

		}


	}

}

int main() {
	int h;
	cin >> h;
	house *hs = new house[h];
	for (int i = 0; i < h; i++) {
		cin >> hs[i].arr[0] >> hs[i].arr[1] >> hs[i].arr[2];


	}
	cout << func(hs, h, 0, 0, 0);



}