#include<iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include<string>

using namespace std;
int a = 0;
int countcity = 0;//도시의종류의수
int countmajor = 0;//전공종류의수


class City {//도시클래스
public:
	
	string name;
	int soo;
	City() {
		

		

		soo = 0;
	}
};
class Major {//전공클래스
public:
	
	string name;
	int soo;
	Major(){
		
		soo = 0;
	}
};

City *cities = new City[100];//도시클래스객체배열
Major *majors = new Major[100];//전공클래스객체배열

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
	void setgrade(string gra) {//마지막으로 학점정보를 입력받았을경우 cityv함수와 majorv함수가 실행되도록한다 이함수들은 해당학생객체의 도시와, 전공을 각객체배열에 할당한다.
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






//프린트
void printarray(Student s[]) {
	
	for (int i = 0; i <= a; i++) {
		cout << s[i].name << " " << s[i].number << " " << s[i].major << " " << s[i].city << " " << s[i].grade << endl;
	}

}


//삽입
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

//제거
void remove(Student s[], string b) {
	string cit;
	string maj;
	int aaa = countcity;//카운트값이 포문에서 바뀔수 있으므로 다른 변수에 저장
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
			if (cities[i].soo == 1) {//학생객체 삭제시 학생객체만 삭제해주면 안된다, 그에해당하는 도시, 전공 객체도 삭제를 해주어야한다 만약 그수가1이라면  배열에서 아예 삭제한다

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
//탐색
void search(Student st[], string b, int s, int e) {//이진탐색

	int m = (s + e) / 2;
	if ((s == e) && (st[s].name != b)) {//찾는사람이 없을 수도 있다.
		cout << "없는듯합니다" << endl;

	}

	else if (s == e) {
		cout <<"찾았습니다."<< st[s].name << " " << st[s].number << " " << st[s].major << " " << st[s].city << " " << st[s].grade << endl;


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



//최고평점의 학생
void maxscore(Student s[]) {
	string MAX = "0";
	string NAME = "";
	for (int i = 0; i <= a; i++) {
		if (s[i].grade > MAX) {
			MAX = s[i].grade;
			NAME = s[i].name;
		}


	}
	cout <<"최고평점은 : "<< MAX << " 그 주인공은 : " << NAME << endl;
}
//평점들의 평균
void avscore(Student s[]) {
	double sum = 0;
	for (int i = 0; i <= a; i++) {
		sum += atof(s[i].grade.c_str());


	}
	cout <<"학점평균 : "<< sum / a << endl;
}
void overfour(Student s[]) {
	//4.0넘는 인간들
	int sa = 0;
	for (int i = 0; i <= a; i++) {
		if (atof(s[i].grade.c_str()) > 4) {
			sa++;
		}

	}
	cout <<"4.0넘는 사람들의 수 : "<< sa << "명" << endl;
}

void ilsanin(Student s[]) {
	//일산에 사는 사람의 수는?
	int ilsan = 0;
	for (int i = 0; i <= a; i++) {
		if (s[i].city == "일산") {
			ilsan++;
		}

	}
	cout <<"일산에 사는 사람의 수는 : "<< ilsan << "명" << endl;
}
//가장 많은 학생이 거주하는도시
void mostlive(City s[]) {
	int MAX = 0;
	string NAME = "";
	for (int i = 0; i < countcity - 1; i++) {
		if (s[i].soo > MAX) {
			MAX = s[i].soo;
			NAME = s[i].name;
		}
	}
	cout <<"가장많은 학생이 사는 도시는 : "<<NAME << " " << MAX<<"명"<<endl;

	
}


//어떤학생과 같은도시에사는 학생의이름
void livewith(Student s[], string h) {
	string live;
	int soo=-1;
	cout << h << "와 같은 도시에사는 사람은 : " ;
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

//학과의 수와 이름;
void majorsoo(Major s[]) {
	cout <<"총 학과의 수는"<< countmajor << "개 : ";
	
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
	


	
	

	 // 한 줄씩 읽어서 임시로 저장할 공간

	  // 파일 열기

	if (ifile.is_open())

	{

		while (ifile.getline(line, sizeof(line))) // 한 줄씩 읽어 처리를 시작합니다.
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
				
			}//띄어쓰기 구분
			











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

			}//띄어쓰기 구분
			














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

			}//띄어쓰기 구분

			












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

			}//띄어쓰기 구분

		









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


		//////////////////////////////////////////////////////////////문제//////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		
		printarray(student);
		
		
	
		
		remove(student, "김상윤");
		search(student,"김상윤", 0, a-1);//이진탐색//a는 총학생의 수임
		printarray(student);//프린트
	
        //최고평점의 학생
		maxscore(student);
		//평점들의 평균
		avscore(student);

		//4.0넘는 사람들
		overfour(student);


		//일산에사는 사람의수
		ilsanin(student);
		
		//가장 많은 학생이 거주하는도시
		mostlive(cities);
		
		//어떤학생과 같은도시에사는 학생의이름
		livewith(student,"이호희");
	
		//학과의 수와 이름;
		majorsoo(majors);


		
		




		

		

		
		







	
       

		



		
		






		
		











	}


	
}