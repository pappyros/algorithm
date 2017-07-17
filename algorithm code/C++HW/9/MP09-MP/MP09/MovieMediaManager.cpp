#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include "MovieMediaManager.h"
#include "MovieMedia.h"
using namespace std;
MovieMediaManager::MovieMediaManager()
{
	m_Count = 0;
}

MovieMediaManager::MovieMediaManager(const MovieMediaManager& m)
{
    m_MovieMedia= m.m_MovieMedia;
	m_Count=m.m_Count;
	
}

void MovieMediaManager::load(const std::string& filename)
{
	m_MovieMedia.clear();

	ifstream in(filename);
	std::string linestr;
	getline(in, linestr);
	m_Count=atoi(linestr.c_str());


	for (int i = 0; i < m_Count; i++) {
		MovieMedia movie;
		getline(in, linestr);
		movie.setType(linestr);
		getline(in, linestr);
		movie.setTitle(linestr);
		getline(in, linestr);
		movie.setKoreanTitle(linestr);
		getline(in, linestr);
		movie.setDirector(linestr);
		getline(in, linestr);
		movie.setActors(linestr);
		getline(in, linestr);
		movie.setYear(atoi(linestr.c_str()));
		getline(in, linestr);
		movie.setSubtitle(linestr);
		getline(in, linestr);
		movie.setFileName(linestr);
		getline(in, linestr);
		movie.setResolution(linestr);
		m_MovieMedia.push_back(movie);
	}
	
}

void MovieMediaManager::printAllMovieMedias() 
{
	for (auto m : m_MovieMedia) {
		printAMovieMedia(m);
	}
}

void MovieMediaManager::search(std::string s) 
{
	for (auto m : m_MovieMedia) {
		for (int i = 0; i < m_Count; i++) {
			if (m.getType().find(s) ||
				m.getTitle().find(s)||
				m.getKoreanTitle().find(s)||
				m.getFileName().find(s) ||
				m.getDirector().find(s)||
				m.getActors().find(s)||
				m.getYear() == atoi(s.c_str()) ||
				m.getSubtitle().find(s)||
				m.getResolution().find(s)



				) {
				printAMovieMedia(m);
			}
		}
	}
	
}

void MovieMediaManager::add(MovieMedia& m)
{
	m_MovieMedia.push_back(m);
}

void MovieMediaManager::remove(int row)
{
	m_MovieMedia.erase(m_MovieMedia.begin() + row);

}

void MovieMediaManager::printAMovieMedia(MovieMedia& b)
{
	std::cout << b;
}

void MovieMediaManager::save(const std::string& fileName)
{
	ofstream of(fileName);
	of << m_Count << endl;
	for (MovieMedia m : m_MovieMedia) {
		
		of<<m.getType()<<endl;
		
		of<<m.getTitle()<<endl;
		
		of<<m.getKoreanTitle()<<endl;
		
		of<<m.getDirector()<<endl;
		
		of<<m.getActors()<<endl;
		
		of << m.getYear()<<endl;
		
		of<<m.getSubtitle()<<endl;
		
		of<<m.getFileName()<<endl;
		
		of<<m.getResolution()<<endl;
	}
	
}