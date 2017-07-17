#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int func(long long  win, long long total) {
	return ((double)win*100/ (double)total);
}
long long prometric(long long  start, long long  end, long long win,long long total, int now, int want) {
	long long mid = (start + end) / 2;
	long long k;
	if (func(win + mid, total + mid)==now&&func(win + mid+1, total + mid+1)==want) {
		return mid+1;
	}
	if (func(win + mid-1, total + mid-1) == now&&func(win + mid, total + mid ) >= want) {
		return mid ;
	}
	if (now== func(win + mid, total+ mid)) {//오른쪽으로
		k = prometric(mid+1, end, win, total, now, want);
	}
	else if(want<=func(win + mid, total + mid)){//왼쪽으로
		k = prometric(start, mid ,win, total, now, want);

	}
	
	return k;

};

int main() {
	long long  to, wi;
	while (scanf("%lld %lld", &to, &wi) != EOF) {
		if (func(wi, to) >= 99) {
			cout << -1 << "\n";
		}
		else {

			cout << prometric(0, 1000000001, wi, to, func(wi, to), func(wi, to) + 1) << "\n";

		}
	

		
	}
	

}