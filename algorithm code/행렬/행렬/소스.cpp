#include<iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	char **arr = new char*[N];
	char **mrr = new char*[N];



	for (int i = 0; i < N; i++) {
		arr[i] = new char[M];
		
			cin >> arr[i];
		
	}
	for (int i = 0; i < N; i++) {
		mrr[i] = new char[M];
	
			cin >> mrr[i];
		
	}
	for (int i = 0; i < N; i++) {
		
		for (int k = 0; k < M; k++) {
			
			if (arr[i][k] =='1'&&mrr[i][k]=='1') {
				arr[i][k] == '0';
			}
			else if (arr[i][k] == '0'+'0') {
				arr[i][k] = '0';
			}
			else if (arr[i][k] == '0' + '1') {
				arr[i][k] = '1';
			}

		}
	}


	for (int i = 0; i < N; i++) {
		
		for (int k = 0; k < M; k++) {
			cout<<arr[i][k];
		}
		cout << endl;
	}

}