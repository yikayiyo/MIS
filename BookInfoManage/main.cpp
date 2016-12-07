#include <iostream>
#include <cstdlib>
#include <string>
#include "BookInfoManagement.h"
#include "StudentInfoManagement.h"
using namespace std;

Interface face;
fstream file;
const char login_filename[] = "login.txt";
string account;
string password;

int Login(string s1, string s2);

int admin();
void student();


int main()
{
	int identity = 0;
	while (1)
	{
		int op= face.MainFace();
		switch (op)
		{
		case 0:
			return 0;
		case 1:
			cout << "�����˺š�����" << endl;
			cin >> account >> password;
			identity = Login(account, password);
			switch (identity)
			{
			case 0:
				cout << "��½ʧ�ܣ���������...";
				return 1;
			case 1:
				cout << "ѧ����½�ɹ�����" << endl;
				//cout << "���� ���� ԤԼ �ҵĽ��� ��ѯ ����....." << endl;
				break;
			case 2:
				cout << "����Ա��½�ɹ�����" << endl;
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

void student()
{

}
int Login(string s1, string s2)						//0:ʧ��1.ѧ��2.����Ա
{
	int res = 0;
	file.open(login_filename, ios::in);
	while (!file.eof())
	{
		string account, password;
		int flag;
		file >> account >> password >> flag;
		if (s1 == account&&s2 == password)
		{
			res = flag;
			break;
		}
	}
	file.close();
	return res;
}