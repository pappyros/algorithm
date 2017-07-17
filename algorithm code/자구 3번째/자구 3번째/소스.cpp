#include<iostream>
#include<fstream>
using namespace std;

class read {
public:
	char line[500];//텍스트를 읽어오는 하나의 라인의 수


	read(string a) {
		string tc="";//텍스트파일의 첫줄인 테스트케이스문자열을 읽어올 변수
		int testcase;//위의 문자열을 변환시켜 대입할 변수
		int index = 5;//배열의 최대 인덱스
		int num = 0;//읽어올줄의 인덱스
		
		ifstream ifile;
		ifile.open(a);
		//파일이 열리게되면
		if (ifile.is_open())

		{
			while (ifile.getline(line, sizeof(line))) {
				while (line[num] != NULL) {
					tc += line[num];//숫자를 한자씩대입
					num++;

				}
				testcase = atoi(tc.c_str());//정수변환
				break;


			}
		
			while (ifile.getline(line, sizeof(line))&&testcase>0) // 한 줄씩 읽어 처리를 시작합니다.
			{
				char*train = new char[1000];//동적할당
				num = 0;
				index = 5;
				for (int i = 0; i <=index; i++) {//ABCDEF대입
					train[i] = ('A' + i);
				}
				
				
					while (line[num] != NULL) {
						char letter = line[num];
						if (line[num] == 'C'&&index < 0) {//기차칸이 모자랄 경우
							cout<< "기차칸이 부족합니다";
							break;
						}
						if (line[num] == 'D'&&index <= -1) {//기차칸이 모자랄 경우
							cout<< "기차칸이 부족합니다";
							break;
						}

						if (line[num] == 'A') {//A일경우
							for (int i = index; i >= 0; i--) {
								train[i + 1] = train[i];
							}
							train[0] = 'B';
							index++;
						}
						else if (line[num] == 'B') {//B일경우
							index++;
							train[index] = 'A';


						}
						else if (line[num] == 'C') {//C일경우
							for (int i = 1; i < index; i++) {
								train[i] = train[i + 1];
							}
							index--;

						}
						else if (line[num] == 'D') {//D일경우
							for (int i = 0; i < index; i++) {
								train[i] = train[i + 1];
							}
							index--;

						}
						else if (line[num] == 'E') {//E일경우
							swap(train[0], train[index]);

						}
						else if (line[num] == 'F') {//F일경우
							swap(train[index], train[index - 1]);


						}




						num++;//다음 글자인덱스 증가


					}
					for (int i = 0; i <= index; i++) {
						cout << train[i];//출력
					}
					cout << endl;//한줄띄움
					testcase--;//테스트케이스 감소
				}
				
			}

	}
	
	};


int main() {

	
	read aaa("input.txt");
	
	


}