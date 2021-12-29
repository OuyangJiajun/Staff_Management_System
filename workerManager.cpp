#include "workerManager.h"

workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())//打开失败文件不存在
	{
		cout << "文件不存在" << endl;
		m_FileIsEmpty = true;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		ifs.close();
		system("pause");
		return;
	}
	//char ch;
	//ifs >> ch;
	if (ifs.eof())//文件存在但为空
	{
		cout << "文件为空" << endl;
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