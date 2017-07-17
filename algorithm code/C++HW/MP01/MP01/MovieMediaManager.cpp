#include"MovieMediaManager.h"
#include<fstream>
#include<iostream>
#include<string>
#include"MovieMedia.h"


MovieMediaManager::MovieMediaManager()
{

	m_Count = 0;

}
MovieMediaManager::MovieMediaManager(const MovieMediaManager& man) {

	int num = man.m_Count;
	m_Count = num;
	m_MovieMedia = new MovieMedia[m_Count];
	for (int i = 0; i < num; i++) {
		m_MovieMedia[i] = man.m_MovieMedia[i];
	}


}
MovieMediaManager::~MovieMediaManager() {
	
	delete[] m_MovieMedia;
}

void MovieMediaManager::load() {
	std::ifstream in("MovieMedia.data");
	std::string linestr;
	getline(in, linestr);
	m_Count = atoi(linestr.c_str());
	m_MovieMedia = new MovieMedia[m_Count];
	for (int i = 0; i < m_Count; i++) {
		getline(in, linestr);
		m_MovieMedia[i].setType(linestr);
		getline(in, linestr);
		m_MovieMedia[i].setTitle(linestr);
		getline(in, linestr);
		m_MovieMedia[i].setKoreanTitle(linestr);
		getline(in, linestr);
		m_MovieMedia[i].setDirector(linestr);
		getline(in, linestr);
		m_MovieMedia[i].setActors(linestr);
		getline(in, linestr);
		m_MovieMedia[i].setYear(atoi(linestr.c_str()));
		getline(in, linestr);
		m_MovieMedia[i].setSubtitle(linestr);
		getline(in, linestr);
		m_MovieMedia[i].setFileName(linestr);
		getline(in, linestr);
		m_MovieMedia[i].setResolution(linestr);
	}
}


void MovieMediaManager::printAllMovieMedias() {
	for (int i = 0; i < m_Count; i++) {
		printAMovieMedia(m_MovieMedia[i]);
	}
}

void MovieMediaManager::search(std::string s) {
	for (int i = 0; i < m_Count; i++) {
		int year = atoi(s.c_str());
		if (year != 0 && m_MovieMedia[i].getYear() == year) {
			printAMovieMedia(m_MovieMedia[i]);
		}
		else {
			if (m_MovieMedia[i].getTitle().find(s) != std::string::npos
				|| m_MovieMedia[i].getKoreanTitle().find(s) != std::string::npos
				|| m_MovieMedia[i].getDirector().find(s) != std::string::npos
				|| m_MovieMedia[i].getActors().find(s) != std::string::npos
				|| m_MovieMedia[i].getFileName().find(s) != std::string::npos
				|| m_MovieMedia[i].getSubtitle().find(s) != std::string::npos
				|| m_MovieMedia[i].getResolution().find(s) != std::string::npos) {
				printAMovieMedia(m_MovieMedia[i]);
			}
		}
	}
};

void MovieMediaManager::printAMovieMedia(MovieMedia b) {
	std::cout << b.getType() << std::endl;
	std::cout << b.getTitle() << std::endl;
	std::cout << b.getKoreanTitle() << std::endl;
	std::cout << b.getDirector() << std::endl;
	std::cout << b.getActors() << std::endl;
	std::cout << b.getYear() << "\n\n";
	std::cout << b.getSubtitle() << std::endl;
	std::cout << b.getFileName() << std::endl;
	std::cout << b.getResolution() << std::endl;
};