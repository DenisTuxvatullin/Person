#pragma once
#include <string>

using namespace std;
class CPerson
{
public:
	CPerson(string name, bool isMale,
		int age, int weight, int growth)
		: m_name(move(name)), m_isMale(isMale),
		m_age(age), m_weight(weight), m_growth(growth)
	{
	}

	~CPerson()
	{
	}

	string GetName() const
	{
		return m_name;
	}

	bool IsMale() const
	{
		return m_isMale;
	}

	int GetAge() const
	{
		return m_age;
	}

	int GetGrowth() const
	{
		return m_growth;
	}

	int GetWeight() const
	{
		return m_weight;
	}

	void SetAge(int age)
	{
		if (age > m_age)
		{
			m_age = age;
		}
	}

	void SetName(string name)
	{
		m_name = move(name);
	}

	void SetGrowth(int growth)
	{
		if (growth > m_growth)
		{
			m_growth = growth;
		}
	}

	void SetWeight(int weight)
	{
		m_weight = weight;
	}

private:
	string m_name;
	int m_growth, m_weight, m_age;
	bool m_isMale;
};

