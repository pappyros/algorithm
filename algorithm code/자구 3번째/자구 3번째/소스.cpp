#include<iostream>
#include<fstream>
using namespace std;

class read {
public:
	char line[500];//�ؽ�Ʈ�� �о���� �ϳ��� ������ ��


	read(string a) {
		string tc="";//�ؽ�Ʈ������ ù���� �׽�Ʈ���̽����ڿ��� �о�� ����
		int testcase;//���� ���ڿ��� ��ȯ���� ������ ����
		int index = 5;//�迭�� �ִ� �ε���
		int num = 0;//�о������ �ε���
		
		ifstream ifile;
		ifile.open(a);
		//������ �����ԵǸ�
		if (ifile.is_open())

		{
			while (ifile.getline(line, sizeof(line))) {
				while (line[num] != NULL) {
					tc += line[num];//���ڸ� ���ھ�����
					num++;

				}
				testcase = atoi(tc.c_str());//������ȯ
				break;


			}
		
			while (ifile.getline(line, sizeof(line))&&testcase>0) // �� �پ� �о� ó���� �����մϴ�.
			{
				char*train = new char[1000];//�����Ҵ�
				num = 0;
				index = 5;
				for (int i = 0; i <=index; i++) {//ABCDEF����
					train[i] = ('A' + i);
				}
				
				
					while (line[num] != NULL) {
						char letter = line[num];
						if (line[num] == 'C'&&index < 0) {//����ĭ�� ���ڶ� ���
							cout<< "����ĭ�� �����մϴ�";
							break;
						}
						if (line[num] == 'D'&&index <= -1) {//����ĭ�� ���ڶ� ���
							cout<< "����ĭ�� �����մϴ�";
							break;
						}

						if (line[num] == 'A') {//A�ϰ��
							for (int i = index; i >= 0; i--) {
								train[i + 1] = train[i];
							}
							train[0] = 'B';
							index++;
						}
						else if (line[num] == 'B') {//B�ϰ��
							index++;
							train[index] = 'A';


						}
						else if (line[num] == 'C') {//C�ϰ��
							for (int i = 1; i < index; i++) {
								train[i] = train[i + 1];
							}
							index--;

						}
						else if (line[num] == 'D') {//D�ϰ��
							for (int i = 0; i < index; i++) {
								train[i] = train[i + 1];
							}
							index--;

						}
						else if (line[num] == 'E') {//E�ϰ��
							swap(train[0], train[index]);

						}
						else if (line[num] == 'F') {//F�ϰ��
							swap(train[index], train[index - 1]);


						}




						num++;//���� �����ε��� ����


					}
					for (int i = 0; i <= index; i++) {
						cout << train[i];//���
					}
					cout << endl;//���ٶ��
					testcase--;//�׽�Ʈ���̽� ����
				}
				
			}

	}
	
	};


int main() {

	
	read aaa("input.txt");
	
	


}