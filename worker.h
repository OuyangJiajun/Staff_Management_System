#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ��������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ�����������ƣ���λ���ƣ�
	virtual string getDeptName() = 0;
	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ��ű��,1��Ա����2�Ǿ���3���ϰ�
};
