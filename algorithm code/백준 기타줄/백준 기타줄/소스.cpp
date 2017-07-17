#include<iostream>
using namespace std;
class brand {
public:
	int set;
	int one;
};

int func(int set, int one, int num, int mon) {
	if (num == 0) {
		return mon;
	}
	if (num >= 6) {
		
		
			func(set, one, num - 6, mon + set);
		
	}
	else if (num > 0) {
		if (num*one > set) {
			return mon + set;
		}
		else {
			func(set, one, num - 1, mon + one);
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	brand *br = new brand[M];
	int L, l;
	for (int i = 0; i < M; i++) {
		cin >> br[i].set >> br[i].one;
		if (i == 0) {
			L = br[0].set;
			l = br[0].one;

		}

		if (L > br[i].set) {
			L = br[i].set;
		}

		if (l > br[i].one) {
			l = br[i].one;
		}

	}
	if (l * 6 < L) {
		cout << l*N;
	}
	else {
		cout << func(L, l, N, 0);
	}

	


}