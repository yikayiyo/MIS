#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"

const int Num_book = 100;		//����鼮�������
static Book book[Num_book];		//���������
static int No_book = 1;			//��Ŵ�1��ʼ
static int Total_book = 0;      //��ǰ�鼮����

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
	void AfterBorrow(string bookid);
	void ReturnBook(string bookid);
	BookInfoManagement() { InBookFile(); }
	string GetBookIdByIndex(int index);
	string GetBookNameByIndex(int index);
	int GetBookAmount(string bid);
};

