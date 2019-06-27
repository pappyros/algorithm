#include<iostream>
#include<vector>

using namespace std;

class hmm {
public:
	long long int start, gab;
};

int main() {
	long long int n, swap, sum;
	cin >> n >> swap >> sum;
	long long int *arr = new long long int[n + 1];
	long long int *brr = new long long int[n + 1];
	int *confirm = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		confirm[i] = -1;
	}
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			arr[i] = 0;
			brr[i] = 0;
			continue;
		}
		long long int a;
		cin >> a;
		arr[i] = arr[i - 1] + a;
		
	}
	
	vector<hmm> vec;
	vector<long long int> result;
	for(int i = 0; i < swap + sum; i++) {
		long long int a,b,c;
		cin >> a >> b >> c;
		if (a == 1) {
			
			if (confirm[b]!=-1 ) {
				vec[confirm[b]].gab= c - (arr[b] - arr[b - 1]);
			}
			else {
				hmm h1;
				h1.start = b;
				h1.gab = c - (arr[b] - arr[b - 1]);
				vec.push_back(h1);
				confirm[b] = vec.size() - 1;


			}

		}
		else {
			long long int sum = arr[c]-arr[b-1];
			for (int k = 0; k < vec.size();k++) {
				if (b <= vec[k].start&&vec[k].start <= c) {
					sum += vec[k].gab;
				}

			}
			result.push_back(sum);

		}
		
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

}