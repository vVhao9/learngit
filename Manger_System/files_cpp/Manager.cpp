#include"Manager.h"

Manager::Manager(int id, std::string name, int deptid)
{
	this->m_Id = id;
	this->m_Name = name;
	m_DeptId = deptid;
}

void Manager::showInfo()
{
	std::cout << "ְ�����:" << this->m_Id;
	std::cout << "\tְ������:" << this->m_Name;
	std::cout << "\tְ����λ:" << this->getDepName();
	std::cout << "\t��λְ��:" << this->getDuty();
	std::cout << std::endl;
}

std::string Manager::getDepName()
{
	return std::string("����");
}

std::string Manager::getDuty()
{
	return std::string("����ϰ���������");
}