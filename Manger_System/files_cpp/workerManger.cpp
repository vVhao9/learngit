#include"workerManger.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
WorkerManger::WorkerManger()
{	
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	//情况1：文件不存在的情况
	if (!ifs.is_open())
	{
		//std::cout << "此文件不存在！" << std::endl;
		this->m_Emparray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//情况2：文件存在但没有记录
	char test;
	ifs >> test;
	if (ifs.eof())
	{
		//std::cout << "文件存在，但无内容" << std::endl;
		this->m_Emparray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//情况3：文件存在且有数据
	//std::cout << "当前记录人数为: " << this->get_EmpNum() << std::endl;
	this->m_EmpNum = get_EmpNum();
	this->m_Emparray = new Worker * [get_EmpNum()]; //开辟空间存放文件之前的记录到数组中
	this->init_Emp(); 

	/* for (int i = 0; i < get_EmpNum(); i++)
	{
		std::cout << "ID" << this->m_Emparray[i]->m_Id << std::endl;
		std::cout << "姓名" << this->m_Emparray[i]->m_Name << std::endl;
		std::cout << "岗位" << this->m_Emparray[i]->m_DeptId << std::endl;
	} */
}


WorkerManger::~WorkerManger()
{
	if (m_Emparray != NULL)
	{
		delete[] m_Emparray;
		m_Emparray = NULL;
	}
}

void WorkerManger::Show_Menu()
{
	std::cout << "------------------------------" << std::endl;
	std::cout << "|***欢迎使用职工管理系统！***|" << std::endl;
	std::cout << "|*******0.退出管理系统*******|" << std::endl;
	std::cout << "|*******1.增加职工信息*******|" << std::endl;
	std::cout << "|*******2.显示职工信息*******|" << std::endl;
	std::cout << "|*******3.删除离职职工*******|" << std::endl;
	std::cout << "|*******4.修改职工信息*******|" << std::endl;
	std::cout << "|*******5.查找职工信息*******|" << std::endl;
	std::cout << "|*******6.按照编号排序*******|" << std::endl;
	std::cout << "|*******7.清空所有文档*******|" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << std::endl;
}

void WorkerManger::exit_System()
{
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);
}

void WorkerManger::add_EMp()
{	
	system("cls");
	std::cout << "请输入你要添加的员工数量" << std::endl;
	int add_Num = 0;
	std::cin >> add_Num;	
	if (add_Num > 0)
	{
		int newSize = this->m_EmpNum + add_Num;
		Worker* * newArray = new Worker * [newSize];
		if (m_EmpNum>0)
		{
			for (int i = 0; i < newSize; i++)
			{
				newArray[i] = this->m_Emparray[i];
			}
		}
		for (int i = 0; i < add_Num; i++)
		{
			int ID;
			std::string name;
			int DepName;
			
			std::cout << "请输入要添加的第" << i + 1 << "位员工的ID" << std::endl;
			std::cin >> ID;
			std::cout << "请输入要添加的第" << i + 1 << "位员工的姓名" << std::endl;
			std::cin >> name;
			std::cout << "请输入要添加的第" << i + 1 << "位员工的职位" << std::endl;
			std::cout << "1.员工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.老板" << std::endl;
			std::cin >> DepName;

			Worker * worker = NULL;
			switch (DepName)
			{
			case 1:
				worker = new Employee(ID, name, DepName);
				break;
			case 2:
				worker = new Manager(ID, name, DepName);
				break;
			case 3:
				worker = new Boss(ID, name, DepName);
				break;
			default:
				break;
			}
			system("cls");
			newArray[m_EmpNum + i] = worker;
		}
		delete[] m_Emparray;
		this->m_Emparray = newArray;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		std::cout << "添加成功！" << std::endl;
		this->save();
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "输入有误！" << std::endl;
	}

}

void WorkerManger::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);

	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_Emparray[i]->m_Id << "  "
			<< m_Emparray[i]->m_Name << "  ";

		switch (m_Emparray[i]->m_DeptId)
		{
		case 1:
			ofs << std::string("员工") << std::endl;
			break;
		case 2:
			ofs << std::string("经理") << std::endl;
			break;
		case 3:
			ofs << std::string("老板") << std::endl;
			break;
		default:
			std::cout << "输入错误！" << std::endl;
		}	
	}
	ofs.close();
}

int WorkerManger::get_EmpNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	int id;
	std::string EDepName;
	std::string name;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> EDepName)
	{
		num++;
	}

	return num;
}

void WorkerManger::init_Emp()
{
	int num = get_EmpNum();
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	int id;
	std::string name;
	std::string EDepName;
	for (int i = 0; i < num; i++)
	{
		Worker* worker = NULL;
		ifs >> id && ifs >> name && ifs >> EDepName;
		if (EDepName == "员工")
		{
			worker = new Employee(id,name,1);
		}
		else if (EDepName == "经理")
		{
			worker = new Employee(id, name, 2);
		}
		else if (EDepName == "老板")
		{
			worker = new Employee(id, name, 3);
		}
		this->m_Emparray[i] = worker;
	}
	ifs.close();
	return;
}

void WorkerManger::show_Info()
{
	if (m_FileIsEmpty)
	{
		std::cout << "文件为空或不存在！" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_Emparray[i]->showInfo();
		}
	}
		system("pause");
		system("cls");

}

int WorkerManger::EmpIsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_Emparray[i]->m_Id)
		{
			index = i;
			return index;
			break;	
		}
	}
	return index;
}

void WorkerManger::Delete_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件不存在或记录为空！" << std::endl;
	}

	std::cout << "请输入要删除的员工ID" << std::endl;
	int EmpId,index;
	std::cin >> EmpId;
	index = this->EmpIsExist(EmpId);
	if (index == -1)
	{
		std::cout << "删除失败，查无此人！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = index; i < this->m_EmpNum-1; i++)
		{
			this->m_Emparray[i] = this->m_Emparray[i + 1];
		}
		this->m_EmpNum--;
		this->save();
		std::cout << "删除成功！" << std::endl;
		system("pause");
		system("cls");
	}
}

void WorkerManger::Mod_Emp()
{
	if (!this->m_FileIsEmpty)
	{
		std::cout << "请输入要修改的员工编号" << std::endl;
		int Id;
		std::cin >> Id;
		int ret = this->EmpIsExist(Id);
		if (ret != -1)
		{
			delete this->m_Emparray[ret];
			int newid = 0;
			std::string name = "";
			int DId = 0;
			std::cout << "查到" << Id << "号职工，请输入新职工号：" << std::endl;
			std::cin >> newid;
			std::cout << "请输入新姓名:" << std::endl;
			std::cin >> name;
			std::cout << "请输入新职位:" << std::endl;
			std::cout << "1.员工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.老板" << std::endl;
			std::cin >> DId;
			Worker* worker = NULL;
			switch (DId)
			{
			case 1:
				worker = new Employee(newid,name,1);
				break;
			case 2:
				worker = new Manager(newid, name, 2);
				break;
			case 3:
				worker = new Boss(newid, name, 3);
				break;
			default:
				break;
			}
			this->m_Emparray[ret] = worker;
			std::cout << "修改成功！" << std::endl;
			this->save();
		}
		else
		{
			std::cout << "该编号不存在！" << std::endl;
		}
	}
	else
	{
		std::cout << "文件为空或不存在!" << std::endl;
	}
	system("pause");
	system("cls");
}

void WorkerManger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "此文件不存在或内容为空！" << std::endl;
	}
	else
	{
		std::cout << "请选择查找方式：" << std::endl;
		std::cout << "1.按职工ID查找" << std::endl;
		std::cout << "2.按职工姓名查找" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "请要查找的输入职工ID：" << std::endl;
			int id;
			std::cin >> id;
			int index = this->EmpIsExist(id);
			if (index != -1)
			{
				this->m_Emparray[index]->showInfo();
			}
			else
			{
				std::cout << "查无此人！" << std::endl;
			}
		}
		else if (choice == 2)
		{
			std::string name;
			int index = -1;
			std::cout << "请要查找的输入职工姓名：" << std::endl;
			std::cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_Emparray[i]->m_Name)
				{
					index = i;
					this->m_Emparray[index]->showInfo();
				}
				else
				{
					std::cout << "查无此人！" << std::endl;
				}
			}

		}
		else
		{
			std::cout << "输入错误！" << std::endl;
		}
	}
		system("pause");
		system("cls");
}

void WorkerManger::Sort_List()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件为空或不存在！" << std::endl;
	}
	else
	{
		std::cout << "请选择排序方式：" << std::endl;
		std::cout << "1.升序" << std::endl;
		std::cout << "2.降序" << std::endl;
		int choices;
		std::cin >> choices;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int Max_or_Min = i;
			for (int j = i+1; j < m_EmpNum; j++)
			{
				if (choices == 1)
				{
					if (this->m_Emparray[Max_or_Min]->m_Id > this->m_Emparray[j]->m_Id)
					{
						Max_or_Min = j;
					}
				}
				else if (choices == 2)
				{
					if (this->m_Emparray[Max_or_Min]->m_Id < this->m_Emparray[j]->m_Id)
					{
						Max_or_Min = j;
					}
				}
				else
				{
					std::cout << "输入错误！" << std::endl;
					
				}
			}
			if (i != Max_or_Min)
			{
				Worker* temp = m_Emparray[i];
				m_Emparray[i] = m_Emparray[Max_or_Min];
				m_Emparray[Max_or_Min] = temp;
 			}
		}
		std::cout << "排序成功！" << std::endl;
		this->save();
		this->show_Info();
	}
}

void WorkerManger::Clear_File()
{
	std::cout << "确认清空？" << std::endl;
	std::cout << "1.确认" << std::endl;
	std::cout << "2.返回" << std::endl;
	int select;
	std::cin >> select;
	if (select == 1)
	{
		std::ofstream ofs;
		ofs.open(FILENAME, std::ios::trunc);
		ofs.close();

		if (this->m_Emparray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_Emparray[i] != NULL)
				{
					delete m_Emparray[i];
					m_Emparray[i] = NULL;
				}
			}
			delete[] this->m_Emparray;
			this->m_Emparray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		std::cout << "清空完成！" << std::endl;
	}
	system("pause");
	system("cls");
}