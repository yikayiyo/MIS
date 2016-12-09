#include <iostream>
#include <cstdlib>
#include <string>
#include "BookInfoManagement.h"
#include "StudentInfoManagement.h"
#include"Fileoperate.h"
using namespace std;

Interface face;
fstream file;
Fileoperate operate;
int admin();
int student();


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
				student();
				break;
			case 2:
				cout << "����Ա"<<account<<"��½�ɹ�����" << endl;
				admin();
				break;
			}
			break;
		}

	}

	return 1;
}

int admin()
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

int student()
{
	while (1)
	{
		int op = face.StuMainFace();
		switch (op)
		{
		case 1:
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