#include<iostream>
#include<cmath>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
class point {
public:
	int x, y;
};
bool func(point A, point B) {
	return A.x < B.x;
}
int main() {
	int num;
	scanf("%d", &num);
	point*prr = new point[num];
	for (int i = 0; i < num; i++) {
		scanf("%d", &prr[i].x);
		scanf("%d", &prr[i].y);
	}
	sort(prr, prr + num, func);
	
	int dist = 1000000001;
	for (int i = 0; i < num; i++) {
		for (int k = i+1; k < num; k++) {
			if (pow(prr[k].x - prr[i].x,2) >= dist)break;
			int imsi = pow(prr[i].x - prr[k].x,2) + pow(prr[i].y - prr[k].y,2);
			if(dist >imsi ){
				dist = imsi;

			}


		}
	}

	printf("%d",dist);

}