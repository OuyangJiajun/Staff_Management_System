#include "workerManager.h"

workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//1.�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		m_FileIsEmpty = true;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;//��Ҫ��һ��ָ��Ż�ָ���ļ��ڲ���ifs.eof()�Ż�ָ��EOF
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		m_FileIsEmpty = true;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//3.�ļ������Ҳ�Ϊ��
	m_EmpNum = get_EmpNum();
	//cout << "����"<<m_EmpNum<<"��ְ��" << endl;
	m_EmpArray = new Worker*[m_EmpNum];
	init_Emp();//����m_EmpArray����
}

workerManager::~workerManager()
{
	if (m_EmpArray != NULL)
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i] != NULL)
				delete m_EmpArray[i];
		}
		m_EmpNum = 0;
		delete[] m_EmpArray;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
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

int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num=0;
	while (ifs >> id && ifs >> name && ifs >> dId)//�ո����ļ���β������ֹͣ>>���룬������������Ϊ��һ��ְ��
	{
		num++;
	}
	ifs.close();
	return num;
}

void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)//�ո����ļ���β������ֹͣ>>���룬������������Ϊ��һ��ְ��
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id,name,dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void workerManager::Show_Emp()
{
	if (m_EmpNum == 0)
	{
		cout << "ְ��Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			m_EmpArray[i]->showInfo();
		}
	}
	cout << "����������������ز˵�" << endl;
	system("pause");
}

void workerManager::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "ְ��Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ�����" << endl;
		int id;
		cin >> id;
		int index = IsExist(id);
		if (index == -1)
		{
			cout << "�ñ��ְ��������" << endl;
		}
		else
		{
			//�Ѻ����ǰ�Ƹ���
			for (int i = index; i < m_EmpNum - 1; i++)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			// num-1
			m_EmpNum--;
			//��д������ļ�
			save();
			cout << "ɾ���ɹ�" << endl;
		}
	}
	system("pause");
}

int workerManager::IsExist(int id)//���ڷ���ְ���������е�λ�ã������ڷ���-1
{
	int index=-1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (id == m_EmpArray[i]->m_Id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "ְ��Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;
		int index = IsExist(id);
		if (index == -1)
		{
			cout << "�ñ��ְ��������" << endl;
		}
		else
		{
			//����ֱ���޸ģ���Ϊ���ܻ��˸�λ�����ڲ�ͬ�������
			delete m_EmpArray[index];
			int id;
			string name;
			int dId;
			cout << "�������ְ���±��" << endl;
			cin >> id;
			cout << "�������ְ��������" << endl;
			cin >> name;
			while (true)
			{
				cout << "�������ְ���¸�λ���" << endl;
				cout << "1.��ְͨ��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				cin >> dId;
				if (dId == 1 || dId == 2 || dId == 3)
					break;
				else
					cout << "��������ȷ�ĸ�λ���" << endl;
			}
			switch (dId)
			{
			case 1:m_EmpArray[index] = new Employee(id, name, dId);
				break;
			case 2:m_EmpArray[index] = new Manager(id, name, dId);
				break;
			case 3:m_EmpArray[index] = new Boss(id, name, dId);
				break;
			}
			save();
			cout << "�޸ĳɹ�" << endl;
		}
	}
	system("pause");
}

void workerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "ְ��Ϊ��" << endl;
	}
	else
	{
		int select=0;
		while(true)
		{ 
		cout << "�����룺1.����Ų��ң�2.����������" << endl;
		cin >> select;
		if (select == 1 || select == 2)
			break;
		else
			cout << "������������ȷ�Ĳ��ҷ�ʽ" << endl;
		}
		if(select==1)//����Ų���
		{
			cout << "������Ҫ���ҵ�ְ�����" << endl;
			int id;
			cin >> id;
			int index = IsExist(id);
			if (index == -1)
			{
				cout << "�ñ��ְ��������" << endl;
			}
			else
			{
				m_EmpArray[index]->showInfo();
			}
		}
		else//���������ң�������ȫ�����
		{
			cout << "������Ҫ���ҵ�ְ������" << endl;
			string name;
			cin >> name;
			int j = 0;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					m_EmpArray[i]->showInfo();
					j++;
				}
			}
			if (j == 0)
				cout << "��������ְ��������" << endl;
		}
	}
	system("pause");
}

void workerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "ְ��Ϊ��" << endl;
	}
	else
	{
		int select = 0;
		while (true)
		{
			cout << "�����룺1.��ְ���������2.��ְ����Ž���" << endl;
			cin >> select;
			if (select == 1 || select == 2)
				break;
			else
				cout << "������������ȷ������ʽ" << endl;
		}
		if (select == 1)//���������ѡ������
		{
			Worker* temp = NULL;
			for (int round=0;round<m_EmpNum-1;round++)
			{
				int max = 0;//��¼���ı��
				int max_index=0;//��¼����ŵ��±�
				for (int i = 0; i < m_EmpNum-round; i++)
				{
					if (m_EmpArray[i]->m_Id > max)
					{
						max=m_EmpArray[i]->m_Id;
						max_index = i;
					}
				}
				if (max_index != m_EmpNum-round-1)
				{
					temp = m_EmpArray[m_EmpNum-round-1];
					m_EmpArray[m_EmpNum-round-1] = m_EmpArray[max_index];
					m_EmpArray[max_index] = temp;
					temp = NULL;
				}
			}
		}
		else//����Ž���ѡ������
		{
			Worker* temp = NULL;
			for (int round = 0; round < m_EmpNum - 1; round++)
			{
				int min = m_EmpArray[0]->m_Id;//��¼��С�ı��
				int min_index=0;//��¼��С��ŵ��±�
				for (int i = 0; i < m_EmpNum - round; i++)
				{
					if (this->m_EmpArray[i]->m_Id < min)
					{
						min = m_EmpArray[i]->m_Id;
						min_index = i;
					}
				}
				if (min_index != m_EmpNum - round-1)
				{
					temp = m_EmpArray[m_EmpNum - round-1];
					m_EmpArray[m_EmpNum - round-1] = m_EmpArray[min_index];
					m_EmpArray[min_index] = temp;
					temp = NULL;
				}
			}
		}
		/*��׼ѡ������
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
						minOrMax = j;
				}
				else//����
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
						minOrMax = j;
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
				temp = NULL;
			}
		}
		*/
	}
	save();
	cout << "����ɹ�" << endl;
	Show_Emp();
}

void workerManager::Clean_File()
{
	cout << "ȷ�����" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1 || select == 2)
			break;
		else
			cout << "������������������" << endl;
	}
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i] != NULL)
					delete m_EmpArray[i];
			}
			m_EmpNum = 0;
			delete[] m_EmpArray;
			m_EmpArray = NULL;
			m_FileIsEmpty = true;
			cout << "��ճɹ�" << endl;
		}
	}
	system("pause");
}