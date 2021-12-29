#include"manager.h"

Manager::Manager(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Manager::showInfo()
{
	cout << "职工编号：" << m_Id << "\t职工姓名：" << m_Name << "\t职工岗位：" << getDeptName() << "\t岗位职责：完成老板的任务，并下发给普通员工" << endl;
}

string Manager::getDeptName()
{
	return "经理";
}