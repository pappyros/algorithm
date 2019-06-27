#include<iostream>
#include<algorithm>
using namespace std;

int func(int K,int A,int B,int con,int b) {//ÀüÃ¼ °¹¼öA
	if (B == A) {
		return b;
	}
	if (A>con) {
		return 2 *con;
	}
	if (b > con) {
		return 2 * con;
	}
	
	

	if (b == 0&&A>=K) {
		func(K, A - K, B,con,  b + 1);
	}
	else {
		if (A >= K) {
			int arr[3];
			arr[0]= func(K, A + (K+2), B,con, b + 1);
			arr[1]=func(K, A - (K-2), B,con, b + 1);
			arr[2]=func(K, A - K, B,con, b + 1);
			sort(arr, arr + 3);
			return arr[0];
			
			
		}
		else {
			
			
			int a=func(K, A + K-2, B, con,b + 1);

			cout << a;
			
			

		}
	}

}

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	if(K%A==0&&B!=0){
		cout << -1;
	}
	

	else {
		int d = K%A;

		cout << func(d, A, B,A, 0);

	}
}