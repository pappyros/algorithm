#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;


class human {
public:
	vector<int>child;
	int gab;
};

int func(human* hrr, int nu) {
	if (hrr[nu].child.size() != 0) {

	
		int ma=0;
		for (int i = 0; i < hrr[nu].child.size(); i++) {
			if (hrr[hrr[nu].child[i]].gab > ma) {
				func(hrr, hrr[nu].child[i]);
				ma = hrr[hrr[nu].child[i]].gab;
			}
		}
		int aaa = hrr[nu].child.size();
		
		hrr[nu].gab= max(ma,aaa);
		return hrr[nu].gab;



	}
	else {
		hrr[nu].gab = 0;
		return 0;
	}

}



int main() {
	int num,head;
	scanf("%d", &num);
	human* hrr = new human[num];
	for (int i = 0; i < num; i++) {
		int k;
		scanf("%d", &k);
		if (k == -1) { head = i; continue; };
		hrr[k].child.push_back(i);


	}
	func(hrr, head);

	printf("%d", hrr[head].gab);


}
