#pragma once
using namespace std;
#include <string>

class CUniversity
{
public:
	CUniversity(string name);
	string GetName()const;
	void SetName(string name);
	~CUniversity();
private:
	string u_name;
};

