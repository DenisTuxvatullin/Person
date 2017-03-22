#pragma once

class CUniversity
{
public:
	CUniversity(const std::string &university);
	std::string GetName() const;
	void SetName(const std::string& name);
private:
	std::string m_name;
};

