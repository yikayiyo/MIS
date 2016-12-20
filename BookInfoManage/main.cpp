#include <iostream>
#include <cstdlib>
#include <string>
#include "BookInfoManagement.h"
#include "StudentInfoManagement.h"
#include"Peroperate.h"
#include"Fileoperate.h"
using namespace std;

Interface face;
Fileoperate operate;
int adminop();
int studentop(string account);
BookInfoManagement bm;

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
				studentop(account);
				break;
			case 2:
				cout << "����Ա"<<account<<"��½�ɹ�����" << endl;
				adminop();
				break;
			}
			break;
		}

	}

	return 1;
}

int adminop()
{
	StudentInfoManagement Student_Info_Manage;
	while (1) {
		int op = face.AdminMainFace();
		switch (op)
		{
		case 1:
			bm.BookInfoManage();
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

int studentop(string account)
{
	Peroperate p;
	while (1)
	{
		p.PersonalOperate(account);
		break;
	}
	return 1;
}
