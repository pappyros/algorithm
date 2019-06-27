#include<iostream>
#include<vector>
using namespace std;

class sinip {
public:
	int seo, myun;
	sinip(int a, int b) {
		seo = a;
		myun = b;
	}
};

void func(vector<sinip> vvv) {
	for (int i = 0; i < vvv.size(); i++) {
		int *arr = new int[vvv.size()];
		for (int k = 0; k < vvv.size(); k++) {
			arr[k] = 0;
		}
		int myung = 1;
		arr[i] = 1;


	}



}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<sinip>vc;
		while (n--) {
			int a, b;
			cin >> a >> b;
			vc.push_back(sinip(a, b));


		}

	}
}