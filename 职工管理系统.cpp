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
		case 2:workmanager.Show_Emp();//��ʾְ��
			break;
		case 3:workmanager.Del_Emp();//ɾ��ְ��
			break;
		case 4:workmanager.Mod_Emp();//�޸�ְ��
			break;
		case 5:workmanager.Find_Emp();//����ְ��
			break;
		case 6:workmanager.Sort_Emp();//����ְ��
			break;
		case 7:workmanager.Clean_File();//����ļ�
			break;
		default:
			break;
		}
	}
}