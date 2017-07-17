#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
class deca {
public:
	int x, y;
	int score;
	deca() {
		score = 0;
	}
};

bool func(deca a, deca b) {
	return a.score < b.score;
}
int main() {
	vector<deca> decv;
	char **arr = new char*[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = new char[5];
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			if (arr[i][k] == '*') {
				deca dec1;
				dec1.x = i;
				dec1.y = k;
				decv.push_back(dec1);
			}
		}
	}
	int max = 1000;
		
	for (int i = 0; i < decv.size(); i++) {
		int sum = 0;
		for (int k = 0; k < decv.size(); k++) {
			decv[i].score+=abs(decv[i].x - decv[k].x);
			decv[i].score+= abs(decv[i].y - decv[k].y);
		}
		
	}
	sort(decv.begin(), decv.end(), func);
	
	

}