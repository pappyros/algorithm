#include<iostream>
using namespace std;
typedef class build *nptr;
class build {
public:
	int bname;
	int time;
	int childnum=0;
	nptr * child;
	void registchild(nptr a) {
		childnum++;
		nptr *imsi;
		imsi = child;
		nptr* childimsi = new nptr[childnum];
		for (int i = 0; i < childnum-1; i++) {
			childimsi[i] = imsi[i];
		}
		childimsi[childnum-1] = a;
		child = childimsi;
		
	}
	void search(nptr a,int t,int number) {
		int result;
		result = t + (a->time);
		if (a->bname == number) {
			cout<< result;
		}
		for (int i=0; i < childnum; i++) {
			
			search(a->child[i],result,number);
		}
		

	}

};
int main() {
	int tc;
	cin >> tc;
	
	while (tc > 0) {
		int *resul = new int[tc];
		int gunmoolsoo, link;
		cin >> gunmoolsoo >> link;
		build *building = new build[gunmoolsoo];
		for (int i = 0; i < gunmoolsoo; i++) {
			int tim;
			cin >> tim;
			building[i].bname = i + 1;
			building[i].time = tim;

		}
		for (int i = 0; i < link; i++) {
			int from, to;
			cin >> from >> to;
			building[from - 1].registchild(building + to-1);

		}
		int find;
		cin >> find;
		
		
		
		building[0].search(building, 0, find);
		tc--;
	}


}