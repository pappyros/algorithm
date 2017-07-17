#ifndef exce
#define exce
#include<iostream>
using namespace std;
class IndexOutOfRangeException {
public:
	int index;
public:
	IndexOutOfRangeException(int a) {
		index = a;



	}
	void print() {
		cout << index << "is wrong index" << endl;

	}
	/*
	friend ostream& operator<<(ostream& c, const IndexOutOfRangeException& s) {
		c << s.index << "is wrong index";
		return c;

	}*/


}




	
	

	

#endif
