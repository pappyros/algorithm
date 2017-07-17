#include <iostream>
#include <string>

using namespace std;

class abc
{
public:
	char* a;
	

	abc()
	{
		a = new char[5];
		
		
	}
	void sv() {
		std::cout << "시발롬들";
	}

	abc(const abc& b)
	{
		
		a = b.a;
		
	}
	~abc() {
		delete[] a;
	}
	
};

int main()
{
	string a = "abcd";
	string b;
	b = a;
	std::cout << &a<<" " << &b;


	abc A;
	

	



}