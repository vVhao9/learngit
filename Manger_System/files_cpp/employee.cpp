#include"employee.h"

Employee:: Employee(int id, std::string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Employee::showInfo()
{
	std::cout << "职工编号:" << this->m_Id;
	std::cout << "\t职工姓名:" << this->m_Name;
	std::cout << "\t职工岗位:" << this->getDepName();
	std::cout << "\t岗位职责:" << this->getDuty();
	std::cout << std::endl;
}

std::string Employee ::getDepName()
{
	return std::string("员工");
}

std::string Employee::getDuty()
{
	return std::string("完成经理分配的任务！");
}