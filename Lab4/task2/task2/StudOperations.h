#pragma once
#include "University.h"
#include "Student.h"
typedef std::shared_ptr<CStudent> Student;
typedef std::shared_ptr<CUniversity> Univer;

class StudOperations
{
public:
	StudOperations();
	void PrintStudentInfo(const std::shared_ptr<const CStudent> &student);
	void ChangeUniversityForStudent(const Univer &university, std::set<Student> &students, Student &student);
	bool ChangeUniversityName(const std::set<Univer> &universities, const Univer &university, const std::string &newName);
	bool DeleteStudent(std::set<Student> &students, Student &student);
	void PrintStudents(const std::shared_ptr<const CUniversity> &university, const std::set<Student> &students);
	void PrintAllStudents(const std::set<Student> &students);
	void ChangeAge(Student &student, int age);
	void ChangeHeight(Student &student, int growth);
	void ChangeYear(Student &student, int year);
	void AddStudent(std::set<Student> &students, Student &student);
	std::set<Student> LoadStudents(const std::set<Univer> &universities, const std::string &sFilename);
	void SaveStudents(const std::set<Student> &students, const std::string &sFileName);
	std::string GetStudentInfo();
	bool GetChangeableStudent(int &age, int &growth, int &weight, int &studyYear);
	Student GetNewStudent(const std::set<Univer> &universities);
	Student GetStudent(const std::set <Student> &students, const std::string &name);
};