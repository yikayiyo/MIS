#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>



class BookInfoManagement
{
private:
	Interface Face_book;
	Fileoperate Infile_book;  //�ļ�������ʵ�ֶ�������
	Fileoperate OutFile_book; //�ļ�������ʵ��д�빦��
public:
	void BookInfoManage();     //��Ϣ����
	void InBookFile();		  //�����ļ�
	void OutBookFile();		  //д���ļ�
	void AllBookShow();		  //��Ϣչʾ
	int SwitchFunction (int); //����ѡ��
};