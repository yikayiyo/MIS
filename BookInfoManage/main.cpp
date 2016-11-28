#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
using namespace std;

const int Num_book = 100; //����鼮����
int No_book = 1;		  //��Ŵ�1��ʼ
int Total_book = 0;       //��ǰ�鼮����
Interface Face_book;      //�鼮�������
Fileoperate Infile_book;  //�����ļ�
Fileoperate OutFile_book; //�����ļ�
Book book[Num_book];	  //���������
int switchfun(int);		  //���ܺ���ѡ��
void InBookFile();		  //�����鼮����
void OutBookFile();		  //�����ļ�����
void AllBookShow();		  //��ӡ�鼮��Ϣ
void BookInfoManage();	  //�鼮��Ϣ����

int main()
{
	BookInfoManage();
	return 1;
}

int switchfun(int op_num)
{
	int i;
	string id;
	string name;
	string author;
	string publisher;
	string pubdate;
	int amount;

	if (op_num == 1)							//���
	{
		int num = Face_book.BookAddface();
		if(num==0){	cout << "���˳�.";getchar(); getchar();return 0;}
		for (i = 0; i < num; i++)
		{
			cout << "�����"<<(i+1)<<"���鼮����Ϣ��" << endl;
			cout << "�����鼮��ţ�";
			cin >> id;
			cout << "�����鼮���ƣ�";
			cin >> name;
			cout << "�����鼮���ߣ�";
			cin >> author;
			cout << "��������磺";
			cin >> publisher;
			cout << "����������ڣ�";
			cin >> pubdate;
			cout << "�����棺";
			cin >> amount;
			cout << endl;
			Total_book++;
			book[Total_book - 1].SetIndex(Total_book);
			book[Total_book - 1].SetInfo(id, name, author, publisher, pubdate, amount);
		}
		if (i == num)cout << "�����ɣ�" << endl;
			
	}
	else if (op_num == 2)							//ɾ��
	{
		int no;
		no = Face_book.BookDelface();
		if (no == 0) { cout << "���˳�."; getchar(); getchar(); return 0; }
		for (i = no; i < Total_book; i++) { book[i].SetIndex(i); book[i - 1] = book[i]; }	//�����Ԫ�ظ���ǰ���Ԫ�� 
		cout << endl<<"ɾ���鼮��Ϣ�ɹ���"<<endl;
		cout << "���������...";
		getchar(); getchar();
		Total_book--;
	}
	else if (op_num == 3)							//�޸�
	{
		int no;					//Ҫ�޸ĵ��鼮���,Ϊ0ʱ�˳�
		int item;				//Ҫ�޸ĵ���Ŀ
		int flag=0;
		no = Face_book.BookSetface();
		if (0 == no) { cout << "���˳�."; getchar(); getchar(); return 0; }
		cin >> item;
		switch (item)
		{
		case 0:
			cout << "���˳�"; getchar(); getchar(); return 0;
			break;
		case 1:
			cout << "�����鼮��ţ�";
			book[no - 1].SetBookId();
			break;
		case 2:
			cout << "�����鼮���ƣ�";
			book[no - 1].SetBookName();
			break;
		case 3:
			cout << "�����鼮���ߣ�";
			book[no - 1].SetBookAuthor();
			break;
		case 4:
			cout << "��������磺";
			book[no - 1].SetBookPub();
			break;
		case 5:
			cout << "����������ڣ�";
			book[no - 1].SetBookPubDate();
			break;
		case 6:
			cout << "�����棺";
			book[no - 1].SetBookAmount();
			break;
		case 7:
			cout << "�����鼮��ţ�";
			cin >> id;
			cout << "�����鼮���ƣ�";
			cin >> name;
			cout << "�����鼮���ߣ�";
			cin >> author;
			cout << "��������磺";
			cin >> publisher;
			cout << "����������ڣ�";
			cin >> pubdate;
			cout << "�����棺";
			cin >> amount;
			cout << endl;
			book[no - 1].SetInfo(id, name, author, publisher, pubdate, amount);
			break;
		}

		cout << endl << endl << "������޸ģ����Ϊ��" << endl;
		for (i = 0; i < 110; i++) cout << "-";
		cout << endl;
		book[no - 1].Show();
		for (i = 0; i < 110; i++) cout << "-";
		cout << endl;
		getchar(); getchar();

	}
	else if (op_num == 4)							//��ѯ
	{
		int no;
		int Begin, End;							//��ʼ����Ϊֹ
		int res = 0;							//������������

		string temp;

		no = Face_book.BookSearchface();
		//if (0 == no) { cout << "���˳������������..."; getchar(); getchar(); return 0; }
		int flag = 0;
		switch (no)
		{
		case 0:
		{
			cout << "���˳�."; getchar(); getchar(); return 0;
		}
		case 1:																		//���������
		{
			cout << "��������ţ�";
			cin >> id;
			for (i=0;i<Total_book;i++)
			{
				temp = book[i].GetBookId();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!"<<endl;
			else
			{
				cout <<endl<< "����"<<res<<"����¼��"<<endl;
				res = 0;						//��0
				for (i = 0; i < 110;i++)	cout << "-";
			}
			getchar();
			break;
		}	
		case 2:																		//����������
			cout << "������������";
			cin >> name;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookName();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 3:																		//����������
			cout << "���������ߣ�";
			cin >> author;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookAuthor();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 4:																//������������
			cout << "����������磺";
			cin >> id;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookPub();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 5:																//��������������
			cout << "������������ڣ�";
			cin >> id;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookPubDate();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		}

	}
	else if (op_num == 5)							//��ʾ
	{
		AllBookShow();
	}
	return 1;
}

void BookInfoManage()
{
	int op_num;         //��������
	char op_char;       //ѡ����
	char op_char2;      //�Ƿ񱣴�
	Face_book.BookLoadface(); //���ؽ���

	int flag, nflag=0;
	do {
		flag = 0;
		if (nflag)cout << "���벻�Ϸ����������룺";
		op_char = Face_book.BookInputcharface();
		if (op_char != 'Y'&&op_char != 'y'&&op_char != 'N'&&op_char != 'n')
		{
			flag=1;
			nflag=1;
		}
	} while (flag);

	if (op_char == 'Y' || op_char == 'y')				//�����ļ�
	{
		InBookFile();
		char sub_op_char;
		nflag = 0;
		do
		{
			flag = 0;
			cout << "�Ѿ��ɹ����룬Ҫ��ʾ������(Y/N)";
			cin >> sub_op_char;
			if (sub_op_char != 'Y'&&sub_op_char != 'y'&&sub_op_char != 'N'&&sub_op_char != 'n')
				flag = 1;
		} while (flag);

		if (sub_op_char == 'Y' || sub_op_char == 'y') { AllBookShow();	Face_book.BookSubloadface(); }
	}
	else if(op_char == 'N' || op_char == 'n')
	{
		Face_book.BookSubloadface2();
	}

	while (1)				//����ִ�й���
	{
		if (Total_book != 0) op_num = Face_book.BookOperateface();		//�鼮Ϊ��0ʱ������������
		else op_num = Face_book.BookOperateface2();						//�鼮Ϊ0ʱ��Ҫ��ӣ������ӽ���
		if (op_num == 6) break;
		switchfun(op_num);
		cout << "���������...";
		getchar();
		if (Total_book != 0) Face_book.BookSubloadface();
		else
		{
			cout << endl;
			cout << "�鼮��ĿΪ0��";
			Face_book.BookSubloadface2();
		}
		
	}
	cout << "Ҫ����������(Y/N)";
	cin >> op_char2;

	if (op_char2 == 'Y' || op_char2 == 'y') { OutBookFile();	cout << "�ѱ��棡" << endl; }	//���浽�ļ�
	system("pause");
}

void InBookFile()
{
	int i;
	Infile_book.open_in_bookfile();
	int total = 0;
	while (Infile_book.Filecinbook())
	{
		book[total++] = Infile_book.Getbook();
	}
	Total_book=total-1;
	for (i = 0; i < Total_book; i++)
		book[i].SetIndex(1 + i);
	Infile_book.Closefile();
}

void OutBookFile()
{
	int i;
	OutFile_book.open_out_bookfile();

	for (i=0;i<Total_book;i++)
	{
		OutFile_book.Filecout(book[i]);
	}
	OutFile_book.Closefile();
}

void AllBookShow()
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "��ʾ���";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_book; i++)
		book[i].Show();
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "�����������...";
	getchar(); getchar();
}
