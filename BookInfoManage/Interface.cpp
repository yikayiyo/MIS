#include "Interface.h"

int Interface::AdminMainFace()
{
	cout << "	~~~~~~~~~~~~~~~~~~~~~~�� �� �� ʾ~~~~~~~~~~~~~~~~~~~~~~	" << endl
		<< "	|	1.ͼ�����	2.ѧ������	0.�˳�                 |	" << endl
		<< "	-------------------------------------------------------	" << endl;
	int op_num;
	cin >> op_num;
	return op_num;
}

void Interface::BookLoadFace()
{
	cout << endl << endl;
	cout << "		             ͼ����Ϣ����       					"<<endl << endl;
	cout << "	#######################################################	" << endl;
	cout << "	#                                                     #	"<< endl;
	cout << "	# 1.���ͼ���¼  # 2.ɾ���鼮��¼  # 3.�޸��鼮��Ϣ  #	" << endl;
	cout << "	# 4.��ѯ�鼮��¼  # 5.��ʾͼ���¼  # 6.�˳�          #	"<< endl;
	cout << "	#                                                     #	" << endl;
	cout << "	#######################################################	" << endl;

}

void Interface::StuLoadFace()
{
	cout << endl << endl;
	cout << "		             ѧ����Ϣ����       					" << endl << endl;
	cout << "	#######################################################	" << endl;
	cout << "	#                                                     #	" << endl;
	cout << "	# 1.���ѧ����¼  # 2.ɾ��ѧ����¼  # 3.�޸�ѧ����Ϣ  #	" << endl;
	cout << "	# 4.��ѯѧ����¼  # 5.��ʾѧ����¼  # 6.�˳�          #	" << endl;
	cout << "	#                                                     #	" << endl;
	cout << "	#######################################################	" << endl;

}

void Interface::BookSubLoadFace2()						   //�ļ�Ϊ�գ���Ӽ�¼ʱ�Ľ���
{
	cout << endl << endl;
	cout << "	======================�� �� �� ʾ======================	" << endl
		<< "	|	1.���ͼ���¼	|	6.�˳�                 |	" << endl
		<< "	=======================================================	" << endl;
	cout << endl;
}

void Interface::StuSubLoadFace2()						   //�ļ�Ϊ�գ���Ӽ�¼ʱ�Ľ���
{
	cout << endl << endl;
	cout << "	======================�� �� �� ʾ======================	" << endl
		<< "	|	1.���ѧ����¼	|	6.�˳�                 |	" << endl
		<< "	=======================================================	" << endl;
	cout << endl;
}

void Interface::BookSubLoadFace()
{
	cout << endl << endl;
	cout << "	=======================��  ��  ��  ʾ========================" << endl
		<< "	|  1.���ͼ���¼  |  2.ɾ��ͼ���¼  |   3.�޸�ͼ���¼    |" << endl
		<< "	|  4.��ѯ�鼮��¼  |  5.��ʾ�鼮��¼  |   6.�˳�            |" << endl
		<< "	=============================================================" << endl;
	cout << endl;
}

void Interface::StuSubLoadFace()
{
	cout << endl << endl;
	cout << "	=======================��  ��  ��  ʾ========================" << endl
		<< "	|  1.���ѧ����¼  |  2.ɾ��ѧ����¼  |   3.�޸�ѧ����¼    |" << endl
		<< "	|  4.��ѯѧ����¼  |  5.��ʾѧ����¼  |   6.�˳�            |" << endl
		<< "	=============================================================" << endl;
	cout << endl;
}

char Interface::ReadFromFileFace()
{
	char op;
	cout << "Ҫ�����ļ���(Y/N):";
	cin >> op;
	return op;
}

char Interface::AfterReadFromFileFace()
{
	char temp;
	cout << "�Ѿ��ɹ����룬Ҫ��ʾ������(Y/N)";
	cin >> temp;
	return temp;
}

char Interface::WriteIntoFileFace()
{
	char temp;
	cout << "Ҫ����������(Y/N)";
	cin >> temp;
	return temp;
}

int Interface::OperateFace()						//���ؽ��1-6����ͬ����
{
	string op;
	int flag, nflag;

	do
	{
		flag = 0; nflag = 0;
		if (nflag)
		{
			cout << "������Χ...Again:";
			cin >> op;
		}
		else
		{
			cout << "������Ĳ���: ";
			cin >> op;
		}

		if (op.length() != 1) { flag++; nflag++; }
		if (op[0] > '6' || op[0] < '0') { flag++; nflag++; }
	} while (flag);

	return op[0] - '0';
}

int Interface::OperateFace2()						//�ļ�Ϊ�գ���Ӽ�¼ʱ�Ĳ�����ʾ������1��6
{
	string op;
	int flag, nflag = 0;

	do
	{
		flag = 0;
		if (nflag)
		{
			cout << "������Χ...Again:";
			cin >> op;
		}
		else
		{
			cout << "������Ĳ���: ";
			cin >> op;
		}

		if (op.length() != 1) { flag++; nflag++; }
		if (op[0] != '6' && op[0] != '1') { flag++; nflag++; }
	} while (flag);

	return op[0] - '0';
}

int Interface::AddFace()									//��ӽ��棬����Ҫ��ӵ���Ŀ
{
	int num;
	cout << "������Ҫ��ӵ���Ŀ��(����0�˳�)";
	cin >> num;
	return num;
}


int Interface::DelFace()									//ɾ�����棬�������
{
	int index;
	cout << "������Ҫɾ���ļ�¼��ţ�(����0�˳�)";
	cin >> index;
	return index;
}


int Interface::BookSetFace()								//ͼ�����ý��棬���ؽ�� 0-7
{
	int index;
	cout << "������Ҫ�޸ĵ��鼮���(����0�˳�)";
	cin >> index;
	if (index)
	{
		cout << "Ҫ�޸��Ĳ�����Ϣ��(1.���,2.����,3.����,4.������,5.��������,6.�����,7.ȫ���޸� 0.�˳�)" <<endl;
		cout << "���룺";
	}
	return index;
}

int Interface::StuSetFace()									//ѧ�����ý��棬���ؽ�� 0-7
{
	int index;
	cout << "������Ҫ�޸ĵ�ѧ�����(����0�˳�)";
	cin >> index;
	if (index)
	{
		cout << "Ҫ�޸��Ĳ�����Ϣ��(1.ѧ��,2.����,3.����,4.�༶,5.רҵ,6.��ϵ��ʽ,7.ȫ���޸� 0.�˳�)" << endl;
		cout << "���룺";
	}
	return index;
}

int Interface::BookSearchFace()								//ͼ���������棬���ؽ��0-5
{
	int no;
	cout << "����Ҫ����������" << endl << "1.���2.����3.����4.������5.�������� 0.�˳�" << endl;
	cout << "���ͣ�" ;
	cin >> no;
	return no;
}

int Interface::StuSearchFace()								//ѧ���������棬���ؽ��0-5
{
	int no;
	cout << "����Ҫ����������" << endl << "1.ѧ�ţ�2.������3.���䣬4.�༶��5.רҵ��0.�˳�" << endl;
	cout << "���ͣ�";
	cin >> no;
	return no;
}

void Interface::AfterSearchFace()						//���������ʾ����
{
	int i;
	cout << endl;
	for (i = 0; i < 50;i++)cout << "-";
	cout << "���������";
	for (i = 0; i < 50; i++)cout << "-";
	cout << endl;
}


