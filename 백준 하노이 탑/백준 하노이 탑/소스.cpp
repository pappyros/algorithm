#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#pragma warning(disable:4996);
using namespace std;
class BigInteger {
public:
	string number;
	bool sign;
	BigInteger() // empty constructor initializes zero
	{
		number = "0";
		sign = false;
	}
	//-------------------------------------------------------------
	BigInteger(string s) // "string" constructor
	{
		if (isdigit(s[0])) // if not signed
		{
			setNumber(s);
			sign = false; // +ve
		}
		else
		{
			setNumber(s.substr(1));
			sign = (s[0] == '-');
		}
	}
	//-------------------------------------------------------------
	BigInteger(string s, bool sin) // "string" constructor
	{
		setNumber(s);
		setSign(sin);
	}
	//-------------------------------------------------------------
	BigInteger(int n) // "int" constructor
	{
		stringstream ss;
		string s;
		ss << n;
		ss >> s;


		if (isdigit(s[0])) // if not signed
		{
			setNumber(s);
			setSign(false); // +ve
		}
		else
		{
			setNumber(s.substr(1));
			setSign(s[0] == '-');
		}
	}
	//-------------------------------------------------------------
	void setNumber(string s)
	{
		number = s;
	}
	//-------------------------------------------------------------
	const string& getNumber() // retrieves the number
	{
		return number;
	}
	//-------------------------------------------------------------
	void setSign(bool s)
	{
		sign = s;
	}
	//-------------------------------------------------------------
	const bool& getSign()
	{
		return sign;
	}
	//-------------------------------------------------------------
	// returns the absolute value
	BigInteger absolute()
	{
		return BigInteger(getNumber()); // +ve by default
	}
	string add(string number1, string number2)
	{
		string add = (number1.length() > number2.length()) ? number1 : number2;
		char carry = '0';
		int differenceInLength = abs((int)(number1.size() - number2.size()));

		if (number1.size() > number2.size())
			number2.insert(0, differenceInLength, '0'); // put zeros from left

		else// if(number1.size() < number2.size())
			number1.insert(0, differenceInLength, '0');

		for (int i = number1.size() - 1; i >= 0; --i)
		{
			add[i] = ((carry - '0') + (number1[i] - '0') + (number2[i] - '0')) + '0';

			if (i != 0)
			{
				if (add[i] > '9')
				{
					add[i] -= 10;
					carry = '1';
				}
				else
					carry = '0';
			}
		}
		if (add[0] > '9')
		{
			add[0] -= 10;
			add.insert(0, 1, '1');
		}
		return add;
	}
	string subtract(string number1, string number2)
	{
		string sub = (number1.length()>number2.length()) ? number1 : number2;
		int differenceInLength = abs((int)(number1.size() - number2.size()));

		if (number1.size() > number2.size())
			number2.insert(0, differenceInLength, '0');

		else
			number1.insert(0, differenceInLength, '0');

		for (int i = number1.length() - 1; i >= 0; --i)
		{
			if (number1[i] < number2[i])
			{
				number1[i] += 10;
				number1[i - 1]--;
			}
			sub[i] = ((number1[i] - '0') - (number2[i] - '0')) + '0';
		}

		while (sub[0] == '0' && sub.length() != 1) // erase leading zeros
			sub.erase(0, 1);

		return sub;
	}

	//-------------------------------------------------------------
	// multiplies two strings and returns their sum in as a string
	string multiply(string n1, string n2)
	{
		if (n1.length() > n2.length())
			n1.swap(n2);

		string res = "0";
		for (int i = n1.length() - 1; i >= 0; --i)
		{
			string temp = n2;
			int currentDigit = n1[i] - '0';
			int carry = 0;

			for (int j = temp.length() - 1; j >= 0; --j)
			{
				temp[j] = ((temp[j] - '0') * currentDigit) + carry;

				if (temp[j] > 9)
				{
					carry = (temp[j] / 10);
					temp[j] -= (carry * 10);
				}
				else
					carry = 0;

				temp[j] += '0'; // back to string mood
			}

			if (carry > 0)
				temp.insert(0, 1, (carry + '0'));

			temp.append((n1.length() - i - 1), '0'); // as like mult by 10, 100, 1000, 10000 and so on

			res = add(res, temp); // O(n)
		}

		while (res[0] == '0' && res.length() != 1) // erase leading zeros
			res.erase(0, 1);

		return res;
	}
};

string mult(int n, string to) {
	if (n == 0)return "1";
	BigInteger one;
	
	return one.multiply(mult(n - 1, "2"), "2");

}

void func(int num, vector<int>first, vector<int>second, vector<int>third) {
	if (num == 0)return;
	func(num - 1, first, third, second);
	printf("%d %d\n", first[0] / 100, third[0] / 100);
	//cout << first[0]/100<<" "<<third[0]/100 << endl;
	func(num - 1, second, first, third);
	
	

}
int main() {
	vector<int>first;
	vector<int>second;
	vector<int>third;
	
	first.push_back(100);
	second.push_back(200);
	third.push_back(300);
	int num;
	scanf("%d", &num);
	//cin >> num;
	BigInteger one;
	if (num <= 20) {
		for (int i = num; i > 0; i--) {
			first.push_back(i);
		}
		cout <<one.subtract(mult(num, "1"), "1")<<endl;
		func(num, first, second, third);
	}
	else {
		cout << one.subtract(mult(num, "1"), "1") << endl;
		
	}
	
	
	
	
	
}