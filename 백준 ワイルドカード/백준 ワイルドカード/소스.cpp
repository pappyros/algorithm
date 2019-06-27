#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class jamsi {
public:
	int star = 0;
	string ppp;
};
string func(string str, string str2) {

	
	vector<jamsi>vect;
	for (int i = 1; i <= str2.size();i++) {
		for (int k = 0; k <= str.size() - i; k++) {
			string imsi = str.substr(k, i);

			for (int p = 0; p <= str2.size() - i; p++) {
				string kkk;
				if (imsi == str2.substr(p, i)) {
					break;
				}
				if (imsi != str2.substr(p, i)) {
					kkk = imsi;
				}

				if (p == str2.size()-i) {
					if (kkk == str) {
						jamsi sv;
						sv.ppp = kkk;
						vect.push_back(sv);
						//cout << "oh" << endl;

					}
					else if (k == 0) {
						jamsi sv;
						sv.ppp = kkk+"*";
						vect.push_back(sv);
						//cout << "oh" << endl;
					}
					else if (k==str.size()-1) {
						jamsi sv;
						sv.ppp = kkk;
						sv.star = 1;
						vect.push_back(sv);
						//cout << "oh" << endl;

					}
					else {
						jamsi sv;
						sv.ppp = kkk+"*";
						sv.star = 1;
						vect.push_back(sv);
						//cout << "oh" << endl;
					}




				}



			}



		}

	}

	
	jamsi jin;
	for (int i = 0; i < vect.size(); i++) {
		if (i == 0) {
			jin = vect[i];
		}
		if (vect[i].ppp < jin.ppp) {
			jin = vect[i];
		}
	}

	if (jin.star == 1) {
		return "*" + jin.ppp;
	}
	else
	{
		return jin.ppp;
	}
}


int main() {
	int m;
	cin >> m;
	string *result = new string[m];
	for (int i = 0; i < m; i++) {
		

		string str,str2;
		cin >> str>>str2;
		result[i] = func(str, str2);


		
	}

	for (int i = 0; i < m; i++) {
		
			cout << result[i] << endl;
		
	}
	
}