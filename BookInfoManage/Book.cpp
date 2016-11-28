#include "Book.h"

void Book::SetInfo(string id, string name, string author, string publisher, string pubdate, int num)
{
	mBookId = id;
	mBookName = name;
	mBookAuthor = author;
	mBookPub = publisher;
	mBookPubDate = pubdate;
	mRemainAmount = num;
}

void Book::Show()
{
	cout << "���:" << index << endl
		<< "��ţ�" << mBookId << "	"
		<< "������" << mBookName << "	"
		<< "���ߣ�" << mBookAuthor << "	"
		<< "�����磺" << mBookPub << "	"
		<< "�������ڣ�" << mBookPubDate << "	"
		<< "ʣ��������" << mRemainAmount << endl << endl;
}
