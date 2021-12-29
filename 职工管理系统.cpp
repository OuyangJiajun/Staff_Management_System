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
		/*测试代码
		Worker* worker = new Employee(1, "张三", 1);
		worker->showInfo();
		delete worker;
		worker = new Manager(2, "李四", 2);
		worker->showInfo();
		delete worker;
		worker = new Boss(3, "王五", 3);
		worker->showInfo();
		delete worker;
		*/
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
		case 2://显示职工
			break;
		case 3://删除职工
			break;
		case 4://修改职工
			break;
		case 5://查找职工
			break;
		case 6://排序职工
			break;
		case 7://清空文件
			break;
		default:
			break;
		}
	}
}