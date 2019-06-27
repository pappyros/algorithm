#include<iostream>
#include<math.h>
#include <cstdlib>
using namespace std;
class cal {
public:
	int calcul(int x1, int y1, int r1, int x2, int  y2, int  r2) {
		double dis;
		dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		int R1 = r1;
		int R2 = r2;
		if (x1 == x2&&y1 == y2&&r1 == r2) {
			return -1;
		}
		else if (dis == R1 + R2 || dis == abs(R2 - R1)) {
			return 1;
		}
		else if (dis > R1 + R2 || dis < abs(R2 - R1)) {
			return 0;
		}
		else {
			return 2;
		}

	}
};

int main() {
	int tc, bun;
	cin >> tc;
	bun = 0;
	int*result = new int[tc];
	while (tc > 0) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cal omega;
		result[bun++] = omega.calcul(x1, y1, r1, x2, y2, r2);
		tc--;
	}
	for (int i = 0; i < bun; i++) {
		cout << result[i] << endl;
	}
}
