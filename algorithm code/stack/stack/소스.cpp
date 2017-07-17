#include<iostream>
using namespace std;

class stack {
	int top;
	int *list = new int[100];
	int num;
public:stack(int a) {
	num = a;
	top = 0;
	for (int i = 0; i < num; i++) {
		list[i] = 0;
	}
}
	   bool isfull() {
		   if (top == num ) {
			   return true;
		   }
		   return false;
	   }
	   bool isempty() {
		   if (top == 0) {
			   return true;
		   }
		   return false;
	   }
	   void put(int a) {
		   if (isfull()) {
			   cout << "꽉찼습니다" << endl;
			   
		   }
		   else {
			   list[top++] = a;
		   }
	   }
	   int pop() {
		   if (isempty()) {
			   cout << "원소가 없습니다." << endl;
		   }
		   else {
			   int k = top - 1;
			   top--;
			   return list[k];
		   }
		   
	   }
	   void show() {
		   for (int i = 0; i < top; i++) {
			   cout << list[i] << " ";
		   }
		   cout << endl;
	   }


};


int main() {
	
	stack stew(5);
	stew.pop();
	stew.put(1);
	stew.put(2);
	stew.put(3);
	stew.put(4);
	stew.put(5);
	stew.show();
	cout << stew.pop() << endl;
	stew.put(2);
	stew.put(2);
}