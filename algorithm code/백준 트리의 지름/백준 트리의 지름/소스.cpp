#include<iostream>
#include<algorithm>

using namespace std;


class human {
public:
	int weight,height;

};

bool function(human a, human b) {
	return a.weight<b.weight;

}


int main() {
	human *hrr = new human[5];

	for (int i = 0; i < 5; i++) {
		cout << "Ű�� �����Ը� �Է��ϼ���" << endl;
		cin >> hrr[i].height >> hrr[i].weight;
	}
	int arr[5] = { 2,5,3,7,8 };
	sort(arr, arr + 5);


	for (int i = 0; i < 5; i++) {
		
		cout << arr[i];
	}




}