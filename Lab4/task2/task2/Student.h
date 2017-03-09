#pragma once

#include "Person.h"
#include "University.h"
#include <memory>
class CStudent :
	public CPerson
{
public:
	CStudent(std::string name, bool isMale, int age, int weight, int growth, const std::shared_ptr<CUniversity> university, int studyYear);
	~CStudent();
	void SetYearOfStudy(int studyYear);
	void SetUniversity(const std::weak_ptr<CUniversity> university);
	std::shared_ptr<CUniversity> GetUniversity() const;
	int GetYearOfStudy() const;
	
private:
	const int MAX_YEAR = 5;
	const int MIN_YEAR = 1;
	int m_studyYear;
	std::weak_ptr<CUniversity> m_university;
};

