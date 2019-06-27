#include<iostream>
#include<algorithm>
using namespace std;
long long int n;
long long int m;
long long int ans1, ans2;

int main()
{
	cin >> n >> m;
	if (n > m)
	{
		int tmp = n;
		n = m;
		m = tmp;
	}

	ans1 = ((n - 1)*n) / 2;
	ans2 = (m*(m + 1)) / 2;
	cout << ans2 - ans1;
}
