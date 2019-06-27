#include<iostream>
#include<vector>
#pragma warning(disable :4996)
using namespace std; int n, m;
void func(vector<int>vr,int st,int ed) {
	if (st == ed+1)return;
	if (vr.size() == m) {
		for (int i = 0; i < m; i++)printf("%d ", vr[i]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		vr.push_back(i); func(vr,st+1,ed); vr.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m; vector<int>t;
	func(t, 0, m);
}
