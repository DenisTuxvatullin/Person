#pragma once

class CUniversity
{
public:
	CUniversity(std::string university);
	~CUniversity();
	std::string GetName() const;
	void SetName(std::string name);

private:
	std::string m_name;
};

