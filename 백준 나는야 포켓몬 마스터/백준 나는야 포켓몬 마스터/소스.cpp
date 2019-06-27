#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

class pokemon {
public:
	int number;
	string name;

};
bool nam(pokemon p1, pokemon p2)
{

	return p1.name < p2.name;
}
bool num(pokemon p1, pokemon p2)
{

	return p1.number < p2.number;
}
int bin(pokemon *prr, string name, int start, int end) {
	int mid = (start + end) / 2;
	int dap;
	if (start >= end) {
		return prr[start].number;
	}
	if (name <= prr[mid].name) {
		dap = bin(prr, name, start, mid);
	}
	else {
		dap = bin(prr, name, mid + 1, end);

	}
	return dap;

}
int main() {

	int n, query;
	cin >> n >> query;
	pokemon*prr = new pokemon[n];
	pokemon*nrr = new pokemon[n];


	for (int i = 1; i <= n; i++) {
		pokemon poke;
		char nnn[21];
		scanf("%s", nnn);
		poke.name = nnn;
		poke.number = i;
		prr[i - 1] = poke;
		nrr[i - 1] = poke;

	}
	sort(prr, prr + n, nam);


	string *result = new string[query];


	for (int i = 0; i < query; i++) {
		string que;

		cin >> que;

		if (que < "999999") {
			int a = atoi(que.c_str());
			result[i] = nrr[a - 1].name;
		}
		else {

			result[i] = to_string(bin(prr, que, 0, n - 1));

		}



	}

	for (int i = 0; i < query; i++) {
		cout << result[i] <<"\n";
		
	}




}