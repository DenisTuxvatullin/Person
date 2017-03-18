#pragma once

class CUniversity
{
public:
	CUniversity(std::string university);
	~CUniversity();
	std::string GetName() const;
	void SetName(const std::string& name);
private:
	std::string m_name;
};

