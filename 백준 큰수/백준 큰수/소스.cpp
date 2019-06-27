#include<iostream>
#include<string>
using namespace std;

int num;
int *soo = new int[100];
int money;
string result = "";
void getresult() {
	
	
	for (int i = num; i >= -1; i--) {//큰거부터
	
		if (i == -1) {//다음자리는 못사겠다 전에꺼에서 가장 큰걸 넣자
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
			for (int k = num; k >= 0; k--) {//다음자리 살수 있나?

				


				if (money - soo[i] - soo[k] >= 0) {//다음자리 살수 있다
					
					result += to_string(i);
					money -= soo[i];//돈빼고
					getresult();//다음자리로 가보자
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