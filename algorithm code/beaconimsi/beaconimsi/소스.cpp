#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class RP {
public:
	float arr[5];
};


int main() {

	RP rp[13];
	rp[1].arr[0] = 69.1507; rp[1].arr[1] = 87.7832; rp[1].arr[2] = 82.6164; rp[1].arr[3] = 80.3617; rp[1].arr[4] = 63.3379;
	rp[2].arr[0] = 76.225; rp[2].arr[1] = 83.4938; rp[2].arr[2] = 76.5625; rp[2].arr[3] = 82.8649; rp[2].arr[4] = 65.019;
	rp[3].arr[0] = 74.9351; rp[3].arr[1] = 83.4416; rp[3].arr[2] = 84.7792; rp[3].arr[3] = 80.1589; rp[3].arr[4] = 64.5933;
	rp[4].arr[0] = 72.1354; rp[4].arr[1] = 78.4093; rp[4].arr[2] = 83.943; rp[4].arr[3] = 76.4762; rp[4].arr[4] = 65.2694;
	rp[5].arr[0] = 77.3459;	rp[5].arr[1] = 83.6288;	rp[5].arr[2] = 85.3788; rp[5].arr[3] = 84.4885; rp[5].arr[4] = 61.9925;
	rp[6].arr[0] = 86.5115;	rp[6].arr[1] = 84.0229; rp[6].arr[2] = 87.6772;	rp[6].arr[3] = 78.0465; rp[6].arr[4] = 70.9771;
	rp[7].arr[0] = 78.3898; rp[7].arr[1] = 81.9181; rp[7].arr[2] = 86.9887; rp[7].arr[3] = 79.3842; rp[7].arr[4] = 65.2486;
	rp[8].arr[0] = 84.5443; rp[8].arr[1] = 85.0759; rp[8].arr[2] = 87.4564; rp[8].arr[3] = 77.8844;	rp[8].arr[4] = 72.0486;
	rp[9].arr[0] = 78.8713;	rp[9].arr[1] = 82.2051;	rp[9].arr[2] = 91.5526;	rp[9].arr[3] = 74.8657;	rp[9].arr[4] = 70.98;
	rp[10].arr[0] = 86.7257; rp[10].arr[1] = 82.3657; rp[10].arr[2] = 87.5657; rp[10].arr[3] = 78.6571; rp[10].arr[4] = 73.7143;
	rp[11].arr[0] = 81.528; rp[11].arr[1] = 78.48; rp[11].arr[2] = 91.0684; rp[11].arr[3] = 75.08; rp[11].arr[4] = 75.128;
	rp[12].arr[0] = 88.6207; rp[12].arr[1] = 81.4069; rp[12].arr[2] = 88.1862; rp[12].arr[3] = 66.0621; rp[12].arr[4] = 75.1448;


	float a, s, d, f, g;
	cin >> a >> s >> d >> f >> g;
	float dap = 9999999;
	int position = 200;
	for (int i = 1; i <= 12; i++) {
		float imsi = pow(rp[i].arr[0] - a, 2) + pow(rp[i].arr[1] - s, 2) + pow(rp[i].arr[2] - d, 2) + pow(rp[i].arr[3] - f, 2) + pow(rp[i].arr[4] - g, 2);
		if (dap > imsi) {
			dap = imsi;
			position = i;
			
	}
	
	}

	cout << position;

}
