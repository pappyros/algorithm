#ifndef MOVIE_MEDIA_MANAGER_H
#define MOVIE_MEDIA_MANAGER_H

#include <vector>
#include <string>
#include "MovieMedia.h"

class MovieMediaManager
{
public:
	MovieMediaManager();
	MovieMediaManager(const MovieMediaManager& m);

	virtual ~MovieMediaManager() {};

	void load(const std::string& filename);

	void printAllMovieMedias();
	void search(std::string s);
	void add(MovieMedia& m);
	void remove(int row);
	void save(const std::string& fileName);

protected:
	void printAMovieMedia(MovieMedia& b);

	std::vector<MovieMedia> m_MovieMedia;
	int m_Count;
}; 

#endif