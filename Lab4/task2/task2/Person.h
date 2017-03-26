#pragma once
class CPerson
{
public:
	CPerson(const std::string &name, bool isMale, int age, int weight, int growth);
	virtual ~CPerson(void) = default;
	std::string GetName() const;
	bool IsMale() const;
	int GetAge() const;
	int GetGrowth() const;
	int GetWeight() const;
	void SetAge(int age);
	void SetName(const std::string& name);
	void SetGrowth(int growth);
	void SetWeight(int weight);
private:
	std::string m_name;
	int m_growth;
	int m_weight;
	int m_age;
	bool m_isMale;
};

