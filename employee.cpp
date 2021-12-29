#include"employee.h"

Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "职工编号：" << m_Id << "\t职工姓名：" << m_Name << "\t职工岗位：" << getDeptName() <<"\t岗位职责：完成经理的任务" << endl;
}

string Employee::getDeptName()
{
	return "员工";
}