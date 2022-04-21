#include<iostream>
#include"workerManger.h"
#include"worker.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
int main()
{
	WorkerManger wm;
	int choice;
	while (true)
	{
		wm.Show_Menu();
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_System(); 
			break;
		case 1:
			wm.add_EMp();
			break;
		case 2:
			wm.show_Info();
			break;
		case 3:
			wm.Delete_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_List();
			break;
		case 7:
			wm.Clear_File();
			break;
		default:
			system("cls");
			break;
		}
		
	}
	
	system("pause");
	return 0;
}