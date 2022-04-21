#include"Boss.h"

Boss::Boss(int id, std::string name, int deptid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = deptid;
}

void Boss::showInfo()
{
	std::cout << "职工编号:" << this->m_Id;
	std::cout << "\t职工姓名:" << this->m_Name;
	std::cout << "\t职工岗位:" << this->getDepName();
	std::cout << "\t岗位职责:" << this->getDuty();
	std::cout << std::endl;
}

std::string Boss::getDepName()
{
	return std::string("老板");
}

std::string Boss::getDuty()
{
	return std::string("躺着挣钱！");
}