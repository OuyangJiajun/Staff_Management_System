#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Boss::showInfo()
{
	cout << "职工编号：" << m_Id << "\t职工姓名：" << m_Name << "\t职工岗位：" << getDeptName() << "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName()
{
	return "老板";
}