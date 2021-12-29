#include "workerManager.h"

workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())//��ʧ���ļ�������
	{
		cout << "�ļ�������" << endl;
		m_FileIsEmpty = true;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		ifs.close();
		system("pause");
		return;
	}
	//char ch;
	//ifs >> ch;
	if (ifs.eof())//�ļ����ڵ�Ϊ��
	{
		cout << "�ļ�Ϊ��" << endl;
		m_FileIsEmpty = true;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		ifs.close();
		system("pause");
		return;
	}
	
}

workerManager::~workerManager()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}

void workerManager::Show_Menu()
{
	cout << "****************************************" << endl;
	cout << "**********    0.�˳��������   *********" << endl;
	cout << "**********    1.����ְ����Ϣ   *********" << endl;
	cout << "**********    2.��ʾְ����Ϣ   *********" << endl;
	cout << "**********    3.ɾ����ְְ��   *********" << endl;
	cout << "**********    4.�޸�ְ����Ϣ   *********" << endl;
	cout << "**********    5.����ְ����Ϣ   *********" << endl;
	cout << "**********    6.���ձ������   *********" << endl;
	cout << "**********    7.��������ĵ�   *********" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void workerManager::Add_Emp()
{
	cout << "���������ְ������" << endl;
	int addNum = 0;//��¼�������
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize=m_EmpNum + addNum;//������Ĵ�С
		Worker** newSpace=new Worker* [newSize];//�����¿ռ�
		//��ԭ����ְ�����鿽������
		if (m_EmpArray != NULL)
		{
			for (int i=0;i<m_EmpNum;i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		//��ʼ�����ְ��
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//ְ����λ
			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������"<<endl;
			cin >> name;
			do{
			cout << "�������" << i + 1 << "����ְ���ĸ�λ"<<endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			if (dSelect == 1 || dSelect == 2 || dSelect == 3)
				break;
			else 
				cout << "������������������" << endl;
			} while (true);
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//��������ְ��ָ�뱣�浽������
			newSpace[m_EmpNum + i] = worker;
		}
		//�ͷž�����
		if (m_EmpArray != NULL)
		{
			delete[] m_EmpArray;//�ͷ�����Ҫ��[]
			m_EmpArray = NULL;
		}
		m_EmpArray = newSpace;//ָ��������
		m_EmpNum = newSize;//����ְ������
		save();//���浽�ļ�
		m_FileIsEmpty = false;//�ļ���Ϊ�գ����²���״̬
		cout << "�ɹ����" << addNum << "λ��ְ��" << endl;
	}
	else
	{
		cout << "������������������" << endl;
	}
	system("pause");
}

void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_Id << " " << m_EmpArray[i]->m_Name <<" "<< m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}