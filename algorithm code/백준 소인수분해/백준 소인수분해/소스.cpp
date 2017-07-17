#include<iostream>
#include<stdio.h>
#pragma warning(disable : 4996)
using namespace std;

int main() {

	int a;
	scanf("%d", &a);
	if (a == 1) {

	}
	else {

		for (int i = 2; i <= a; i++) {
			if (a%i == 0) {

				printf("%d\n", i);
				a = a / i;
				i--;

			}
			else if (i == a) {
				printf("%d\n", a);

				break;
			}
		}
	}
	
}