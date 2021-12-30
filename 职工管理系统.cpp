#include "workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	workerManager workmanager;
	int choice = 0;//代表用户选择
	while(true)
	{
		system("cls");
		workmanager.Show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:workmanager.exitSystem();//退出
			break;
		case 1:workmanager.Add_Emp();//添加职工
			break;
		case 2:workmanager.Show_Emp();//显示职工
			break;
		case 3:workmanager.Del_Emp();//删除职工
			break;
		case 4:workmanager.Mod_Emp();//修改职工
			break;
		case 5:workmanager.Find_Emp();//查找职工
			break;
		case 6:workmanager.Sort_Emp();//排序职工
			break;
		case 7:workmanager.Clean_File();//清空文件
			break;
		default:
			break;
		}
	}
}