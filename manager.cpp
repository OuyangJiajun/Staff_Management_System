#include"manager.h"

Manager::Manager(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << m_Id << "\tְ��������" << m_Name << "\tְ����λ��" << getDeptName() << "\t��λְ������ϰ�����񣬲��·�����ͨԱ��" << endl;
}

string Manager::getDeptName()
{
	return "����";
}