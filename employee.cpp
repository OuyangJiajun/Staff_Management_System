#include"employee.h"

Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << m_Id << "\tְ��������" << m_Name << "\tְ����λ��" << getDeptName() <<"\t��λְ����ɾ��������" << endl;
}

string Employee::getDeptName()
{
	return "Ա��";
}