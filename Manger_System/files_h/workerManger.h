#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"

class WorkerManger
{
public:
	WorkerManger();

	void Show_Menu();
	
	void exit_System();

	int m_EmpNum ;  //记录职工人数
	Worker* * m_Emparray ; //职工指针数组的指针

	void add_EMp();

	bool m_FileIsEmpty = false;

	int get_EmpNum();

	void init_Emp();

	void save();

	void show_Info();

	int EmpIsExist(int id);

	void Delete_Emp();

	void Mod_Emp();

	void Find_Emp();

	void Sort_List();

	void Clear_File();

	~WorkerManger();
};