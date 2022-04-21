#include"Manager.h"

Manager::Manager(int id, std::string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	m_DeptId = deptid;
}

void Manager::showInfo()
{
	std::cout << "职工编号:" << this->m_Id;
	std::cout << "\t职工姓名:" << this->m_Name;
	std::cout << "\t职工岗位:" << this->getDepName();
	std::cout << "\t岗位职责:" << this->getDuty();
	std::cout << std::endl;
}

std::string Manager::getDepName()
{
	return std::string("经理");
}

std::string Manager::getDuty()
{
	return std::string("完成老板分配的任务！");
}