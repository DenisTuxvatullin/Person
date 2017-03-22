#pragma once

#include "Person.h"
#include "University.h"

class CStudent :
	public CPerson
{
public:
	CStudent(const std::string &name, bool isMale, int age, int weight, int growth, const std::shared_ptr<CUniversity> university, int studyYear);
	~CStudent();
	void SetYearOfStudy(int studyYear);
	void SetUniversity(const std::weak_ptr<CUniversity> &university);
	std::shared_ptr<CUniversity> GetUniversity() const;
	int GetYearOfStudy() const;
	
private:
	static const int MAX_YEAR = 5;
	static const int MIN_YEAR = 1;
	int m_studyYear;
	std::weak_ptr<CUniversity> m_university;
};

