#include<iostream>
#include<string>
using namespace std;

int num;
int *soo = new int[100];
int money;
string result = "";
void getresult() {
	
	
	for (int i = num; i >= -1; i--) {//ū�ź���
	
		if (i == -1) {//�����ڸ��� ����ڴ� ���������� ���� ū�� ����
			for (int f = num; f >= 0; f--) {
				if (money - soo[f] >= 0) {
					money -= soo[f];
					
					result += to_string(f);
					break;
				}

			}
			break;
		}
		if (money - soo[i] >= 0) {
			for (int k = num; k >= 0; k--) {//�����ڸ� ��� �ֳ�?

				


				if (money - soo[i] - soo[k] >= 0) {//�����ڸ� ��� �ִ�
					
					result += to_string(i);
					money -= soo[i];//������
					getresult();//�����ڸ��� ������
					break;

				}
			}
		}
	}
}

int main() {
	
	
	
	
	cin >> num;
	num--;
	
	for (int i = 0; i <= num; i++) {
		cin >> soo[i];
	};
	
	cin >> money ;
	getresult();
	
	cout << atoi(result.c_str());
	


	
	 
}