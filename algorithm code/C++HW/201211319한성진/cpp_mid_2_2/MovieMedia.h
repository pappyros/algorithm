#pragma once
#include<string>
#ifndef moviemedia


#define moviemedia

class MovieMedia
{
public:
	MovieMedia();


	MovieMedia(std::string type, std::string title, std::string koreanTitle,
		std::string director, std::string actors, int year,
		std::string subtitle, std::string fileName, std::string resolution);

	void setType(std::string type);

	void setTitle(std::string title);

	void setKoreanTitle(std::string koreanTitle);


	void setDirector(std::string director);

	void setActors(std::string actors);

	void setYear(int year);

	void setSubtitle(std::string subtitle);

	void setFileName(std::string fn);


	void setResolution(std::string resolution);

	std::string getType();

	std::string getTitle();

	std::string getKoreanTitle();

	std::string getDirector();

	std::string getActors();

	int getYear();

	std::string getSubtitle();

	std::string getFileName();

	std::string getResolution();

protected:
	std::string m_Type;
	std::string m_Title;
	std::string m_KoreanTitle;
	std::string m_Director;
	std::string m_Actors;
	int m_Year;
	std::string m_Subtitle;
	std::string m_FileName;
	std::string m_Resolution;

};
#endif

