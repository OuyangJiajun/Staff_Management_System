#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << m_Id << "\tְ��������" << m_Name << "\tְ����λ��" << getDeptName() << "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName()
{
	return "�ϰ�";
}