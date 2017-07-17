#include"MovieMedia.h"

MovieMedia::MovieMedia(){
	//		m_Title = "";
	m_Year = 0;
}

MovieMedia::MovieMedia(std::string type, std::string title, std::string koreanTitle,
	std::string director, std::string actors, int year,
	std::string subtitle, std::string fileName, std::string resolution) {
	m_Type = type;
	m_Title = title;
	m_KoreanTitle = koreanTitle;
	m_Director = director;
	m_Actors = actors;
	m_Subtitle = subtitle;
	m_FileName = fileName;
	m_Resolution = resolution;
	m_Year = year;
}


void MovieMedia::setType(std::string type) {
	m_Type = type;
}

void MovieMedia::setTitle(std::string title) {
	m_Title = title;
}

void MovieMedia::setKoreanTitle(std::string koreanTitle) {
	m_KoreanTitle = koreanTitle;
}


void MovieMedia::setDirector(std::string director) {
	m_Director = director;
}

void MovieMedia::setActors(std::string actors) {
	m_Actors = actors;
}

void MovieMedia::setYear(int year) {
	m_Year = year;
}

void MovieMedia::setSubtitle(std::string subtitle) {
	m_Subtitle = subtitle;
}

void MovieMedia::setFileName(std::string fn) {
	m_FileName = fn;
}


void MovieMedia::setResolution(std::string resolution) {
	m_Resolution = resolution;
}

std::string MovieMedia::getType() {
	return m_Type;
}

std::string MovieMedia::getTitle() {
	return m_Title;
}

std::string MovieMedia::getKoreanTitle() {
	return m_KoreanTitle;
}

std::string MovieMedia::getDirector() {
	return m_Director;
}

std::string MovieMedia::getActors() {
	return m_Actors;
}

int MovieMedia::getYear() {
	return m_Year;
}

std::string MovieMedia::getSubtitle() {
	return m_Subtitle;
}

std::string MovieMedia::getFileName() {
	return m_FileName;
}

std::string MovieMedia::getResolution() {
	return m_Resolution;
}