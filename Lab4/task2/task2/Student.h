#pragma once
#include "Person.h"
#include "University.h"
#include <memory>

class CStudent :
	public CPerson
{
public:
	CStudent(string name, bool isMale,
		int age, int weight, int growth,
		const shared_ptr<CUniversity> university, int studyYear)
		:CPerson(name, isMale, age, weight, growth), m_university(university)
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

	~CStudent()
	{}

	void SetYearOfStudy(int studyYear)
	{
		if (studyYear >= MIN_YEAR && studyYear <= MAX_YEAR && studyYear > m_studyYear)
		{
			m_studyYear = studyYear;
		}
	}

	void SetUniversity(const weak_ptr<CUniversity> university)
	{
		m_university = university;
	}

	shared_ptr<CUniversity> GetUniversity() const
	{
		return m_university.lock();
	}

	int GetYearOfStudy() const
	{
		return m_studyYear;
	}
	
private:
	const int MAX_YEAR = 5;
	const int MIN_YEAR = 1;
	int m_studyYear;
	weak_ptr<CUniversity> m_university;
};

