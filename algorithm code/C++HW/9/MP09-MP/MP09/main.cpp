#include <iostream>
#include "MovieMediaManager.h"

int main()
{
	MovieMediaManager m;

	std::cout << "Load MovieMedia.data\n";
	m.load("MovieMedia.data");
	std::cout << "******************************\n";
	std::cout << "MovieMedia.data ���� ���\n";
	m.printAllMovieMedias();
	std::cout << "******************************\n";
	m.load("TestMovieMedia.data");
	std::cout << "TestMovieMedia.data ���� ���\n";
	m.printAllMovieMedias();
	
	MovieMedia mm("File", "Attila Marcel", "���� ���罺Ʈ�� �������", 
		          "Sylvain Chomet", "Guillaume Gouix; Anne Le Ny; Bernadette Lafont; Helene Vincent", 
		          2013, "Korean", "�������罺Ʈ�Ǻ������_NonDRM_[HD].mp4", "HD");
				  
	std::cout << "******************************\n";
	m.add(mm);
	m.remove(3);
	m.save("MovieMedia2.data");
	return 0;
}