#pragma once
#include<fstream>
#include<string>
#include "Book.h"
#include "Student.h"
#include"Borrow.h"
#include"Reserve.h"

const char book_filename[] = "Bookdata.txt";
const char student_filename[] = "Studentdata.txt";
const char login_filename[] = "Login.txt";
const char borrow_filename[] = "Borrowdata.txt";
const char reserve_filename[] = "Reservedata.txt";

class Fileoperate
{
public:
	int Filecinbook();							//��ȡ�ļ�
	int Filecinstudent();
	int Filecinborrow();
	int Filecinreserve();
	int Filecout(Book);							//д���ļ�
	int Filecout(Student);
	int Filecout(Borrow);
	int Filecout(Reserve);

	void Closefile();							//�ر��ļ���

	void open_in_bookfile();					//��ȡ���ļ��ж�
	void open_in_studentfile();
	void open_in_borrowfile();
	void open_in_reservefile();

	void open_out_bookfile();					//д����ļ��ж�
	void open_out_studentfile();
	void open_out_borrowfile();
	void open_out_reservefile();

	Book Getbook() { return book; }				//��ȡ�����
	Student Getstudent() { return student; }	//��ȡѧ������
	Borrow Getborrow() { return borrow; }
	Reserve Getreserve(){ return reserve; }
	int GetIdentity(string,string);				//��ȡ�û���ʶ0.��½ʧ��1.ѧ��2.����Ա
private:
	fstream file;								//�ļ���
	int Judge();								//�ļ��Ƿ�ɹ���
	
	Book book;
	Student student;
	Borrow borrow;
	Reserve reserve;
};