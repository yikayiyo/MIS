#pragma once
#include<fstream>
#include<string>
#include "Book.h"
#include "Student.h"

const char book_filename[] = "Bookdata.txt";
const char student_filename[] = "Studentdata.txt";

class Fileoperate
{
public:
	int Filecinbook();							//д���ļ�
	int Filecinstudent();
	int Filecout(Book);							//�����ļ�
	int Filecout(Student);
	void Closefile();							//�ر��ļ���
	void open_in_bookfile();					//д����ļ��ж�
	void open_in_studentfile();
	void open_out_bookfile();					//�������ļ��ж�
	void open_out_studentfile();
	Book Getbook() { return book; }				//��ȡ�����
	Student Getstudent() { return student; }
private:
	fstream file;								//�ļ���
	Book book;
	Student student;
	int Judge();								//�ļ��Ƿ�ɹ���
};