#include "Borrow.h"

void Borrow::SetInfo(string s1, string s2, string s3, string s4, string s5, int i)
{
	mBookId = s1;
	mBookName = s2;
	mStuId = s3;
	mStuName = s4;
	mBorrowDate = s5;
	isReturn = i;
}

void Borrow::Show()
{
	cout << "���:" << index << endl
		<< "��ţ�" << mBookId << "	"
		<< "������" << mBookName << "	"
		<< "ѧ�ţ�" << mStuId << "	"
		<< "������" << mStuName << "	"
		<< "�������ڣ�" << mBorrowDate << "	"
		<< "�Ƿ�黹��" << isReturn << endl << endl;
}
