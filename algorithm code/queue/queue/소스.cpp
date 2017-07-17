#include<iostream>
using namespace std;


class queue {
	int front;
	int rear;
	int num;
	int *list = new int[100];
public : queue(int n) {
		num = n;
		for (int i = 0; i < num; i++) {
			list[i] = 0;
		}
		front = -1;
		rear = -1;

	}
	bool isempty() {
		if (rear == front) {
			return true;
		}
		return false;


	}
	bool isfull() {
		if (rear == num - 1) {
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
			list[++rear] = a;
		}

	}
	int deleteq() {
		if (isempty()) {
			cout << "ÅÖÅÖ ºñ¾ú¾î¿ä" << endl;

		}
		else {
			return list[++front];
		}


	}
	void show() {
		for(int i = front + 1; i <= rear; i++) {
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
	sival.addq(1);
	sival.deleteq();
	sival.show();
		

}

