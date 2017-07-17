#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Parenthesis {
public:
	string name;
	char p;
};
class Stack {

	Parenthesis type1[100];
	Parenthesis type2[100];
	Parenthesis type3[100];
	int onum = 1;
	int cnum = 1;
	int ty1 = 0;
	int ty2 = 0;
	int ty3 = 0;
public:
	Parenthesis *s = new Parenthesis[1000];
	int size;
	int top;


public:
	Stack() {
		size = 1000;
		top = -1;



	}


	bool isEmpty() const { return top == -1; }
	bool isFull() const { return top == size - 1; }
public:
	Parenthesis pop() {
		

		return s[top--];
	}

	void push(char par) {
		Parenthesis a;

		a.p = par;



		if (a.p == '(' || a.p == '{' || a.p == '[') {
			a.name = "o_" + to_string(onum++);
			s[++top] = a;
			
		}
		else if (a.p == ')') {
			
			a.name = "c_" + to_string(cnum++);
			s[++top] = a;
			if (s[top - 1].p == '['|| s[top - 1].p == '{') {
				pop();
				type2[ty2++] = pop();
			}
			else if (s[top - 1].p == '(') {
				pop();
				pop();
			}
			else {
				

			}
		}
		else if (a.p == '}') {
			a.name = "c_" + to_string(cnum++);
			s[++top] = a;
			if (s[top - 1].p == '[' || s[top - 1].p == '(') {
				pop();

				type2[ty2++] = pop();
			}
			else if (s[top - 1].p == '{') {
				pop();
				pop();
			}
			else {
				

			}
		}
		else if (a.p == ']') {
			a.name = "c_" + to_string(cnum++);
			s[++top] = a;
			if (s[top - 1].p == '(' || s[top - 1].p == '{') {
				pop();

				type2[ty2++] = pop();
			}
			else if (s[top - 1].p == '[') {
				pop();
				pop();
			}
			else {
				
				

			}
		}
		else if (isFull()) {
			cout << "Stack is full" << endl;
			exit;
		}

	}
	void gettype13() {
		
		int i = 0;
		while (i<=top) {
			if (s[i].p == '(' || s[i].p == '{' || s[i].p == '[') {
				type1[ty1++] = s[i];
				i++;
			}
			else if (s[i].p == ')' || s[i].p == '}' || s[i].p == ']') {
				type3[ty3++] = s[i];
				i++;
			}
			else {
				
			}
			

		}

	}
	void show() {
		for (int i = 0; i <= ty1; i++) {
			cout << type1[i].name;
		}
		cout << endl;

		for (int i = 0; i <= ty2; i++) {
			cout << type2[i].name;
		}
		cout << endl;
		for (int i = 0; i <= ty3; i++) {
			cout << type3[i].name;
		}
	}

};

class Readtxt {
public:
	Stack stack;
	Readtxt(string a) {
		char line[1000];
		

		ifstream file;
		file.open(a);

		if (file.is_open()) {
			while (file.getline(line, sizeof(line))) {
				int b = 0;
				while (line[b] != NULL) {
					stack.push(line[b]);
					


					b++;
				}
			}

		}
	}



};








int main() {
	Stack s;
	Readtxt a("input.txt");
	a.stack.gettype13();
	a.stack.show();
	cout << endl;
	for (int i = 0; i <= a.stack.top; i++) {
		cout << a.stack.s[i].p;
	}
	


	return 0;
}