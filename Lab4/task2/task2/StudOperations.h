#include "University.h"
#include "Student.h"

namespace StudOperations
{
	void PrintStudentInfo(const std::shared_ptr<const CStudent> &student);
	void ChangeUniversityForStudent(const std::shared_ptr<CUniversity> &university, std::set<std::shared_ptr<CStudent>> &students, std::shared_ptr<CStudent> &student);
	bool ChangeUniversityName(const std::set<std::shared_ptr<CUniversity>> &universities, const std::shared_ptr<CUniversity> &university, const std::string &newName);
	bool DeleteStudent(std::set<std::shared_ptr<CStudent>> &students, std::shared_ptr<CStudent> &student);
	void PrintStudents(const std::shared_ptr<const CUniversity> &university, const std::set<std::shared_ptr<CStudent>> &students);
	void PrintAllStudents(const std::set<std::shared_ptr<CStudent>> &students);
	void ChangeAge(std::shared_ptr<CStudent> &student, int age);
	void ChangeHeight(std::shared_ptr<CStudent> &student, int growth);
	void ChangeYear(std::shared_ptr<CStudent> &student, int year);
	void AddStudent(std::set<std::shared_ptr<CStudent>> &students, std::shared_ptr<CStudent> &student);
	std::set<std::shared_ptr<CStudent>> LoadStudents(const std::set<std::shared_ptr<CUniversity>> &universities);
	void SaveStudents(const std::set<std::shared_ptr<CStudent>> &students);
	std::string GetStudentInfo();
	void GetChangeableStudent(int &age, int &growth, int &weight, int &studyYear);
	std::shared_ptr<CStudent> GetNewStudent(const std::set<std::shared_ptr<CUniversity>> &universities);
	std::shared_ptr<CStudent> GetStudent(const std::set <std::shared_ptr<CStudent>> &students, const std::string &name);
}