#include "workerManager.h"

workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//1.文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		m_FileIsEmpty = true;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//2.文件存在但为空
	char ch;
	ifs >> ch;//需要读一下指针才会指向文件内部，ifs.eof()才会指向EOF
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		m_FileIsEmpty = true;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//3.文件存在且不为空
	m_EmpNum = get_EmpNum();
	//cout << "已有"<<m_EmpNum<<"名职工" << endl;
	m_EmpArray = new Worker*[m_EmpNum];
	init_Emp();//读入m_EmpArray数组
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
	cout << "**********    0.退出管理程序   *********" << endl;
	cout << "**********    1.增加职工信息   *********" << endl;
	cout << "**********    2.显示职工信息   *********" << endl;
	cout << "**********    3.删除离职职工   *********" << endl;
	cout << "**********    4.修改职工信息   *********" << endl;
	cout << "**********    5.查找职工信息   *********" << endl;
	cout << "**********    6.按照编号排序   *********" << endl;
	cout << "**********    7.清空所有文档   *********" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void workerManager::Add_Emp()
{
	cout << "请输入添加职工数量" << endl;
	int addNum = 0;//记录添加数量
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize=m_EmpNum + addNum;//新数组的大小
		Worker** newSpace=new Worker* [newSize];//开辟新空间
		//将原来的职工数组拷贝过来
		if (m_EmpArray != NULL)
		{
			for (int i=0;i<m_EmpNum;i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		//开始添加新职工
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//职工岗位
			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名"<<endl;
			cin >> name;
			do{
			cout << "请输入第" << i + 1 << "个新职工的岗位"<<endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			if (dSelect == 1 || dSelect == 2 || dSelect == 3)
				break;
			else 
				cout << "输入有误，请重新输入" << endl;
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
			//将创建的职工指针保存到数组中
			newSpace[m_EmpNum + i] = worker;
		}
		//释放旧数组
		if (m_EmpArray != NULL)
		{
			delete[] m_EmpArray;//释放数组要加[]
			m_EmpArray = NULL;
		}
		m_EmpArray = newSpace;//指向新数组
		m_EmpNum = newSize;//更新职工人数
		save();//保存到文件
		m_FileIsEmpty = false;//文件不为空，更新参数状态
		cout << "成功添加" << addNum << "位新职工" << endl;
	}
	else
	{
		cout << "输入有误，请重新输入" << endl;
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
	while (ifs >> id && ifs >> name && ifs >> dId)//空格换行文件结尾都可以停止>>读入，三个都读入认为是一个职工
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
	while (ifs >> id && ifs >> name && ifs >> dId)//空格换行文件结尾都可以停止>>读入，三个都读入认为是一个职工
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
		cout << "职工为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			m_EmpArray[i]->showInfo();
		}
	}
	cout << "按任意键清屏并返回菜单" << endl;
	system("pause");
}

void workerManager::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "职工为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号" << endl;
		int id;
		cin >> id;
		int index = IsExist(id);
		if (index == -1)
		{
			cout << "该编号职工不存在" << endl;
		}
		else
		{
			//把后面的前移覆盖
			for (int i = index; i < m_EmpNum - 1; i++)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			// num-1
			m_EmpNum--;
			//重写外面的文件
			save();
			cout << "删除成功" << endl;
		}
	}
	system("pause");
}

int workerManager::IsExist(int id)//存在返回职工在数组中的位置，不存在返回-1
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
		cout << "职工为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号" << endl;
		int id;
		cin >> id;
		int index = IsExist(id);
		if (index == -1)
		{
			cout << "该编号职工不存在" << endl;
		}
		else
		{
			//不能直接修改，因为可能换了岗位，属于不同的类对象
			delete m_EmpArray[index];
			int id;
			string name;
			int dId;
			cout << "请输入该职工新编号" << endl;
			cin >> id;
			cout << "请输入该职工新姓名" << endl;
			cin >> name;
			while (true)
			{
				cout << "请输入该职工新岗位编号" << endl;
				cout << "1.普通职工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				cin >> dId;
				if (dId == 1 || dId == 2 || dId == 3)
					break;
				else
					cout << "请输入正确的岗位编号" << endl;
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
			cout << "修改成功" << endl;
		}
	}
	system("pause");
}

void workerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "职工为空" << endl;
	}
	else
	{
		int select=0;
		while(true)
		{ 
		cout << "请输入：1.按编号查找，2.按姓名查找" << endl;
		cin >> select;
		if (select == 1 || select == 2)
			break;
		else
			cout << "请重新输入正确的查找方式" << endl;
		}
		if(select==1)//按编号查找
		{
			cout << "请输入要查找的职工编号" << endl;
			int id;
			cin >> id;
			int index = IsExist(id);
			if (index == -1)
			{
				cout << "该编号职工不存在" << endl;
			}
			else
			{
				m_EmpArray[index]->showInfo();
			}
		}
		else//按姓名查找，重名则全部输出
		{
			cout << "请输入要查找的职工姓名" << endl;
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
				cout << "该姓名的职工不存在" << endl;
		}
	}
	system("pause");
}

void workerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "职工为空" << endl;
	}
	else
	{
		int select = 0;
		while (true)
		{
			cout << "请输入：1.按职工编号升序，2.按职工编号降序" << endl;
			cin >> select;
			if (select == 1 || select == 2)
				break;
			else
				cout << "请重新输入正确的排序方式" << endl;
		}
		if (select == 1)//按编号升序，选择排序
		{
			Worker* temp = NULL;
			for (int round=0;round<m_EmpNum-1;round++)
			{
				int max = 0;//记录最大的编号
				int max_index=0;//记录最大编号的下标
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
		else//按编号降序，选择排序
		{
			Worker* temp = NULL;
			for (int round = 0; round < m_EmpNum - 1; round++)
			{
				int min = m_EmpArray[0]->m_Id;//记录最小的编号
				int min_index=0;//记录最小编号的下标
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
		/*标准选择排序
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
						minOrMax = j;
				}
				else//降序
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
	cout << "排序成功" << endl;
	Show_Emp();
}

void workerManager::Clean_File()
{
	cout << "确认清空" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1 || select == 2)
			break;
		else
			cout << "输入有误请重新输入" << endl;
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
			cout << "清空成功" << endl;
		}
	}
	system("pause");
}