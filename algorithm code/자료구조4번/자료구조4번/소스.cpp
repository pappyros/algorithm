#include<iostream>
#include<string>
#include<fstream>

using namespace std;
class read {
public:
	int inputsize = 1;
	int * input = new int[inputsize];//숫자들을 읽어올 배열
	char line[500];//텍스트를 읽어오는 하나의 라인의 수

	void insert (int a) {//숫자를 하나씩 받을때마다 배열의 크기를 늘려감
		input[inputsize - 1] = a;
		inputsize++;
		int *imsi = new int[inputsize];
		for (int i = 0; i < inputsize - 1; i++) {
			imsi[i] = input[i];
		}
		input = imsi;
	}

	read(string a) {


		ifstream ifile;
		ifile.open(a);
		//파일이 열리게되면
		if (ifile.is_open())

		{


			while (ifile.getline(line, sizeof(line))) // 한 줄씩 읽어 처리를 시작합니다.
			{
				
				int num = 0;

				while (line[num] != NULL) {
					if (line[num] != ' '||NULL) {
						string s = "";
						s += line[num];
						insert(atoi(s.c_str()));//배열에 숫자추가
						
					}

					num++;//다음 글자인덱스 증가



				}

			}



		};
		
	}
};


typedef class ver *nptr;
class Set { //에지셋
public:
	int start, end;//에지의 시작과끝
	string tosort = "";


	void sortinza() {
		tosort = to_string(start) + to_string(end);
	}

};
class ver {
public:
	int bname;//버텍스이름
	int visit = 0;//버텍스의 미리방문여부
	int hvisit = 0;//탐색중의 방문여부
	int childnum = 0;//나가는 에지수
	
	nptr * child;//에지포인터배열
	void registchild(nptr a) {//에지추가시 
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
	void search(nptr a, int b,nptr start);
	
};



void ver::search(nptr a, int b, nptr start) {//이미 생성되있는 에지중에서 지워도 connect가 성립하는지를 판단



	for (int  i = 0; i < a->childnum; i++) {//모든에지를 일단 본다
		
		if ((a->bname==start->bname&&a->child[i]->bname==b)||(a->child[i]->visit==0)||(a->child[i]->hvisit == 1)) {
			//등록여부를 확인하려는에지와 같은 에지를 쓰면 안됨    미리 방문여부가 없으면거나 탐색중에이미 방문했다면 넘어감
			continue;//(a->bname==a->child[i]->bname)||
		}
		else {
			
			if ((a->child[i]->bname == b)|| (a->bname == a->child[i]->bname)) {//같은걸 발견~!!!or자신에게오는 에지를 발견
				if (a->bname == a->child[i]->bname) {//자신에게 오는 에지를 발견시 삭제하고 해당버텍스 차일드 수를줄인다



					for (int k = 0; k < a->childnum; k++) {
						if (a->bname == a->child[i]->bname) {



							if (i == a->childnum - 1) {
								a->childnum--;
							}


							else {
								for (int q = i; q < a->childnum - 1; q++) {
									a->child[q] = a->child[q + 1];
								}
								a->childnum--;
							}
						}
					}



				}
				




				else {//등록된 에지 이외에 도달할수 있는 방법이 있을시 등록된 에지를 삭제하고 버텍스의 차일드수를줄인다.

					//-------------------------------------------------------
					for (int k = 0; k < start->childnum; k++) {
						if (start->child[k]->bname == b) {



							if (k == start->childnum - 1) {
								start->childnum--;
							}


							else {
								for (int q = k; q < start->childnum - 1; q++) {
									start->child[q] = start->child[q + 1];
								}
								start->childnum--;
							}
						}
					}

				}
				
					
					
				
				
			}
			else {
				a->hvisit = 1;//방금 모든 차일드의 탐색이끝낫다 여기로 다시오지않도록 탐색여부를 생성한다
				search(a->child[i], b, start);//다른 버텍스로가자
				
			}
			
		}
		a->hvisit = 0;//한 줄기의 탐색이 끝났으면 탐색여부를 없앤다



	}//다돌 겟지

	







}



void SetSort(Set *a, int b) {
	for (int i = 0; i < b; i++) {
		for (int k = 0; k < b; k++) {
			if (a[i].tosort < a[k].tosort) {
				swap(a[i], a[k]);
			}
		}
	}

}

void hvisitzero(ver* a, int b){
	for (int i = 0; i < b; i++) {
		a[i].hvisit = 0;
	}
}
int main() {
	read Read("input.txt");//텍스트읽어옴
	int readnum = 0;

	int tc = Read.input[readnum++];//리드객체안 배열에서 꺼내서 읽어옴 이후동일
	
	ver** result = new ver*[tc];//테스트케이스별버텍스를저장할 배열
	int*  resultsoo = new int[tc];//테스트케이스별 정수값을 저장할 배열
	int num = 0;
	for (int i = 0; i < tc; i++) {

		int ven, edg;//각각 버텍스수와 에지수이다
		ven= Read.input[readnum++];
		edg= Read.input[readnum++];
		ver *Vert = new ver[ven];
		Set *set = new Set[edg];
		int *err = new int[8];
		for (int c = 0; c < edg; c++) {//버텍스에 에지를 등록한다
			int s, e;
			s= Read.input[readnum++];
			e= Read.input[readnum++];
			set[c].start = s;
			set[c].end = e;
			Vert[s - 1].registchild(Vert + e - 1);
			Vert[s - 1].bname = s;
			Vert[e - 1].bname = e;
			set[c].sortinza();

		}
		Set *resultset = new Set[edg];
		//SetSort(set, edg);
		int resultnum = 0;
		for (int q = 0; q < edg; q++) {//첫번째 에지는 일단 넣고 그다음 회부터 여부를 판단한다.
			
			Vert[set[q].start - 1].visit = 1;
			Vert[set[q].end - 1].visit = 1;

			
			Vert[0].search(Vert + (set[q].start - 1), set[q].end, Vert + (set[q].start - 1));
			hvisitzero(Vert, ven);
			
			
			
		}
		
		result[num] = new ver[ven];
		for (int i = 0; i < ven; i++) {
			result[num][i] = Vert[i];
		}
		resultsoo[num] = ven;
		num++;

	}

	for (int i = 0; i < tc; i++) {//출력문
		cout << "-------------------------------" << endl;
		for (int k = 0; k < resultsoo[i]; k++) {


			for (int z = 0; z < result[i][k].childnum; z++) {
				for (int x = 0; x < result[i][k].childnum; x++) {
					if (result[i][k].child[z]->bname < result[i][k].child[x]->bname) {//순서대로 소팅
						swap(result[i][k].child[z], result[i][k].child[x]);
					}
				}
			}


			for (int p = 0; p < result[i][k].childnum; p++) {
				cout <<result[i][k].bname<<" "<< result[i][k].child[p]->bname<<endl;
			}
		}
		cout << endl;
	}
}