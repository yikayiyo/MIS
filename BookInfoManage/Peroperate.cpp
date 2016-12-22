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
	OutBorrowFile(); 
	OutReserveFile();
	bm.OutBookFile();
	sm.OutStuFile();
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
	string sname =sm.GetNameById(sid);

	if (op_num == 1)											//�ҵ���Ϣ
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
	else if (op_num == 2)										//ͼ����Ϣ
	{
		bm.AllBookShow();
	}
	else if (op_num == 3)										//����
	{
		bm.AllBookShow();
		cout << "����Ҫ���ĵ��鼮��ţ�";
		int no;cin >> no;
		int index = no - 1;
		cout << "����������ڣ�";
		string date;cin >> date;
		string bid = bm.GetBookIdByIndex(index);
		string bname = bm.GetBookNameByIndex(index);
		string sname = sm.GetNameById(sid);
		int isReturn = 0;
		if (isEnough(sid,bid))
		{
			Borrow nb;
			nb.SetIndex(Total_borrow);
			nb.SetInfo(bid, bname, sid, sname, date, isReturn);
			borrow[Total_borrow] = nb;
			Total_borrow++;
			bm.AfterBorrow(bid);								//ˢ�¿��
			sm.AfterBorrow(sid);								//ˢ��ѧ����ǰ������
			//ˢ��ԤԼ�б�
			UpdateReserve(sid,bid);
			cout << "����ɹ�����";
		}
		else
		{
			cout << "���鼮��ǰ���ɽ��ģ�������ѡ��ԤԼ��";
		}
	}
	else if (op_num == 4)										//����
	{
		if (0==ShowMyCurBorrow(sid)) ;
		else
		{
			cout << "����Ҫ�黹���鼮��ţ� ";
			int index;
			cin >> index;
			if (index != -1)
			{
				borrow[index - 1].SetIsReturn();
				string bid = borrow[index - 1].GetBookId();
				bm.ReturnBook(bid);
				sm.AfterReturn(sid);
				cout << "�黹�ɹ�����";
				ShowMyCurBorrow(sid);
			}
			
		}
		
	}
	else if (op_num == 5)										//ԤԼ�鼮
	{
		bm.AllBookShow();
		cout << "����ҪԤԼ���鼮��ţ� ";
		int no;
		cin >> no;
		int index = no - 1;
		string bid = bm.GetBookIdByIndex(index);
		string bname = bm.GetBookNameByIndex(index);

		for (int i = 0; i < Total_reserve; i++)
		{
			if (reserve[i].GetBookId()==bid)
			{
				cout << "���Ѿ�ԤԼ�����飬��ѡ������������";
			}
		}

		cout << "����ԤԼʱ�䣺";
		string date;
		cin >> date;
		Reserve nr;
		nr.SetInfo(bid, bname, sid, sname, date);
		reserve[Total_reserve] = nr;
		Total_reserve++;
		cout << "ԤԼ�ɹ�";
	}
	return 1;
}

int Peroperate::GetReserveAmount(string bookid)
{
	int i = 0,total=0;
	for (; i < Total_reserve; i++)
	{
		if (reserve[i].GetBookId() == bookid)
			total++;
	}
	return total;
}

void Peroperate::ShowMyBorrow(string sid)
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "��ʷ����";
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
	cout << "�ҵ�ԤԼ";
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

int Peroperate::ShowMyCurBorrow(string sid)
{
	int total = sm.GetNumById(sid);
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "��ǰ����";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_borrow; i++)
	{
		if (borrow[i].GetStuId() == sid && borrow[i].GetIsReturn() == 0)
		{borrow[i].Show();}
	}

	cout << endl;
	cout << "��ǰ����������"<<total<<endl;
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	getchar();
	return total;
}

bool Peroperate::isEnough(string stuid, string bookid)
{
	bool res =false;
	if (sm.GetNumById(stuid) == 3)			//��Ϊ3������ԣ��������Ϊ30
	{
		cout << "��ǰ�����Ѵ����ֵ����" << endl;
		return res;
	}
	else									//��û������������ж��Ƿ�ɽ�
	{
		if (0==bm.GetBookAmount(bookid))	//�鼮��Ϊ0���ɽ�
		{
			return res;
		}
		else								//�鼮����Ϊ��ʱ��ԤԼ����ж��Ƿ�ɽ���
		{
			if (!isReserved(stuid, bookid))		//û��ԤԼ
			{
				if (bm.GetBookAmount(bookid) <= GetReserveAmount(bookid))
					return res;
				else
					return true;
			}
			else							//��ԤԼ
			{
				int amount = bm.GetBookAmount(bookid);
				for (int i = 0; i < amount; i++)
				{
					if (reserve[i].GetStuId() == stuid)
					{
						res = true; return res;
					}
				}
				return res;

			}

		}

	}
	//return res;
}

bool Peroperate::isReserved(string stuid, string bookid)
{
	bool res = 0;
	int i = 0;
	for (; i < Total_reserve; i++)
	{
		if (reserve[i].GetBookId() == bookid&&reserve[i].GetStuId() == stuid)
		{
			res = 1;
		}
	}
	return res;
}
void Peroperate::UpdateReserve(string sid, string bid)
{
	if (isReserved(sid, bid))
	{
		int no;
		for (int i = 0; i < Total_reserve; i++)
		{
			if (reserve[i].GetBookId() == bid&&reserve[i].GetStuId() == sid)
				no = i+1;
		}
		for (; no < Total_reserve; no++)
			reserve[no - 1] = reserve[no];
		Total_reserve--;
	}
}
