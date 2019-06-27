#include<iostream>
using namespace std;

class circle {
public:
	int x = 0;
	int y = 0;
	int ra = 0;


};
class point {
public:
	int x, y;
public:
	point(int a, int b) {
		x = a;
		y = b;
	}
	int* count(circle *a, int total) {
		int *result = new int[100];
		for (int i = 0; i <= total; i++) {

			if (((x - a[i].x) *(x - a[i].x)) + ((y - a[i].y)*(y - a[i].y)) < (a[i].ra)*(a[i].ra)) {
				
				result[i] = 1;
			}
			else {
				result[i] = 0;
			}
		}
		return result;

	}
};
int main() {
	
	int tc;
	cin >> tc;
	int testcase = tc;
	int *Re = new int[100];
	while (tc > 0) {
		
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		point first(a, b);
		point last(c, d);
		
		int celesoo;
		cin >> celesoo;
		circle cir[100];
		celesoo--;
		int wh = celesoo;
		while (wh >= 0) {
			int a, b, c;
			
			cin >> a >> b >> c;
			cir[wh].x = a;
			cir[wh].y = b;
			cir[wh].ra = c;
			wh--;
		}
		
		int *A = first.count(cir, celesoo);
		int *B = last.count(cir, celesoo);
		for (int i = 0; i <= celesoo; i++) {
			
		}

		int result = 0;
		for (int i = 0; i <= celesoo; i++) {
			int ill = A[i] - B[i];
			if (ill == -1 || ill == 1) {
				result++;
			}
		}
		
		Re[tc] = result;
		
		tc--;
	}
	
	for (int i = testcase; i >0; i--) {
		cout << Re[i] << endl;
	}

}