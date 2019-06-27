#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std; vector<vector<char>>srr;
void dol(int i,int q) {
	if (q == -1) {
		char tp = srr[i][0]; srr[i].erase(srr[i].begin()); srr[i].push_back(tp);
	}
	else if (q==1){
		char tp = srr[i][7]; srr[i].pop_back(); srr[i].insert(srr[i].begin(), tp);
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		vector<char>ppp;
		string str; cin >> str; 
		for (int i = 0; i < 8; i++) 	ppp.push_back(str[i]);
		srr.push_back(ppp);//2-5 5-2
	}int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int p, d; cin >> p >> d; p--; int turn[4] = { 0,0,0,0 }; turn[p] = d;
		if (p == 0) {
			if (srr[0][2] != srr[1][6]) {
				turn[1] = -d;
				if (srr[1][2] != srr[2][6]) {
					turn[2] = d;
					if (srr[2][2] != srr[3][6]) {
						turn[3] = -d;
					}
				}
			}
		}
		else if (p == 1) {
			if (srr[0][2] != srr[1][6])turn[0] = -d;
			if (srr[1][2] != srr[2][6]) {
				turn[2] = -d;
				if (srr[2][2] != srr[3][6]) {
					turn[3] = d;
				}
			}
		}
		else if (p == 2) {
			if (srr[2][2] != srr[3][6])turn[3] = -d;
			if (srr[1][2] != srr[2][6]) {
				turn[1] = -d;
				if (srr[0][2] != srr[1][6]) {
					turn[0] = d;
				}
			}
		}
		else if (p == 3) {
			if (srr[2][2] != srr[3][6]) {
				turn[2] = -d;
				if (srr[1][2] != srr[2][6]) {
					turn[1] = d;
					if (srr[0][2] != srr[1][6])turn[0] = -d;
				}
			}
		}
		for (int k = 0; k < 4; k++)dol(k, turn[k]);
		
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (srr[i][0] == '1') {
			sum += pow(2, i);
		}
	}
	cout << sum;
}
