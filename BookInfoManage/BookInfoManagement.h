#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>



class BookInfoManagement
{
private:
	Interface Face_book;
	Fileoperate Infile_book;  //�����ļ�
	Fileoperate OutFile_book; //�����ļ�
public:
	void BookInfoMange();
	void InBookFile();
	void OutBookFile();
	void AllBookShow();
	int SwitchFunction (int);
};