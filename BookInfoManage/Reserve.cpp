#include "Reserve.h"

void Reserve::SetInfo(string s1, string s2, string s3, string s4, string s5)
{
	mBookId = s1;
	mBookName = s2;
	mStuId = s3;
	mStuName = s4;
	mReserveDate = s5;
}

void Reserve::Show()
{
	cout << "���:" << index << endl
		<< "��ţ�" << mBookId << "	"
		<< "������" << mBookName << "	"
		<< "ѧ�ţ�" << mStuId << "	"
		<< "������" << mStuName << "	"
		<<"ԤԼʱ�䣺"<<mReserveDate
		<<endl << endl;
}
