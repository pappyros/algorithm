#include<iostream>
#include<vector>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int meal, day;
	scanf("%d%d", &meal, &day);
	int *spicy = new int[meal + 1];
	int *sweety = new int[meal + 1];
	for (int i = 1; i <= meal; i++) {
		scanf("%d%d", &spicy[i], &sweety[i]);
	}
}