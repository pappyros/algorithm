#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include <iomanip>
using namespace std;

class number {
public:
	int value;
	int index;

};

bool func(number A, number B) {
	return A.value < B.value;
}
int main() {

	
	int num;
	cin >> num;
	int index = 1;
	int max;
	number * nums = new number[num];
	int *result = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> nums[i].value;
		nums[i].index = i + 1;
	}
	sort(nums, nums + num,func);
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			result[i] = index;
			max = nums[i].index;
			

			continue;
		}
		else {
			if (nums[i].index>max) {
				result[i] = result[i - 1] + 1;
				max = nums[i].index;
			}
			else {
				result[i] = result[i - 1];
				max = nums[i].index;


			}

		}
	}

	sort(result, result + num);

	cout << result[num - 1];

	
	

}