#include "workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	workerManager workmanager;
	int choice = 0;//�����û�ѡ��
	while(true)
	{
		/*���Դ���
		Worker* worker = new Employee(1, "����", 1);
		worker->showInfo();
		delete worker;
		worker = new Manager(2, "����", 2);
		worker->showInfo();
		delete worker;
		worker = new Boss(3, "����", 3);
		worker->showInfo();
		delete worker;
		*/
		system("cls");
		workmanager.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:workmanager.exitSystem();//�˳�
			break;
		case 1:workmanager.Add_Emp();//���ְ��
			break;
		case 2://��ʾְ��
			break;
		case 3://ɾ��ְ��
			break;
		case 4://�޸�ְ��
			break;
		case 5://����ְ��
			break;
		case 6://����ְ��
			break;
		case 7://����ļ�
			break;
		default:
			break;
		}
	}
}