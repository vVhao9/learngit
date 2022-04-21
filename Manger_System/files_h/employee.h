//∆’Õ®‘±π§
#pragma once
#include"worker.h"
#include<iostream>

class Employee : public Worker
{
public:
	Employee(int id, std::string name, int deptid);
	virtual void Worker::showInfo();
	virtual std::string Worker::getDepName();
	virtual std::string Worker::getDuty();
};