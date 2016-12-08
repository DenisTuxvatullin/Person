#pragma once
#include "Person.h"
#include "University.h"
#include <memory>
class CStudent: public CPerson
{
public:
	CStudent(string name, bool isMale,
		unsigned short age, unsigned short weight, unsigned short growth,
		const shared_ptr<CUniversity> university, int studyYear)
		:CPerson(age, name, weight, growth,  isMale), m_university(university)
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

	~CStudent();
private:
	const int MAX_YEAR = 5;
	const int MIN_YEAR = 1;
	int m_studyYear;
	weak_ptr<CUniversity> m_university;
};

