#include<iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include<string>

using namespace std;
int a = 0;
int countcity = 0;//�����������Ǽ�
int countmajor = 0;//���������Ǽ�


class City {//����Ŭ����
public:
	
	string name;
	int soo;
	City() {
		

		

		soo = 0;
	}
};
class Major {//����Ŭ����
public:
	
	string name;
	int soo;
	Major(){
		
		soo = 0;
	}
};

City *cities = new City[100];//����Ŭ������ü�迭
Major *majors = new Major[100];//����Ŭ������ü�迭

class Student {
public:
	string number = "";
	string name = "";
	string major = "";
	string city = "";
	string grade = "";
public:
	Student() {

	}
	Student(string num, string nam, string maj, string cit, string gra,Student stu[]) {
		number = num;
		name = nam;
		major = maj;
		city = cit;
		grade = gra;
		cityv();
		majorv();
		

	}
	void setgrade(string gra) {//���������� ���������� �Է¹޾������ cityv�Լ��� majorv�Լ��� ����ǵ����Ѵ� ���Լ����� �ش��л���ü�� ���ÿ�, ������ ����ü�迭�� �Ҵ��Ѵ�.
		grade = gra;
		cityv();
		majorv();
	}

	void cityv() {
		int swit = 0;
		for (int i = 0; i < countcity; i++) {
			
			if (city == cities[i].name) {
				cities[i].soo++;
				swit = 1;
				break;
			}

			

		}
		if (swit == 0) {
			cities[countcity].name = city;
			cities[countcity].soo++;
			countcity++;
		}
		
		


	}
	void majorv() {
		int swit = 0;
		for (int i = 0; i < countmajor; i++) {

			if (major == majors[i].name) {
				majors[i].soo++;
				swit = 1;
				break;
			}



		}
		if (swit == 0) {
			majors[countmajor].name = major;
			majors[countmajor].soo++;
			countmajor++;
		}
		

	}

};






//����Ʈ
void printarray(Student s[]) {
	
	for (int i = 0; i <= a; i++) {
		cout << s[i].name << " " << s[i].number << " " << s[i].major << " " << s[i].city << " " << s[i].grade << endl;
	}

}


//����
void add(Student s[], Student k) {
	
	for (int i = 0; i <= a; i++) {
		if ((s[i].name > k.name)||(i==a)) {
			for (int k = a - 1; k >= i;k--) {
				s[k + 1] = s[k];
			}
			s[i] = k;
			break;
		}
	}
	
	a++;

}

//����
void remove(Student s[], string b) {
	string cit;
	string maj;
	int aaa = countcity;//ī��Ʈ���� �������� �ٲ�� �����Ƿ� �ٸ� ������ ����
	int bbb = countmajor;
	for (int i = 0; i < a; i++) {
		if (s[i].name == b) {
			cit = s[i].city;
			maj = s[i].major;
			for (i; i < a; i++) {
				s[i] = s[i + 1];
			}
			Student nul;
			s[a-1] = nul;
			a--;
		}
	}
	for (int i = 0; i < aaa; i++) {
		if (cit == cities[i].name) {
			if (cities[i].soo == 1) {//�л���ü ������ �л���ü�� �������ָ� �ȵȴ�, �׿��ش��ϴ� ����, ���� ��ü�� ������ ���־���Ѵ� ���� �׼���1�̶��  �迭���� �ƿ� �����Ѵ�

				for (i; i < aaa; i++) {
					cities[i] = cities[i + 1];
				}
				City nul;
				cities[countcity - 1] = nul;
				countcity--;

			}
			else {
				cities[i].soo--;
			}
			
			
		}
	}


	for (int i = 0; i < bbb; i++) {
		if (maj == majors[i].name) {
			if (majors[i].soo == 1) {

				for (i; i < bbb; i++) {
					majors[i] = majors[i + 1];
				}
				Major nul;
				majors[countcity - 1] = nul;
				countmajor--;

			}
			else {
				majors[i].soo--;
			}
			
		}
		
	}
	
}
//Ž��
void search(Student st[], string b, int s, int e) {//����Ž��

	int m = (s + e) / 2;
	if ((s == e) && (st[s].name != b)) {//ã�»���� ���� ���� �ִ�.
		cout << "���µ��մϴ�" << endl;

	}

	else if (s == e) {
		cout <<"ã�ҽ��ϴ�."<< st[s].name << " " << st[s].number << " " << st[s].major << " " << st[s].city << " " << st[s].grade << endl;


	}
	else if (st[m].name>=b) {
		e = m - 1;
		if (e < 0) {
			e +=1;
		}
		search(st, b, s, e);

	}
	else {
		s = m + 1;
		search(st, b, s, e);

	}

}



//�ְ������� �л�
void maxscore(Student s[]) {
	string MAX = "0";
	string NAME = "";
	for (int i = 0; i <= a; i++) {
		if (s[i].grade > MAX) {
			MAX = s[i].grade;
			NAME = s[i].name;
		}


	}
	cout <<"�ְ������� : "<< MAX << " �� ���ΰ��� : " << NAME << endl;
}
//�������� ���
void avscore(Student s[]) {
	double sum = 0;
	for (int i = 0; i <= a; i++) {
		sum += atof(s[i].grade.c_str());


	}
	cout <<"������� : "<< sum / a << endl;
}
void overfour(Student s[]) {
	//4.0�Ѵ� �ΰ���
	int sa = 0;
	for (int i = 0; i <= a; i++) {
		if (atof(s[i].grade.c_str()) > 4) {
			sa++;
		}

	}
	cout <<"4.0�Ѵ� ������� �� : "<< sa << "��" << endl;
}

void ilsanin(Student s[]) {
	//�ϻ꿡 ��� ����� ����?
	int ilsan = 0;
	for (int i = 0; i <= a; i++) {
		if (s[i].city == "�ϻ�") {
			ilsan++;
		}

	}
	cout <<"�ϻ꿡 ��� ����� ���� : "<< ilsan << "��" << endl;
}
//���� ���� �л��� �����ϴµ���
void mostlive(City s[]) {
	int MAX = 0;
	string NAME = "";
	for (int i = 0; i < countcity - 1; i++) {
		if (s[i].soo > MAX) {
			MAX = s[i].soo;
			NAME = s[i].name;
		}
	}
	cout <<"���帹�� �л��� ��� ���ô� : "<<NAME << " " << MAX<<"��"<<endl;

	
}


//��л��� �������ÿ���� �л����̸�
void livewith(Student s[], string h) {
	string live;
	int soo=-1;
	cout << h << "�� ���� ���ÿ���� ����� : " ;
	for (int i = 0; i <= a; i++) {
		if (s[i].name == h) {
			live = s[i].city;
			

		}
	}
	for (int i = 0; i <= a; i++) {
		if ((live == s[i].city)&&(s[i].name!=h)) {
			
			soo++;
			cout << s[i].name << ",";
		}
	}
	cout << endl;

	

}

//�а��� ���� �̸�;
void majorsoo(Major s[]) {
	cout <<"�� �а��� ����"<< countmajor << "�� : ";
	
	for (int i = 0; i < countmajor; i++) {
		cout << majors[i].name << ",";
	}
	cout << endl;


}



/////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main() {
	ifstream ifile;
	ifile.open("StdList.txt");
	char line[100];
	
	

	char plast[100];
	for (int k = 0; k < 100; k++) {
		plast[k] = ' ';
	}
	Student *student = new Student[500];
	


	
	

	 // �� �پ� �о �ӽ÷� ������ ����

	  // ���� ����

	if (ifile.is_open())

	{

		while (ifile.getline(line, sizeof(line))) // �� �پ� �о� ó���� �����մϴ�.
		{
			if (line[0] < '0') { break; }
			int bun = 0;
			
		
			
			for (int k = 0; k < 100; k++) {
				if (line[k] ==NULL) {
					break;
				}
				else {
					plast[k] = line[k];
				}

			}
















			for (int k = 0; k < 100; k++) {
				if (plast[k] == ' ') {
					bun++;
					break;
				}
				else {
					student[a].number = student[a].number + plast[k];
					bun++;
				}

			}
			for (int k = 0; k < 100; k++) {
				if (plast[bun] != ' ') {
					
					break;
				}
				bun+=1;
				
			}//���� ����
			











			for (int k = bun; k < 100; k++) {
				if (plast[k] == ' ') {
					bun++;
					break;
				}
				else {
					student[a].name = student[a].name + plast[k];
					bun++;
				}

			}
			for (int k = 0; k < 100; k++) {
				if (plast[bun] != ' ') {

					break;
				}
				bun += 1;

			}//���� ����
			














			for (int k = bun; k < 100; k++) {
				if (plast[k]=='\t'){
					bun++;
					break;
				}
				else {
					student[a].major = student[a].major + plast[k];
					bun++;
				}

			}
			for (int k = 0; k < 100; k++) {
				if (plast[bun] != '\t') {

					break;
				}
				bun += 1;

			}//���� ����

			












			for (int k = bun; k < 100; k++) {
				if (plast[k] == '\t') {
					bun++;
					break;
				}
				
					student[a].city = student[a].city + plast[k];
					bun++;
				

			}
			for (int k = 0; k < 100; k++) {
				if (plast[bun] != '\t') {

					break;
				}
				bun += 1;

			}//���� ����

		









			int p = bun;
			string imsigrade="";
			for (int k = bun; k <= p+3; k++) {
				

				imsigrade = imsigrade + plast[k];
				bun++;


			}
			student[a].setgrade(imsigrade);


			if (a != 0) {
				for (int i = 0; i <a; i++) {
					if (student[a].name < student[i].name) {
						Student imsi = student[a];
						for (int k = a - 1; k >= i; k--) {
							student[k + 1] = student[k];
						}
						student[i] = imsi;
						break;
					}
				}






			}
			



			a++;
		}


		//////////////////////////////////////////////////////////////����//////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		
		printarray(student);
		
		
	
		
		remove(student, "�����");
		search(student,"�����", 0, a-1);//����Ž��//a�� ���л��� ����
		printarray(student);//����Ʈ
	
        //�ְ������� �л�
		maxscore(student);
		//�������� ���
		avscore(student);

		//4.0�Ѵ� �����
		overfour(student);


		//�ϻ꿡��� ����Ǽ�
		ilsanin(student);
		
		//���� ���� �л��� �����ϴµ���
		mostlive(cities);
		
		//��л��� �������ÿ���� �л����̸�
		livewith(student,"��ȣ��");
	
		//�а��� ���� �̸�;
		majorsoo(majors);


		
		




		

		

		
		







	
       

		



		
		






		
		











	}


	
}