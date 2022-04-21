#pragma once
#include<iostream>
#include"worker.h"

class Boss : public Worker
{
public:
	Boss(int id, std::string name, int deptid);
	virtual void Worker::showInfo();
	virtual std::string Worker::getDepName();
	virtual std::string Worker::getDuty();
};