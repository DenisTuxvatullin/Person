#include "stdafx.h"
#include "Student.h"
CStudent::CStudent(const std::string &name, bool isMale,
		int age, int weight, int growth,
		const std::shared_ptr<CUniversity> university, int studyYear)
	: CPerson(name, isMale, age, weight, growth),
	  m_university(university)
{
	if (studyYear >= MIN_YEAR && studyYear <= MAX_YEAR)
	{
		m_studyYear = studyYear;
	}
	else
	{
		m_studyYear = 1;
	}
}

CStudent::~CStudent()
{}

void CStudent::SetYearOfStudy(int studyYear)
{
	if (studyYear >= MIN_YEAR && studyYear <= MAX_YEAR && studyYear > m_studyYear)
	{
		m_studyYear = studyYear;
	}
}

void CStudent::SetUniversity(const std::weak_ptr<CUniversity> &university)
{
	m_university = university;
}

std::shared_ptr<CUniversity> CStudent::GetUniversity() const
{
	return m_university.lock();
}

int CStudent::GetYearOfStudy() const
{
	return m_studyYear;
}