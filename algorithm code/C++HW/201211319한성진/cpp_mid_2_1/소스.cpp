#include<iostream>
#include<string>
using namespace std;

class imageFile{
protected:
	string name;
    int byte;
	int hei;
	int wid;
public:
	imageFile(){
		name = "";
		byte = 0;
		hei = 0;
		wid = 0;
	}

	imageFile(string a,int b, int c, int d){
		name = a;
		byte = b;
		hei = c;
		wid = d;

	}
	void setbyte(int a){
		byte = a;

	}

	void setname(string a){
		name = a;
	}
	void sethei(int a){
		hei = a;
	}
	void setwid(int a){
		wid = a;
	}
	string getname(){
		return name;
	}
	int gethei(){
		return hei;
	}
	int getwid(){
		return wid;
	}
	int getbyte(){
		return byte;
	}

	void print(){
		cout << "파일이름:" << name<<" 파일크기:"<<byte<<"byte 해상도:"<<hei*wid<<endl;
	}

};

int main(){

	imageFile im("test.jpg",119000,640,480);
	im.print();


	imageFile arr[2];
	arr[0].setname("test.jpg");
	arr[0].setbyte(119000);
	arr[0].sethei(640);
	arr[0].setwid(480);
	arr[1].setname("test1.jpg");
	arr[1].setbyte(130000);
	arr[1].sethei(800);
	arr[1].setwid(600);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		arr[i].print();
	}

}