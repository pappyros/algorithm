#include<iostream>
#include<string>
#include<deque>

using namespace std;
void remove(deque<string> v) {


	if (v.size() >= 2) {
		if (v[v.size()-1]==v[v.size()-2]) {
			cout << "!";
			v.pop_back();
			cout << "popback";
			v.pop_back();
			remove(v);
		}
	}
}

int main() {
	int num;
	cin >> num;
	int fff= 0;
	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		deque<string> st;
		
		for (int k = 0; k < str.length(); k++) {
			st.push_back(str.substr(k, 1));
			

			for (int i = 0; i < st.size(); i++) {
				if (st.size() >= 2) {
					if (st[st.size() - 1] == st[st.size() - 2]) {
						
						st.pop_back();
						
						st.pop_back();
						
					}
				}
			}
			//remove(st);

		}
		if (st.size()==0) {
			fff++;
		}

	
	}

	cout <<fff;


}