#include <iostream>
#include <cstdlib>
#include <string>
#include "BookInfoManagement.h"
using namespace std;


int main()
{
	BookInfoManagement Book_Info_Manage;
	while (1) {
		cout << "1.ͼ����� 2.ѧ������ 0.�˳�" << endl;
		int op;
		cin >> op;
		switch (op)
		{
		case 1:
			Book_Info_Manage.BookInfoMange();
			break;
		case 2:
			break;
		case 0:
			return 1;
		}
	}
	return 1;
}
