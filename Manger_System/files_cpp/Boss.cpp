#include"Boss.h"

Boss::Boss(int id, std::string name, int deptid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = deptid;
}

void Boss::showInfo()
{
	std::cout << "ְ�����:" << this->m_Id;
	std::cout << "\tְ������:" << this->m_Name;
	std::cout << "\tְ����λ:" << this->getDepName();
	std::cout << "\t��λְ��:" << this->getDuty();
	std::cout << std::endl;
}

std::string Boss::getDepName()
{
	return std::string("�ϰ�");
}

std::string Boss::getDuty()
{
	return std::string("������Ǯ��");
}