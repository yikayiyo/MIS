#include <iostream>
#include <cstdlib>
#include <string>
#include "BookInfoManagement.h"
#include "StudentInfoManagement.h"
#include"Fileoperate.h"
using namespace std;

Interface face;
Fileoperate operate;
int admin(string account);
int student(string account);
int BorrowBook(string account);


int main()
{
	int identity;										//��ǰ��½��Ա���
	while (1)
	{
		int op= face.MainFace();
		switch (op)
		{
		case 0:
			return 0;
		case 1:
			cout << "�����˺š�����" << endl;
			string account, password;
			cin >> account >> password;
			identity = operate.GetIdentity(account, password);
			
			switch (identity)
			{
			case 0:
				cout << "��½ʧ�ܣ���������...";
				return 1;
			case 1:
				cout << "ѧ��"<<account<<"��½�ɹ�����" << endl;
				student(account);
				break;
			case 2:
				cout << "����Ա"<<account<<"��½�ɹ�����" << endl;
				admin(account);
				break;
			}
			break;
		}

	}

	return 1;
}

int admin(string account)
{
	BookInfoManagement Book_Info_Manage;
	StudentInfoManagement Student_Info_Manage;
	while (1) {
		int op = face.AdminMainFace();
		switch (op)
		{
		case 1:
			Book_Info_Manage.BookInfoManage();
			break;
		case 2:
			Student_Info_Manage.StuInfoManage();
			break;
		case 0:
			return 0;
		}
	}
	return 1;
}

int student(string account)
{
	while (1)
	{
		int op = face.StuMainFace();
		switch (op)
		{
		case 1:
			BorrowBook(account);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			return 0;
		}
	}
	return 1;
}

int BorrowBook(string account)
{
	BookInfoManagement bm;
	fstream f;
	f.open("Bookdata.txt", ios::out);
	bm.SwitchFunction(5);
	cout << "����Ҫ����鼮��ţ�(0.�˳�)" << endl;
	int index;
	cin >> index;
	if (index == 0) return 0;
	else
	{
		int i = 1;
		while (i != index)i++;
		int count_rese = 0;                           //����ԤԼ�˸��������
		string id, name, author, publisher, pubdate;
		int remain;
		f >> id >> name >> author >> publisher >> pubdate >> remain;
		f.close();
		if (remain == 0)
		{
			cout << "���鼮��治�㣬�Ƿ�ѡ��ԤԼ��" << endl;
			char op;
			cin >> op;
			if (op == 'Y' || op == 'y')
				;
				//ReserveBook();
			else
				return 0;
		}
		else							//�п��ʱ��Ҫ��֤�Ƿ�����ԤԼ�˸���
		{
			f.open("Reservedata.txt",ios::out);
			;
		}
	}
	

}