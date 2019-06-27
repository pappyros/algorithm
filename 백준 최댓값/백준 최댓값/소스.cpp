#include<iostream>
using namespace std;

class point {
public:
	int y, x;
	int value;

};
int main() {

	point max;
	max.value = 0;
	point **arr = new point*[9];
	for (int i = 0; i < 9; i++) {
		arr[i] = new point[9];
		for (int k = 0; k < 9; k++) {
			int val;
			cin >> val;
			arr[i][k].value = val;
			arr[i][k].y = i;
			arr[i][k].x = k;
			


			if (max.value < arr[i][k].value) {
				max = arr[i][k];
			}

		}
	}
	cout << max.value << endl;
	cout << max.y + 1 << " " << max.x + 1;

}