#include<iostream>
#include<vector>

using namespace std;
typedef class construct *nptr;
class construct {
public:
	int time, visit;
	vector<nptr>tobuild;

	int findtime(nptr bi) {
		bi->visit = 1;
		int ti = bi->time;
		for (int i = 0; i < bi->tobuild.size(); i++) {
			if (bi->tobuild[i]->visit == 0) {
				ti+=findtime(bi->tobuild[i]);
			}
		}
		return ti;
	}
	void tozero(nptr bi) {
		bi->visit = 0;
		for (int i = 0; i < bi->tobuild.size(); i++) {
			
			tozero(bi->tobuild[i]);
			
		}

	}
};

int main() {

	int n;
	cin >> n;
	int*result = new int[n];
	vector<nptr>buildings;
	for (int i = 0; i < n; i++) {
		construct cons;
		cin >> cons.time;
		while (true) {
			int imsi;
			cin >> imsi;
			if (imsi == -1) {
				break;
			}
			cons.tobuild.push_back(buildings[imsi - 1]);
		}
		buildings.push_back(&cons);
	}
	for (int i = 0; i < n; i++) {
		result[i] = buildings[0]->findtime(buildings[i]);
		cout << result[i] << endl;
		for (int k = 0; k < n; k++) {
		
			buildings[k]->visit = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}



}