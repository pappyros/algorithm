#include<iostream>
#include<string>
#include<fstream>

using namespace std;
class read {
public:
	int inputsize = 1;
	int * input = new int[inputsize];//���ڵ��� �о�� �迭
	char line[500];//�ؽ�Ʈ�� �о���� �ϳ��� ������ ��

	void insert (int a) {//���ڸ� �ϳ��� ���������� �迭�� ũ�⸦ �÷���
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
		//������ �����ԵǸ�
		if (ifile.is_open())

		{


			while (ifile.getline(line, sizeof(line))) // �� �پ� �о� ó���� �����մϴ�.
			{
				
				int num = 0;

				while (line[num] != NULL) {
					if (line[num] != ' '||NULL) {
						string s = "";
						s += line[num];
						insert(atoi(s.c_str()));//�迭�� �����߰�
						
					}

					num++;//���� �����ε��� ����



				}

			}



		};
		
	}
};


typedef class ver *nptr;
class Set { //������
public:
	int start, end;//������ ���۰���
	string tosort = "";


	void sortinza() {
		tosort = to_string(start) + to_string(end);
	}

};
class ver {
public:
	int bname;//���ؽ��̸�
	int visit = 0;//���ؽ��� �̸��湮����
	int hvisit = 0;//Ž������ �湮����
	int childnum = 0;//������ ������
	
	nptr * child;//���������͹迭
	void registchild(nptr a) {//�����߰��� 
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



void ver::search(nptr a, int b, nptr start) {//�̹� �������ִ� �����߿��� ������ connect�� �����ϴ����� �Ǵ�



	for (int  i = 0; i < a->childnum; i++) {//��翡���� �ϴ� ����
		
		if ((a->bname==start->bname&&a->child[i]->bname==b)||(a->child[i]->visit==0)||(a->child[i]->hvisit == 1)) {
			//��Ͽ��θ� Ȯ���Ϸ��¿����� ���� ������ ���� �ȵ�    �̸� �湮���ΰ� ������ų� Ž���߿��̹� �湮�ߴٸ� �Ѿ
			continue;//(a->bname==a->child[i]->bname)||
		}
		else {
			
			if ((a->child[i]->bname == b)|| (a->bname == a->child[i]->bname)) {//������ �߰�~!!!or�ڽſ��Կ��� ������ �߰�
				if (a->bname == a->child[i]->bname) {//�ڽſ��� ���� ������ �߽߰� �����ϰ� �ش���ؽ� ���ϵ� �������δ�



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
				




				else {//��ϵ� ���� �̿ܿ� �����Ҽ� �ִ� ����� ������ ��ϵ� ������ �����ϰ� ���ؽ��� ���ϵ�������δ�.

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
				a->hvisit = 1;//��� ��� ���ϵ��� Ž���̳����� ����� �ٽÿ����ʵ��� Ž�����θ� �����Ѵ�
				search(a->child[i], b, start);//�ٸ� ���ؽ��ΰ���
				
			}
			
		}
		a->hvisit = 0;//�� �ٱ��� Ž���� �������� Ž�����θ� ���ش�



	}//�ٵ� ����

	







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
	read Read("input.txt");//�ؽ�Ʈ�о��
	int readnum = 0;

	int tc = Read.input[readnum++];//���尴ü�� �迭���� ������ �о�� ���ĵ���
	
	ver** result = new ver*[tc];//�׽�Ʈ���̽������ؽ��������� �迭
	int*  resultsoo = new int[tc];//�׽�Ʈ���̽��� �������� ������ �迭
	int num = 0;
	for (int i = 0; i < tc; i++) {

		int ven, edg;//���� ���ؽ����� �������̴�
		ven= Read.input[readnum++];
		edg= Read.input[readnum++];
		ver *Vert = new ver[ven];
		Set *set = new Set[edg];
		int *err = new int[8];
		for (int c = 0; c < edg; c++) {//���ؽ��� ������ ����Ѵ�
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
		for (int q = 0; q < edg; q++) {//ù��° ������ �ϴ� �ְ� �״��� ȸ���� ���θ� �Ǵ��Ѵ�.
			
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

	for (int i = 0; i < tc; i++) {//��¹�
		cout << "-------------------------------" << endl;
		for (int k = 0; k < resultsoo[i]; k++) {


			for (int z = 0; z < result[i][k].childnum; z++) {
				for (int x = 0; x < result[i][k].childnum; x++) {
					if (result[i][k].child[z]->bname < result[i][k].child[x]->bname) {//������� ����
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