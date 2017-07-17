#include <stdio.h>
#include <string.h>


void pointer(char a[], char input) {
	char*ptr1, *ptr2;
	ptr1 = a;
	if (input == '!') {
		for (int i = 0; i < 25; i++) {
			if ((i % 5) + 1 == 1) {
				printf("\n");
			}

			printf("%c", ptr1[i]);
		}


	}
	else if (input == '@') {
		for (int i = 0; i <6; i++) {
			for (int k = 0; k < 25; k++) {
				if ((k % 5) == i) {
					printf("%c", ptr1[k]);
				}

			}
			printf("\n");

		}



	}
	else if (input == '#') {
		int a = 0;
		char B[25];
		for (int i = 0; i < 25; i++) {
			B[i] = 'A' + a++;
		}
		ptr2 = B;

		int num = 0;
		for (int i = 0; i<25; i++) {
			ptr2[num] = ptr1[i];
			if (num % 2 == 0 && num<24) {
				num = num + 2;
			}
			else if (num == 24) {
				num = 23;
			}
			else {
				num = num - 2;
			}

		}
		for (int i = 0; i<25; i++) {
			if ((i % 5) + 1 == 1) {
				printf("\n");
			}

			printf("%c", ptr2[i]);
		}
	}

}


int main(void)
{
	char arr[25] = { '\0' };
	int i = 0;
	char A = 'A';
	
	for (i = 0; i<25; i++) arr[i] = A++;
	printf("문자 입력:");
	
	pointer(arr, '#');
	return 0;
	
}