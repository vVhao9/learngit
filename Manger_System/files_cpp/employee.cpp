#include"employee.h"

Employee:: Employee(int id, std::string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Employee::showInfo()
{
	std::cout << "ְ�����:" << this->m_Id;
	std::cout << "\tְ������:" << this->m_Name;
	std::cout << "\tְ����λ:" << this->getDepName();
	std::cout << "\t��λְ��:" << this->getDuty();
	std::cout << std::endl;
}

std::string Employee ::getDepName()
{
	return std::string("Ա��");
}

std::string Employee::getDuty()
{
	return std::string("��ɾ�����������");
}