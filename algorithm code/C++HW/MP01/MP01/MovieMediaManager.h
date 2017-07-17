#pragma once
#include<string>
#include"MovieMedia.h"
#ifndef moviemediamanager
#define moviemediamanager

class MovieMediaManager
{
public:
	MovieMediaManager();
	virtual ~MovieMediaManager();
	MovieMediaManager(const MovieMediaManager& man);
	void load();

	void printAllMovieMedias();

	void search(std::string s);

protected:
	void printAMovieMedia(MovieMedia b);

	MovieMedia *m_MovieMedia;
	int m_Count;
};
#endif // !moviemediamanager