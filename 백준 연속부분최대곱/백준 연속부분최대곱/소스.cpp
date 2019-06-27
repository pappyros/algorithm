#include<iostream>
#include<algorithm>
#include<cmath>
#include <iomanip>
using namespace std;

double Round(double x, int digit)
{
	return (floor((x)* pow(float(10), digit) + 0.5f) / pow(float(10), digit));
}

int main() {

	int num;
	cin >> num;
	double *arr = new double[num];
	double *mrr = new double[num];
	double imsi=0;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < num;i++) 
	{
		for (int k = i; k < num; k++) 
		{
			if (k == i) 
			{
				mrr[i] = arr[i];
				imsi = arr[i];
				continue;
			}
			imsi = imsi*arr[k];
			if (imsi > mrr[i])
			{
				mrr[i] = imsi;
			}
		}
	}

	sort(mrr, mrr + num);
	cout << fixed;
	cout.precision(3);
	cout << mrr[num-1];

}