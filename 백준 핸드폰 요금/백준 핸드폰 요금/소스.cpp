#include<iostream>
using namespace std;
int ys(int n) {
	int yogm;
	if (n % 30 != 0) {
		yogm = (n / 30) * 10+10;
	}
	else {
		yogm = (n / 30) * 10+10;
	}
	return yogm;
}
int ms(int n) {
	int yogm;
	if (n % 60 != 0) {
		yogm = (n / 60) * 15 + 15;
	}
	else {
		yogm = (n / 60) * 15+15;
	}
	return yogm;

}


int main() {


	int n;
	cin >> n;
	int *arr = new int[n+1];
	int *ydp = new int[n+1];
	int *mdp = new int[n+1];
	ydp[0] = 0;
	mdp[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		ydp[i] = ydp[i - 1] + ys(arr[i]);
		mdp[i] = mdp[i - 1] + ms(arr[i]);

	}
	if (ydp[n] > mdp[n]) {
		cout << "M" <<" "<< mdp[n]<<endl;

	}
	else if (ydp[n] < mdp[n]) {
		cout << "Y" <<" "<< ydp[n]<<endl;

	}
	else {
		cout << "Y M " << mdp[n]<<endl;

	}

}