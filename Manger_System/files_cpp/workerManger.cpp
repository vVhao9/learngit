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
	//���1���ļ������ڵ����
	if (!ifs.is_open())
	{
		//std::cout << "���ļ������ڣ�" << std::endl;
		this->m_Emparray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//���2���ļ����ڵ�û�м�¼
	char test;
	ifs >> test;
	if (ifs.eof())
	{
		//std::cout << "�ļ����ڣ���������" << std::endl;
		this->m_Emparray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//���3���ļ�������������
	//std::cout << "��ǰ��¼����Ϊ: " << this->get_EmpNum() << std::endl;
	this->m_EmpNum = get_EmpNum();
	this->m_Emparray = new Worker * [get_EmpNum()]; //���ٿռ����ļ�֮ǰ�ļ�¼��������
	this->init_Emp(); 

	/* for (int i = 0; i < get_EmpNum(); i++)
	{
		std::cout << "ID" << this->m_Emparray[i]->m_Id << std::endl;
		std::cout << "����" << this->m_Emparray[i]->m_Name << std::endl;
		std::cout << "��λ" << this->m_Emparray[i]->m_DeptId << std::endl;
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
	std::cout << "|***��ӭʹ��ְ������ϵͳ��***|" << std::endl;
	std::cout << "|*******0.�˳�����ϵͳ*******|" << std::endl;
	std::cout << "|*******1.����ְ����Ϣ*******|" << std::endl;
	std::cout << "|*******2.��ʾְ����Ϣ*******|" << std::endl;
	std::cout << "|*******3.ɾ����ְְ��*******|" << std::endl;
	std::cout << "|*******4.�޸�ְ����Ϣ*******|" << std::endl;
	std::cout << "|*******5.����ְ����Ϣ*******|" << std::endl;
	std::cout << "|*******6.���ձ������*******|" << std::endl;
	std::cout << "|*******7.��������ĵ�*******|" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << std::endl;
}

void WorkerManger::exit_System()
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);
}

void WorkerManger::add_EMp()
{	
	system("cls");
	std::cout << "��������Ҫ��ӵ�Ա������" << std::endl;
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
			
			std::cout << "������Ҫ��ӵĵ�" << i + 1 << "λԱ����ID" << std::endl;
			std::cin >> ID;
			std::cout << "������Ҫ��ӵĵ�" << i + 1 << "λԱ��������" << std::endl;
			std::cin >> name;
			std::cout << "������Ҫ��ӵĵ�" << i + 1 << "λԱ����ְλ" << std::endl;
			std::cout << "1.Ա��" << std::endl;
			std::cout << "2.����" << std::endl;
			std::cout << "3.�ϰ�" << std::endl;
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
		std::cout << "��ӳɹ���" << std::endl;
		this->save();
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "��������" << std::endl;
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
			ofs << std::string("Ա��") << std::endl;
			break;
		case 2:
			ofs << std::string("����") << std::endl;
			break;
		case 3:
			ofs << std::string("�ϰ�") << std::endl;
			break;
		default:
			std::cout << "�������" << std::endl;
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
		if (EDepName == "Ա��")
		{
			worker = new Employee(id,name,1);
		}
		else if (EDepName == "����")
		{
			worker = new Employee(id, name, 2);
		}
		else if (EDepName == "�ϰ�")
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
		std::cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << std::endl;
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
		std::cout << "�ļ������ڻ��¼Ϊ�գ�" << std::endl;
	}

	std::cout << "������Ҫɾ����Ա��ID" << std::endl;
	int EmpId,index;
	std::cin >> EmpId;
	index = this->EmpIsExist(EmpId);
	if (index == -1)
	{
		std::cout << "ɾ��ʧ�ܣ����޴��ˣ�" << std::endl;
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
		std::cout << "ɾ���ɹ���" << std::endl;
		system("pause");
		system("cls");
	}
}

void WorkerManger::Mod_Emp()
{
	if (!this->m_FileIsEmpty)
	{
		std::cout << "������Ҫ�޸ĵ�Ա�����" << std::endl;
		int Id;
		std::cin >> Id;
		int ret = this->EmpIsExist(Id);
		if (ret != -1)
		{
			delete this->m_Emparray[ret];
			int newid = 0;
			std::string name = "";
			int DId = 0;
			std::cout << "�鵽" << Id << "��ְ������������ְ���ţ�" << std::endl;
			std::cin >> newid;
			std::cout << "������������:" << std::endl;
			std::cin >> name;
			std::cout << "��������ְλ:" << std::endl;
			std::cout << "1.Ա��" << std::endl;
			std::cout << "2.����" << std::endl;
			std::cout << "3.�ϰ�" << std::endl;
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
			std::cout << "�޸ĳɹ���" << std::endl;
			this->save();
		}
		else
		{
			std::cout << "�ñ�Ų����ڣ�" << std::endl;
		}
	}
	else
	{
		std::cout << "�ļ�Ϊ�ջ򲻴���!" << std::endl;
	}
	system("pause");
	system("cls");
}

void WorkerManger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "���ļ������ڻ�����Ϊ�գ�" << std::endl;
	}
	else
	{
		std::cout << "��ѡ����ҷ�ʽ��" << std::endl;
		std::cout << "1.��ְ��ID����" << std::endl;
		std::cout << "2.��ְ����������" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "��Ҫ���ҵ�����ְ��ID��" << std::endl;
			int id;
			std::cin >> id;
			int index = this->EmpIsExist(id);
			if (index != -1)
			{
				this->m_Emparray[index]->showInfo();
			}
			else
			{
				std::cout << "���޴��ˣ�" << std::endl;
			}
		}
		else if (choice == 2)
		{
			std::string name;
			int index = -1;
			std::cout << "��Ҫ���ҵ�����ְ��������" << std::endl;
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
					std::cout << "���޴��ˣ�" << std::endl;
				}
			}

		}
		else
		{
			std::cout << "�������" << std::endl;
		}
	}
		system("pause");
		system("cls");
}

void WorkerManger::Sort_List()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << std::endl;
	}
	else
	{
		std::cout << "��ѡ������ʽ��" << std::endl;
		std::cout << "1.����" << std::endl;
		std::cout << "2.����" << std::endl;
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
					std::cout << "�������" << std::endl;
					
				}
			}
			if (i != Max_or_Min)
			{
				Worker* temp = m_Emparray[i];
				m_Emparray[i] = m_Emparray[Max_or_Min];
				m_Emparray[Max_or_Min] = temp;
 			}
		}
		std::cout << "����ɹ���" << std::endl;
		this->save();
		this->show_Info();
	}
}

void WorkerManger::Clear_File()
{
	std::cout << "ȷ����գ�" << std::endl;
	std::cout << "1.ȷ��" << std::endl;
	std::cout << "2.����" << std::endl;
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
		std::cout << "�����ɣ�" << std::endl;
	}
	system("pause");
	system("cls");
}