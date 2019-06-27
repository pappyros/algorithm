#include<iostream>
#include<string>

using namespace std;
void func(int *arr, int limit,int currentzari,  string current) {
	if (currentzari == limit) {
		printf("%s\n",current.c_str());
		return;
	}

	for (int i = 1; i <= limit; i++) {
		if (arr[i] == 0) {
			
			arr[i] = 1;
			
			func(arr, limit, currentzari + 1, current+ to_string(i)+" ");
			
			arr[i] = 0;
		}
	}

}

int main() {

	int n;
	cin >> n;
	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
	func(arr, n, 0, "");
}