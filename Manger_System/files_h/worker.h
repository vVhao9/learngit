#pragma once
#include<iostream>
#include<string>

class Worker
{
public:
	virtual void showInfo() = 0;  //��ʾ������Ϣ	
	virtual std::string getDepName() = 0;  //��ȡ��λ��Ϣ
	virtual std::string getDuty() = 0;  //��ȡ��λְ��

	int m_Id;
	std::string m_Name;
	int m_DeptId;
};