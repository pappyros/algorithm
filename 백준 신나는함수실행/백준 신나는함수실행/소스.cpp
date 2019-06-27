#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

void func(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << endl;
	}
	else {
		int x = max(a, max(b, c));
		int ***arr = new int**[x + 1];
		for (int i = 0; i <= x; i++) {
			arr[i] = new int*[x + 1];
			for (int k = 0; k <= x; k++) {
				arr[i][k] = new int[x + 1];
				for (int t = 0; t <= x; t++) {
					arr[i][k][t] = 0;
				}
			}
		}
		arr[0][0][0] = 1;

		for (int i = 0; i <= x; i++) {

			for (int k = 0; k <= x; k++) {

				for (int t = 0; t <= x; t++) {
					if (i <= 0 || k <= 0 || t <= 0) {
						arr[i][k][t] = 1;
					}
					else if (i > 20 || k > 20 || t > 20) {
						arr[i][k][t] = arr[20][20][20];
					}
					else if (i < k&&k < t) {
						arr[i][k][t] = arr[i][k][t - 1] + arr[i][k - 1][t - 1] - arr[i][k - 1][t];
					}
					else {
						arr[i][k][t] = arr[i - 1][k][t] + arr[i - 1][k - 1][t] + arr[i - 1][k][t - 1] - arr[i - 1][k - 1][t - 1];

					}


				}
			}
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[a][b][c] << endl;
	}

}
class temp {
public :
	int a, b, c;
};

int main() {
	
	vector<temp> crr;
	while (true) {
		int a1, b1, c1;
		cin >> a1 >> b1 >> c1;
		if (a1 == -1 && b1 == -1 && c1 == -1) {
			break;
		}
		else {
			temp tem;
			tem.a = a1;
			tem.b = b1;
			tem.c = c1;

			crr.push_back(tem);
		}

	}

	for (int i = 0; i < crr.size(); i++) {
		func(crr[i].a, crr[i].b, crr[i].c);
	}

	
	
	
	

}