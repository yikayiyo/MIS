#pragma once
#include<fstream>
#include<string>
#include "Book.h"
#include "Student.h"

const char book_filename[] = "Bookdata.txt";
const char student_filename[] = "Studentdata.txt";
const char login_filename[] = "Login.txt";

class Fileoperate
{
public:
	int Filecinbook();							//��ȡ�ļ�
	int Filecinstudent();
	int Filecout(Book);							//д���ļ�
	int Filecout(Student);

	void Closefile();							//�ر��ļ���

	void open_in_bookfile();					//��ȡ���ļ��ж�
	void open_in_studentfile();

	void open_out_bookfile();					//д����ļ��ж�
	void open_out_studentfile();

	Book Getbook() { return book; }				//��ȡ�����
	Student Getstudent() { return student; }	//��ȡѧ������
	int GetIdentity(string,string);				//��ȡ�û���ʶ0.��½ʧ��1.ѧ��2.����Ա
private:
	fstream file;								//�ļ���
	int Judge();								//�ļ��Ƿ�ɹ���
	Book book;
	Student student;
	
};