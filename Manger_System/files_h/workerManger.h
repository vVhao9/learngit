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

	int m_EmpNum ;  //��¼ְ������
	Worker* * m_Emparray ; //ְ��ָ�������ָ��

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