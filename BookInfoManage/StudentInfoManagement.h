#pragma once
#include "Student.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>



class StudentInfoManagement
{
private:
	Interface Face_student;
	Fileoperate Infile_student;  //�ļ�������ʵ��д�빦��
	Fileoperate OutFile_student; //�ļ�������ʵ�ֶ�������
public:
	void StuInfoManage();     //��Ϣ����
	void InStuFile();		  //д���ļ�
	void OutStuFile();		  //�����ļ�
	void AllStuShow();		  //��Ϣչʾ
	int SwitchFunction(int); //����ѡ��
};