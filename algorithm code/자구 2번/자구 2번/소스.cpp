#include<iostream>
#include<String>
#include<fstream>
using namespace std;

//스택
class stack {
public:
	int top;
	char *list = new char[200];
	int num;
public:stack(int a) {
	num = a;
	top = 0;
	for (int i = 0; i < num; i++) {
		list[i] = 0;
	}
}
	   bool isfull() {
		   if (top == num) {
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
	   void push(char a) {
		   if (isfull()) {
			   cout << "꽉찼습니다" << endl;

		   }
		   else {
			   list[top++] = a;
		   }
	   }
	   char pop() {
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
//괄호 객체 
class paren {
public:
	string num;//open_2 같은 괄호의 번호를 포함안 괄호의 전체적 이름을 나타냄
	char parenth;//괄호자체를 나타낸다 ex: )
	int number;//괄호의 번째수
	

};
//괄호들을 넣을 스택
class parenstack {
public:
	int top;
	paren *list = new paren[200];
	int num;
public:parenstack(int a) {
	num = a;
	top = 0;
	
}
	   bool isfull() {
		   if (top == num) {
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
	   void push(paren a) {
		   if (isfull()) {
			   cout << "꽉찼습니다" << endl;

		   }
		   else {
			   list[top++] = a;
		   }
	   }
	   paren pop() {
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
			   cout << list[i].num << " ";
		   }
		   cout << endl;
	   }



};

//텍스트를 읽어오고 스택에 넣는 전체적인 과정을 가짐
class read {
public:
	char line[500];//텍스트를 읽어오는 하나의 라인의 수
	parenstack open=NULL;//여는 괄호를 넣을 스택
	parenstack close = NULL;//닫는 괄호를 넣을 스택
	parenstack type1 = NULL;//타입1 에 해당하는 오류를 가진 괄호를 넣을 스택
	parenstack type2 = NULL;//타입2 에 해당하는 오류를 가진 괄호를 넣을 스택
	parenstack type3 = NULL;//타입3 에 해당하는 오류를 가진 괄호를 넣을 스택
	stack  input = NULL;//열고,닫고,모든 텍스트파일에 존재하는 괄호를 일차적으로 넣을 스택
	int opennum;//몇번째 여는 괄호인지를 나타내는 int값
	int closenum;//몇번째 닫는 괄호인지를 나타내는 int값

	read(string a) {
		
		stack Stack(200);
		parenstack pa(200), pa1(200), pa2(200), pa3(200), pa4(200);//각각 크기를 200만큼 할당함
		input = Stack;
		open = pa;
		close = pa1;
		type1 = pa2;
		type2 = pa3;
		type3 = pa4;

		ifstream ifile;
		ifile.open(a);
		//파일이 열리게되면
		if (ifile.is_open())

		{
			closenum = 1;//closenum초기화
			opennum = 1;//opennum초기화

			while (ifile.getline(line, sizeof(line))) // 한 줄씩 읽어 처리를 시작합니다.
			{
				int num = 0;
				////여는괄호 일경우
				while (line[num] != NULL) {
					char letter = line[num];
					if (letter == '(' || letter == '{' || letter == '[') {
						input.push(letter);
						paren op;
						op.num = "open_" + to_string(opennum);//open_2처럼 이름을 넣어준다
						op.number = opennum;//번째수를 넣어준다
						opennum++;
						op.parenth = letter;//이번에읽은 괄호를 넣어준다
						open.push(op);//괄호 객체를 open스택에 넣어준다
						




					}

					
						//닫는 괄호일 ㅣ경우
					if (letter == ')' || letter == '}' || letter == ']') {
						ifclose(letter);
						closenum++;

					}











					num++;//다음 글자로 넘어간다


				}
			}


		}
		for (int i = 0; i < open.top; i++) {
			//inputstack에서 정리하고 남은 괄호들을 타입1으로 간주한다
			type1.push(open.list[i]);

		}
		for (int i = 0; i < close.top; i++) {
			//inputstack에서 정리하고 남은 괄호들을 타입2으로 간주한다
			type3.push(close.list[i]);
		}


	}
	////닫는괄호 일경우
	void ifclose(char a) {
		
		
			paren cl;
			cl.num = "close_" + to_string(closenum);
			cl.parenth = a;
			cl.number = closenum;
			close.push(cl);
			input.push(a);
			
			//)로닫힐때
			if (input.list[input.top - 1] == ')') {
				if (input.list[input.top - 2] == '(') {
					//이경우는 괄호가 성립하므로 인풋스택에서 두개를 팝하고 오픈과 클로즈스택에서도 한번씩 팝을해서 없애준다
					input.pop();
					input.pop();
					open.pop();
					close.pop();
				}
				else if (input.list[input.top - 2] == '{' || input.list[input.top - 2] == '[') {
					//오류로 처리되어야할 사항이다 인풋스택에서 두개를 팝하고 여는 괄호를 타입2스택에 푸쉬한다
					input.pop();
					input.pop();
					close.pop();
					type2.push(open.pop());//타입2로 간주한다
					

				}
				else if (input.list[input.top - 2] == '}' || input.list[input.top - 2] == ']') {
					input.pop();
					input.pop();
					close.pop();
					type3.push(close.pop());
				}
				
			}
			//}로 닫힐때
			if (input.list[input.top - 1] == '}') {
				if (input.list[input.top - 2] == '{') {
					input.pop();
					input.pop();
					open.pop();
					close.pop();
				}
				else if (input.list[input.top - 2] == '(' || input.list[input.top - 2] == '[') {
					input.pop();
					input.pop();
					type2.push(open.pop());
					close.pop();
					

				}
				else if (input.list[input.top - 2] == ')' || input.list[input.top - 2] == ']') {
					input.pop();
					input.pop();
					close.pop();
					type3.push(close.pop());
				}

			}
			//]로 닫힐때
			if (input.list[input.top - 1] == ']') {
				if (input.list[input.top - 2] == '[') {
					input.pop();
					input.pop();
					open.pop();
					close.pop();
				}
				else if (input.list[input.top - 2] == '{'|| input.list[input.top - 2] == '(') {
					input.pop();
					input.pop();
					type2.push(open.pop());
					close.pop();
					

				}
				else if (input.list[input.top - 2] == '}' || input.list[input.top - 2] == ')') {
					input.pop();
					input.pop();
					close.pop();
					type3.push(close.pop());
				}

			}


		
	
	};
	
};

//오류괄호 스택 안에 있는 오류들을 나타난 순으로 소팅함
void sort(parenstack pstack){
	
	for (int i = 0; i < pstack.top; i++) {
		for (int k = 0; k < pstack.top; k++) {
			if (pstack.list[i].number < pstack.list[k].number){
			swap(pstack.list[i], pstack.list[k]);
			}
		}
	}

}
int main() {
	
	read read("input.txt");
	
	sort(read.type1);
	sort(read.type2);
	sort(read.type3);
	cout << "type1 : ";
    read.type1.show();
	cout << "type2 : ";
	read.type2.show();
	cout << "type3 : ";
	read.type3.show();
	}
