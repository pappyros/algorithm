#include<iostream>
#include<vector>
using namespace std; int n; int dab = 0;
bool brr[201]; bool visit[201][201];
void tam(int cur,vector<int>vec, int a, int b) {

	if (a == b+2)return;
	if (cur == 3) {
		bool tp = (visit[vec[0]][vec[1]]==false&& visit[vec[2]][vec[1]]==false&& visit[vec[0]][vec[2]]==false?true:false);
		if (tp)dab++;
	}
	else {
		brr[a] = true; vec.push_back(a); tam(cur + 1, vec, a + 1, b); brr[a] = false; vec.pop_back();
		tam(cur,vec,  a + 1, b);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	 int m; cin >> n >> m; fill(brr, brr + 201, false); 
	for (int i = 0; i < m; i++) {
		 int a, b; cin >> a >> b; 
		 visit[a][b] = true; visit[b][a] = true;
	}vector<int>oh; tam(0, oh,1, n); cout << dab;
}
