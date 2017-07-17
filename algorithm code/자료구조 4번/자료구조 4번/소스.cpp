#include<iostream>
#include<string>

using namespace std;

typedef class ver *nptr;
class ver {
public:
	int bname;
	int visit=0;
	int hvisit = 0;
	int childnum = 0;
	int cycle = 0;
	nptr * child;
	void registchild(nptr a) {
		childnum++;
		nptr *imsi;
		imsi = child;
		nptr* childimsi = new nptr[childnum];
		for (int i = 0; i < childnum - 1; i++) {
			childimsi[i] = imsi[i];
		}
		childimsi[childnum - 1] = a;
		child = childimsi;
		
	}
	int search(nptr a, int b);
	
	
	

};

//스택
class stack {
public:
	int top;
	
	int num;
	nptr *list = new nptr[num];
public:stack(int a) {
	num = a;
	top = 0;
	
}
	   bool isfull() {
		   if (top == num-1) {
			   return true;
		   }
		   return false;
	   }
	   bool isempty() {
		   if (top == 0) {
			   return true;
		   }
		   return false;
	   }
	   void push(nptr a) {
		   if (isfull()) {
			   cout << "꽉찼습니다" << endl;

		   }
		   else {
			   list[top++] = a;
		   }
	   }
	   nptr pop() {
		   if (isempty()) {
			   cout << "원소가 없습니다." << endl;
		   }
		   else {
			   int k = top - 1;
			   top--;
			   return list[k];
		   }

	   }
	   



};
stack abc(100);
int ver :: search(nptr a, int b) {
	
	
	if (a->bname == b) {
		
		return 3;//같은걸 발견했어 아웃!
	}
	 
	
	
	for (int i = 0; i < a->childnum; i++) {
		if ((a->child[i]->visit==1)) {//미리 방문아니거나 함수방문일경우안감
			search(a->child[i], b);
		
			
		}
		
		

	}//다돌 겟지
	
	
	
	





}

class Set {
public:
	int start, end;
	string tosort = "";
	

	void sortinza() {
		tosort = to_string(start) + to_string(end);
	}

};

void SetSort(Set *a, int b) {
	for (int i = 0; i < b; i++) {
		for (int k = 0; k < b; k++) {
			if (a[i].tosort < a[k].tosort) {
				swap(a[i], a[k]);
			}
		}
	}

}
int main() {
	

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		
		int ven, edg;
		cin >> ven >> edg;
		ver *Vert = new ver[ven];
		Set *set = new Set[edg];
		for (int c = 0; c < edg; c++) {
			int s, e;
			cin >> s>>e ;
			set[c].start = s;
			set[c].end = e;
			Vert[s-1].registchild(Vert + e - 1);
			Vert[s-1].bname = s;
			Vert[e-1].bname = e;
			set[c].sortinza();

		}
		Set *resultset = new Set[edg];
		//SetSort(set, edg);
		int resultnum = 0;
		for (int q = 0; q < edg; q++) {
			if (q == 0) {
				resultset[resultnum++] = set[0];
				Vert[set[0].start-1].visit = 1;
				Vert[set[0].end-1].visit = 1;
				continue;
			}
			Vert[set[q].start - 1].visit = 1;
			Vert[set[q].end-1].visit = 1;
			
			
			int k = Vert[0].search(Vert + (set[q].start - 1), set[q].end);
				
			if (k!=3) {
				for (int k = 0; k < ven; k++) {
					cout << "vertname: " << Vert[k].bname << "childnum :" << Vert[k].childnum << "visit : " << Vert[k].visit << "cycel : " << Vert[k].cycle << "hvisit : " << Vert[k].hvisit << endl;
				}
				cout << endl;

				
				
				resultset[resultnum++] = set[q];
				
				continue;
				
				
			}
			for (int i = 0; i < resultnum; i++) {
				cout << resultset[i].start << " " << resultset[i].end;
			}
			
			
			


		}

	
		
	}

	
	

	


}