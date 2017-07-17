#include<iostream>
#include<cmath>
using namespace std;
/*int main() {


	int tc;
	cin >> tc;
	int num = 0;
	int *arr = (int*)malloc(sizeof(int));
	for (int i = 0; i < tc; i++) {
		int a, b;
		
		cin >> a >> b;
		
		int dis =b - a;
		int first = 1;
		int k = 0;
		while (k==0) {
			int sum = (first*(first + 1))/2;
			
			if (dis % 2 == 0 && sum==dis / 2) {
				arr[num++] = first * 2;
				k = 1;
			}
			else if (dis %2 == 0 && sum > dis / 2) {
				first--;
				arr[num++] = first * 2 + 1;
				k = 1;
			}
			else if (dis % 2 == 1 && sum == dis / 2+1) {
				
				arr[num++] = first * 2;
				k = 1;
			}
			else if(dis%2 ==1&& sum>dis/2+1){
				first--;
				arr[num++] = first * 2 + 1;
				k = 1;
			}
			first++;

		}
		

	}
	for (int i = 0; i < tc; i++) {
		cout << arr[i];
	}
}*/

int main() {
	int tc;
	cin >> tc;
	int *arr = new int[tc];
	for (int i = 0; i < tc; i++) {

		int first, last;
		float disf;
		int disi;
		cin >> first >> last;
		disf = last - first;
		disi = last - first;
		int realdi = disi;
		disf = sqrt(disf);
		disi = sqrt(disi);
		//cout << disi << endl;
		//cout << disf;
		if (disi==0) {
			arr[i] = 0;

		}
		else if (disi == disf) {
			arr[i] = disi + disi - 1;
		}
		else {
			int sum = 0;
			for (int k = 0; k <= disi*2; k=k+2) {
				sum += k;
				if (realdi <= sum) {
					arr[i]=disi*2;
					break;
				}
				else {
					arr[i] = disi * 2+1;
				}
			}
			
		


		}


		




		}
		


	
	for (int q = 0; q < tc; q++) {
		cout << arr[q] << endl;
	}
}