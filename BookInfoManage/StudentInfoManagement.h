#pragma once
#include "Student.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>

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
};