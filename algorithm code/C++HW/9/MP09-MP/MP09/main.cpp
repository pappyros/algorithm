#include <iostream>
#include "MovieMediaManager.h"

int main()
{
	MovieMediaManager m;

	std::cout << "Load MovieMedia.data\n";
	m.load("MovieMedia.data");
	std::cout << "******************************\n";
	std::cout << "MovieMedia.data 전부 출력\n";
	m.printAllMovieMedias();
	std::cout << "******************************\n";
	m.load("TestMovieMedia.data");
	std::cout << "TestMovieMedia.data 전부 출력\n";
	m.printAllMovieMedias();
	
	MovieMedia mm("File", "Attila Marcel", "마담 프루스트의 비밀정원", 
		          "Sylvain Chomet", "Guillaume Gouix; Anne Le Ny; Bernadette Lafont; Helene Vincent", 
		          2013, "Korean", "마담프루스트의비밀정원_NonDRM_[HD].mp4", "HD");
				  
	std::cout << "******************************\n";
	m.add(mm);
	m.remove(3);
	m.save("MovieMedia2.data");
	return 0;
}