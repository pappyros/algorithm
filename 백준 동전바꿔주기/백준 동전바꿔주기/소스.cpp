#include<iostream>
#include<vector>
using namespace std;
class Coin {
public:
	int value;
	int gesu;
};

int main() {

	int money, n;
	cin >> money >> n;
	vector<Coin>coin;
	for (int i = 0; i < n; i++) {
		int aaa,bbb;
		cin >> aaa>>bbb;
		Coin c;
		c.value = aaa;
		c.gesu = bbb;
		coin.push_back(c);
	}
	int *arr = new int[money + 1];
	int *brr = new int[money + 1];
	arr[0] = 1;
	brr[0] = 1;
	for (int i = 1; i < money + 1; i++) {
		arr[i] = 0;
		brr[i] = 0;
	}


	for (int i = 0; i < coin.size(); i++) {
		for(int k = 0; k < money + 1; k++) {
			if (arr[k] != 0) {
				for (int p = k + coin[i].value; (p <= k + coin[i].value*coin[i].gesu)&&(p<=money); p = p + coin[i].value) {
					brr[p]+=arr[k];
				}

			}
		}
		
		for (int k = 0; k < money + 1; k++) {
			arr[k] = brr[k];
		}
	}
	
	cout << arr[money];

}