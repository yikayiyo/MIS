#include "StudentInfoManagement.h"

const int Num_stu = 100; //����鼮����
Student student[Num_stu];	  //���������
int No_stu = 1;		  //��Ŵ�1��ʼ
int Total_stu = 0;       //��ǰ�鼮����

void StudentInfoManagement::StuInfoManage()
{
	int op_num;         //��������
	char op_char;       //ѡ����
	char op_char2;      //�Ƿ񱣴�
	Face_student.StuLoadface(); //���ؽ���

	int flag, nflag = 0;
	do {
		flag = 0;
		if (nflag)cout << "���벻�Ϸ����������룺";
		op_char = Face_student.StuInputcharface();
		if (op_char != 'Y'&&op_char != 'y'&&op_char != 'N'&&op_char != 'n')
		{
			flag = 1;
			nflag = 1;
		}
	} while (flag);

	if (op_char == 'Y' || op_char == 'y')				//�����ļ�
	{
		InStuFile();
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

		if (sub_op_char == 'Y' || sub_op_char == 'y') { AllStuShow();	Face_student.StuSubloadface(); }
	}
	else if (op_char == 'N' || op_char == 'n')
	{
		Face_student.StuSubloadface2();
	}

	while (1)				//����ִ�й���
	{
		if (Total_stu != 0) op_num = Face_student.StuOperateface();		//�鼮Ϊ��0ʱ������������
		else op_num = Face_student.StuOperateface2();						//�鼮Ϊ0ʱ��Ҫ��ӣ������ӽ���
		if (op_num == 6) break;
		SwitchFunction(op_num);
		cout << "���������...";
		getchar();
		if (Total_stu != 0) Face_student.StuSubloadface();
		else
		{
			cout << endl;
			cout << "�鼮��ĿΪ0��";
			Face_student.StuSubloadface2();
		}

	}
	cout << "Ҫ����������(Y/N)";
	cin >> op_char2;

	if (op_char2 == 'Y' || op_char2 == 'y') { OutStuFile();	cout << "�ѱ��棡" << endl; }	//���浽�ļ�
	system("pause");
}

void StudentInfoManagement::InStuFile()
{
	int i;
	Infile_student.open_in_bookfile();
	int total = 0;
	while (Infile_student.Filecinstudent())
	{
		student[total++] = Infile_student.Getstudent();
	}
	Total_stu = total - 1;
	for (i = 0; i < Total_stu; i++)
		student[i].SetIndex(1 + i);
	Infile_student.Closefile();
}

void StudentInfoManagement::OutStuFile()
{
	int i;
	OutFile_student.open_out_studentfile();

	for (i = 0; i<Total_stu; i++)
	{
		OutFile_student.Filecout(student[i]);
	}
	OutFile_student.Closefile();
}

void StudentInfoManagement::AllStuShow()
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "��ʾ���";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_stu; i++)
		student[i].Show();
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "�����������...";
	getchar(); getchar();
}

int StudentInfoManagement::SwitchFunction(int)
{

	return 0;
}

