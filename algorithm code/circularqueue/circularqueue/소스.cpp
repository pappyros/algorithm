#include<iostream>
using namespace std;


class queue {
public:
	int front;
	int rear;
	int num;
	int *list = new int[100];
	int count;
public: queue(int n) {
	int count = 0;
	num = n;
	for (int i = 0; i < num; i++) {
		list[i] = 0;
	}
	front = -1;
	rear = -1;

}
		bool isempty() {
			if (count==0) {
				return true;
			}
			return false;


		}
		bool isfull() {
			if ((num==count)) {
				return true;
			}
			else {
				return false;
			}


		}
		void addq(int a) {
			if (isfull()) {
				cout << "ÀÜ¶à ²ËÃ¡¾î¿ä¤Ì¤Ì" << endl;
				

			}
			else {
				rear = (++rear) % (num);
				list[rear] = a;
				count++;
			}

		}
		int deleteq() {
			if (isempty()) {
				cout << "ÅÖÅÖ ºñ¾ú¾î¿ä" << endl;
				return 0;

			}
			else {
				front = (++front) % (num);
				int k = list[front];
				list[front] = 0;
				count--;
				return k;
			}


		}
		void show() {
			for (int i = 0; i < num; i++) {
				cout << list[i] << " ";
			}
			cout << endl;
		}
		

};


int main() {

	queue sival(5);
	sival.deleteq();
	sival.addq(5);
	sival.addq(8);
	
	sival.addq(7);
	
	sival.addq(1);
	
	sival.addq(1);
	sival.deleteq();
	
	
	sival.addq(4);
	sival.addq(4);
	
	sival.show();


}

