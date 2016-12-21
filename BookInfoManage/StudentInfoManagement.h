#pragma once
#include "Student.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>

const int Num_stu = 100; //���ѧ������
static Student student[Num_stu];	  //ѧ��������
static int No_stu = 1;		  //��Ŵ�1��ʼ
static int Total_stu = 0;       //��ǰѧ������

class StudentInfoManagement
{
private:
	Interface Face_student;
	Fileoperate Infile_student;						//�ļ�������ʵ�ֶ�������
	Fileoperate OutFile_student;					//�ļ�������ʵ��д�빦��
public:
	void StuInfoManage();							//��Ϣ����
	void InStuFile();								//�����ļ�
	void OutStuFile();								//д���ļ�
	void AllStuShow();								//��Ϣչʾ
	int SwitchFunction(int);						//����ѡ��
	StudentInfoManagement() { InStuFile(); }
	string GetNameById(string sid);
	int GetNumById(string id);
	void AfterReturn(string id);
	void AfterBorrow(string id);
};