#include "Peroperate.h"
const int Num_borrow = 100; //�����ļ�¼����
Borrow borrow[Num_borrow];	  //���Ķ�������
int No_borrow = 1;		  //��Ŵ�1��ʼ
int Total_borrow = 0;       //��ǰ����

const int Num_reserve = 100; //���ԤԼ��¼����
Reserve reserve[Num_reserve];	  //ԤԼ��������
int No_reserve = 1;		  //��Ŵ�1��ʼ
int Total_reserve = 0;       //��ǰԤԼ����

void Peroperate::PersonalOperate(string sid)
{
	int op_num;
	char op_char;           //�Ƿ񱣴�
	InBorrowFile();
	InReserveFile();
	while (1)
	{
		op_num = face.StuMainFace();
		if (op_num == 0)break;
		SwitchFunction(sid, op_num);
		cout << "���������...";
		getchar();
	}
	op_char = face.WriteIntoFileFace();

	if (op_char == 'Y' || op_char == 'y') { OutBorrowFile(); OutReserveFile();	cout << "�ѱ��棡" << endl; }	//���浽�ļ�
	system("pause");

}

void Peroperate::InBorrowFile()
{
	int i;
	Infile_borrow.open_in_borrowfile();
	int total = 0;
	while (Infile_borrow.Filecinborrow())
	{
		borrow[total++] = Infile_borrow.Getborrow();
	}
	Total_borrow = total - 1;
	for (i = 0; i < Total_borrow; i++)
		borrow[i].SetIndex(1 + i);
	Infile_borrow.Closefile();
}

void Peroperate::InReserveFile()
{
	int i;
	Infile_reserve.open_in_reservefile();
	int total = 0;
	while (Infile_reserve.Filecinreserve())
	{
		reserve[total++] = Infile_reserve.Getreserve();
	}
	Total_reserve = total - 1;
	for (i = 0; i < Total_reserve; i++)
		reserve[i].SetIndex(1 + i);
	Infile_reserve.Closefile();
}

void Peroperate::OutBorrowFile()
{
	int i;
	OutFile_borrow.open_out_borrowfile();

	for (i = 0; i<Total_borrow; i++)
	{
		OutFile_borrow.Filecout(borrow[i]);
	}
	OutFile_borrow.Closefile();
}

void Peroperate::OutReserveFile()
{
	int i;
	OutFile_reserve.open_out_reservefile();

	for (i = 0; i<Total_reserve; i++)
	{
		OutFile_reserve.Filecout(reserve[i]);
	}
	OutFile_reserve.Closefile();
}

int Peroperate::SwitchFunction(string sid, int op_num)
{
	string curStuId = sid;
	if (op_num == 1)            //�ҵ���Ϣ
	{
		int op=face.PersonalInfoFace();
		if(op == 0) 
		{ cout << "���˳�."; getchar(); getchar(); return 0; }
		else if(op==1)
		{
			ShowMyCurBorrow(sid);
		}
		else if (op == 2)
		{
			ShowMyBorrow(sid);
		}
		else if (op == 3)
		{
			ShowMyReserve(sid);
		}
	} 
	else if (op_num == 2)
	{
		BookInfoManagement bm;
		bm.InBookFile();
		bm.AllBookShow();
	}
	else if (op_num == 3)
	{

	}
	else if (op_num == 4)
	{

	}
	else if (op_num == 5)
	{

	}
	return 1;
}

void Peroperate::ShowMyBorrow(string sid)
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "��ʾ���";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_borrow; i++)
	{
		if (borrow[i].GetStuId() == sid)
			borrow[i].Show();
	}
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "�����������...";
	getchar(); getchar();
}

void Peroperate::ShowMyReserve(string sid)
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "��ʾ���";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_reserve; i++)
	{
		if (reserve[i].GetStuId() == sid)
			reserve[i].Show();
	}
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "�����������...";
	getchar(); getchar();
}

void Peroperate::ShowMyCurBorrow(string sid)
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "��ʾ���";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_borrow; i++)
	{
		if (borrow[i].GetStuId() == sid && borrow[i].GetIsReturn()==0)
			borrow[i].Show();
	}
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "�����������...";
	getchar(); getchar();
}