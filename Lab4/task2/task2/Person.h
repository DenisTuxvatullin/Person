#pragma once
#include <string>
class CPerson
{
public:
	CPerson(std::string name, bool isMale, int age, int weight, int growth);
	~CPerson();
	std::string GetName() const;
	bool IsMale() const;
	int GetAge() const;
	int GetGrowth() const;
	int GetWeight() const;
	void SetAge(int age);
	void SetName(std::string name);
	void SetGrowth(int growth);
	void SetWeight(int weight);

private:
	std::string m_name;
	int m_growth, m_weight, m_age;
	bool m_isMale;
};

