#include<iostream>
#include<vector>
using namespace std;


//Bruteforce
/*

void func(vector<int> vec ,int N, int current, int currentN) {

	if (current >= 0 && current <= 20&&currentN+1<N) {

		func(vec, N, current+vec[currentN+1] , currentN+1);
		func(vec, N, current-vec[currentN+1], currentN+1);
		
	}
	else if (currentN+1 == N&&current==vec[N]) {
		total++;
	}
	

}

int main() {

	vector<int> arr;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}


	func(arr, N-1, arr[0], 0);
	cout << total;


	
}
*/

//DP

unsigned long long int arr[901];
unsigned long long int brr[901];

int func(int currentnumber,int endnumber, int *vec) {
	if (currentnumber == endnumber ) {
		return arr[vec[endnumber]];
	}
	else {
		for (int i=0;i<901;i++)
		{
			if (arr[i] != 0) {
				if (i + vec[currentnumber] <= 20) {
					brr[i + vec[currentnumber]] += arr[i];
				}
				if (i - vec[currentnumber] >= 0) {
					brr[i - vec[currentnumber]] += arr[i];
				}
			}

		}
		swap(arr, brr);
		for (int i = 0; i < 901; i++) {
			brr[i] = 0;
		}


		func(currentnumber + 1, endnumber, vec);
	}

}

int main() {
	for (int i = 0; i++; i < 901) {
		arr[i] = 0;
		brr[i] = 0;
	}

	

	int N;
	cin >> N;
	int *vrr = new int[N];
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		vrr[i]=k;
	}
	arr[vrr[0]] = 1;


	func(1, N - 1, vrr);
	cout << arr[vrr[N - 1]];

}