#include "Student.h"

void Student::SetInfo(string id, string name, string age, string cls, string major, string phone)
{
	mStuId = id;
	mStuName = name;
	mStuAge = age;
	mStuClass = cls;
	mStuMajor = major;
	mStuPhone = phone;
}

void Student::Show()
{
	cout << "���:" << index << endl
		<< "ѧ�ţ�" << mStuId << "	"
		<< "������" << mStuName << "	"
		<< "���䣺" << mStuAge << "	"
		<< "�༶��" << mStuClass << "	"
		<< "רҵ��" << mStuMajor << "	"
		<< "�绰��" << mStuPhone << endl << endl;
}
