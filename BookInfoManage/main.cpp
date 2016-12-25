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
			cout << "�����˺�:" << endl;
			string account, password;
			cin >> account;
			cout << "��������:" << endl;
			cin >> password;
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
	BookInfoManagement bm;
	StudentInfoManagement sm;
	while (1) {
		int op = face.AdminMainFace();
		switch (op)
		{
		case 1:
			bm.BookInfoManage();
			break;
		case 2:
			sm.StuInfoManage();
			break;
		case 0:
			return 0;
		}
	}
	return 1;
}

int studentop(string account)
{
	
	while (1)
	{
		Peroperate::GetInstance().PersonalOperate(account);
		break;
	}
	return 1;
}
