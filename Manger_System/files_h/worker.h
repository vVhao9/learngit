#pragma once
#include<iostream>
#include<string>

class Worker
{
public:
	virtual void showInfo() = 0;  //显示个人信息	
	virtual std::string getDepName() = 0;  //获取岗位信息
	virtual std::string getDuty() = 0;  //获取岗位职责

	int m_Id;
	std::string m_Name;
	int m_DeptId;
};