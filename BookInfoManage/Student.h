#pragma once
#ifndef STUDENT_H
#define STUDENT_H


#include<iostream>
#include<string>
#include "Book.h"
using namespace std;
class Student
{
private:
	int index;
	string mStuId;							//ѧ��
	string mStuName;						//����
	string mStuAge;							//����
	string mStuClass;						//�༶
	string mStuMajor;						//רҵ
	string mStuPhone;						//��ϵ��ʽ
	int mStuBorrow;							//��ǰ��������
	string SysMessage;				    //ϵͳ��Ϣ
		 
public:
	void SetIndex(int i) { index = i; }                       //�����±�
	void SetInfo(string, string, string, string, string,string,int);//�޸ĺ���

	void SetStuId() { cin >> mStuId; }
	void SetStuName() { cin >> mStuName; }
	void SetStuAge() { cin >> mStuAge; };
	void SetStuClass() { cin >> mStuClass; }
	void SetStuMajor() { cin >> mStuMajor; }
	void SetStuPhone() { cin >> mStuPhone; }
	void UpdateBrwAmt() { mStuBorrow--; }
	void Show();

	string GetStuId() {	return mStuId;}
	string GetStuName() { return mStuName; }
	string GetStuAge() { return mStuAge; }
	string GetStuClass() { return mStuClass; }
	string GetStuMajor() { return mStuMajor; }
	string GetStuPhone()	{ return mStuPhone;}
	int GetStuBrwAmt() { return mStuBorrow; }
};
#endif // !STUDENT_H
