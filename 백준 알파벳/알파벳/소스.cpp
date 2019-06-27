#include<iostream>
#include<string>


using namespace std;
int Max = 1;
int tmax = 1;
char alphabet[26];

void func(char **str , int A, int B, int LA, int LB, char current) {
	if (A != 0) {
		int a = 0;

		if (str[A - 1][B] == alphabet[str[A - 1][B] - 'A']) {
			a = 1;

		}
		if (Max > tmax) {
			tmax = Max;
		}
		if (a == 0) {
			alphabet[str[A - 1][B] - 'A'] = str[A - 1][B];
			char pp = str[A - 1][B];
			Max++;
			func(str, A - 1, B, LA, LB,pp);
		}
	}
	if (B+1<LB) {
		int a = 0;
		if (str[A][B+1] == alphabet[str[A][B+1] - 'A']) {
			a = 1;

		}
		if (Max > tmax) {
			tmax = Max;
		}
		if (a == 0) {
			alphabet[str[A][B+1] - 'A'] = str[A][B+1];
			char pp = str[A][B + 1];
			Max++;
			func(str, A, B+1, LA, LB,pp);
		}
	}
	if (A+1<LA) {
		int a = 0;
		if (str[A + 1][B] == alphabet[str[A + 1][B] - 'A']) {
			a = 1;

		}
		if (Max > tmax) {
			tmax = Max;
		}
		if (a == 0) {
			alphabet[str[A + 1][B] - 'A'] = str[A + 1][B];
			char pp = str[A + 1][B];
			Max++;
			func(str, A + 1, B, LA, LB,pp);
		}
	}
	if (B!=0) {
		int a = 0;
		if (str[A][B-1] == alphabet[str[A][B-1] - 'A']) {
			a = 1;

		}
		if (Max > tmax) {
			tmax = Max;
		}
		if (a == 0) {
			alphabet[str[A][B-1] - 'A'] = str[A][B-1];
			char pp = str[A][B - 1];
			Max++;
			func(str, A, B-1, LA, LB,pp);
		}
	}

	Max--;
	alphabet[current - 'A'] = '>';
}

int main() {
	for (int i = 0; i < 26; i++) {
		alphabet[i] = '>';
	}
	int A, B;
	cin >> A >> B;
	char **arr = new char *[A];
	for (int i = 0; i < A; i++) {
		arr[i] = new char[B];
		cin >> arr[i];
	}
	alphabet[arr[0][0]-'A']= arr[0][0];
	func(arr, 0, 0, A, B,arr[0][0]);
	cout << tmax;

}