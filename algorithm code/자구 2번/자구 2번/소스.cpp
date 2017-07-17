#include<iostream>
#include<String>
#include<fstream>
using namespace std;

//����
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
			   cout << "��á���ϴ�" << endl;

		   }
		   else {
			   list[top++] = a;
		   }
	   }
	   char pop() {
		   if (isempty()) {
			   cout << "���Ұ� �����ϴ�." << endl;
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
//��ȣ ��ü 
class paren {
public:
	string num;//open_2 ���� ��ȣ�� ��ȣ�� ���Ծ� ��ȣ�� ��ü�� �̸��� ��Ÿ��
	char parenth;//��ȣ��ü�� ��Ÿ���� ex: )
	int number;//��ȣ�� ��°��
	

};
//��ȣ���� ���� ����
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
			   cout << "��á���ϴ�" << endl;

		   }
		   else {
			   list[top++] = a;
		   }
	   }
	   paren pop() {
		   if (isempty()) {
			   cout << "���Ұ� �����ϴ�." << endl;
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

//�ؽ�Ʈ�� �о���� ���ÿ� �ִ� ��ü���� ������ ����
class read {
public:
	char line[500];//�ؽ�Ʈ�� �о���� �ϳ��� ������ ��
	parenstack open=NULL;//���� ��ȣ�� ���� ����
	parenstack close = NULL;//�ݴ� ��ȣ�� ���� ����
	parenstack type1 = NULL;//Ÿ��1 �� �ش��ϴ� ������ ���� ��ȣ�� ���� ����
	parenstack type2 = NULL;//Ÿ��2 �� �ش��ϴ� ������ ���� ��ȣ�� ���� ����
	parenstack type3 = NULL;//Ÿ��3 �� �ش��ϴ� ������ ���� ��ȣ�� ���� ����
	stack  input = NULL;//����,�ݰ�,��� �ؽ�Ʈ���Ͽ� �����ϴ� ��ȣ�� ���������� ���� ����
	int opennum;//���° ���� ��ȣ������ ��Ÿ���� int��
	int closenum;//���° �ݴ� ��ȣ������ ��Ÿ���� int��

	read(string a) {
		
		stack Stack(200);
		parenstack pa(200), pa1(200), pa2(200), pa3(200), pa4(200);//���� ũ�⸦ 200��ŭ �Ҵ���
		input = Stack;
		open = pa;
		close = pa1;
		type1 = pa2;
		type2 = pa3;
		type3 = pa4;

		ifstream ifile;
		ifile.open(a);
		//������ �����ԵǸ�
		if (ifile.is_open())

		{
			closenum = 1;//closenum�ʱ�ȭ
			opennum = 1;//opennum�ʱ�ȭ

			while (ifile.getline(line, sizeof(line))) // �� �پ� �о� ó���� �����մϴ�.
			{
				int num = 0;
				////���°�ȣ �ϰ��
				while (line[num] != NULL) {
					char letter = line[num];
					if (letter == '(' || letter == '{' || letter == '[') {
						input.push(letter);
						paren op;
						op.num = "open_" + to_string(opennum);//open_2ó�� �̸��� �־��ش�
						op.number = opennum;//��°���� �־��ش�
						opennum++;
						op.parenth = letter;//�̹������� ��ȣ�� �־��ش�
						open.push(op);//��ȣ ��ü�� open���ÿ� �־��ش�
						




					}

					
						//�ݴ� ��ȣ�� �Ӱ��
					if (letter == ')' || letter == '}' || letter == ']') {
						ifclose(letter);
						closenum++;

					}











					num++;//���� ���ڷ� �Ѿ��


				}
			}


		}
		for (int i = 0; i < open.top; i++) {
			//inputstack���� �����ϰ� ���� ��ȣ���� Ÿ��1���� �����Ѵ�
			type1.push(open.list[i]);

		}
		for (int i = 0; i < close.top; i++) {
			//inputstack���� �����ϰ� ���� ��ȣ���� Ÿ��2���� �����Ѵ�
			type3.push(close.list[i]);
		}


	}
	////�ݴ°�ȣ �ϰ��
	void ifclose(char a) {
		
		
			paren cl;
			cl.num = "close_" + to_string(closenum);
			cl.parenth = a;
			cl.number = closenum;
			close.push(cl);
			input.push(a);
			
			//)�δ�����
			if (input.list[input.top - 1] == ')') {
				if (input.list[input.top - 2] == '(') {
					//�̰��� ��ȣ�� �����ϹǷ� ��ǲ���ÿ��� �ΰ��� ���ϰ� ���°� Ŭ����ÿ����� �ѹ��� �����ؼ� �����ش�
					input.pop();
					input.pop();
					open.pop();
					close.pop();
				}
				else if (input.list[input.top - 2] == '{' || input.list[input.top - 2] == '[') {
					//������ ó���Ǿ���� �����̴� ��ǲ���ÿ��� �ΰ��� ���ϰ� ���� ��ȣ�� Ÿ��2���ÿ� Ǫ���Ѵ�
					input.pop();
					input.pop();
					close.pop();
					type2.push(open.pop());//Ÿ��2�� �����Ѵ�
					

				}
				else if (input.list[input.top - 2] == '}' || input.list[input.top - 2] == ']') {
					input.pop();
					input.pop();
					close.pop();
					type3.push(close.pop());
				}
				
			}
			//}�� ������
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
			//]�� ������
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

//������ȣ ���� �ȿ� �ִ� �������� ��Ÿ�� ������ ������
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
