#pragma once
using namespace std;
#include <string>
class CPerson
{
public:
	CPerson(unsigned short age, string name, unsigned short weight, unsigned short growth, bool isMale);
	~CPerson();
	unsigned short GetAge()const;
	void SetAge(unsigned short age);
	unsigned short GetWeight()const;
	void SetWeight(unsigned short weight);
	unsigned short GetGrowth()const;
	void SetGrowth(unsigned short growth);
	string GetName()const;
	void SetName(string name);
private:
	unsigned short p_age, p_weight, p_growth;
	string p_name;
	bool p_isMale;

};

