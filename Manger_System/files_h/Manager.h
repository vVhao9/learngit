#pragma once
#include<iostream>
#include"worker.h"

class Manager : public Worker
{
public:
	Manager(int id, std::string name, int deptid);
	virtual void Worker::showInfo();
	virtual std::string Worker::getDepName();
	virtual std::string Worker::getDuty();
};