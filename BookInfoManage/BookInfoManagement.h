#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>



class BookInfoManagement
{
private:
	Interface Face_book;
	Fileoperate Infile_book;  //�ļ�������ʵ��д�빦��
	Fileoperate OutFile_book; //�ļ�������ʵ�ֶ�������
public:
	void BookInfoManage();     //��Ϣ����
	void InBookFile();		  //д���ļ�
	void OutBookFile();		  //�����ļ�
	void AllBookShow();		  //��Ϣչʾ
	int SwitchFunction (int); //����ѡ��
};