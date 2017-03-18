#include "stdafx.h"
#include "University.h"
#include "Student.h"

namespace UniverOperations
{
	bool IsUniversityExist(const std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name);
	void DeleteAllStudentsFromSameUniversity(std::set<std::shared_ptr<CStudent>> &students, std::shared_ptr<CUniversity> &university);
	std::set<std::shared_ptr<CUniversity>> LoadUniversities();
	bool DeleteUniversity(std::set<std::shared_ptr<CUniversity>> &universities, std::shared_ptr<CUniversity> &university, std::set<std::shared_ptr<CStudent>> &students);
	void SaveUniversities(const std::set<std::shared_ptr<CUniversity>> &universities);
	std::string GetUniversityInfo();
	std::shared_ptr<CUniversity> GetUniversity(const std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name);
	bool AddUniversity(std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name);
	void PrintUniversities(const std::set<std::shared_ptr<CUniversity>> &universities);
}

