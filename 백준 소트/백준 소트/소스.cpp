#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;






int main() {
	int num;
	cin >> num;
	

	vector<int> arr;
	vector<int> vec;
	
	
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
		
		
	}
	sort(arr.begin(), arr.end());


	
	/*
	int max = arr[num - 1];
	
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			vec.push_back(arr[i]);
			arr[i] = max;
			continue;
		}
		for (int k = 1; k < num; k++) {
			if (vec[vec.size()-1] + 1 != arr[k]&&arr[k]!=max) {
				vec.push_back(arr[k]);
				arr[k] = max;
				break;
			}

		}
	}
	sort(arr.begin(), arr.end());
	arr.resize(arr.size() - vec.size());
	
	while (vec.empty() == false) {
		for(arr)




	}*/

	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	


}