#include "StudentInfoManagement.h"


void StudentInfoManagement::StuInfoManage()
{
	int op_num;         //��������
	char op_char;       //ѡ����
	char op_char2;      //�Ƿ񱣴�
	Face_student.StuLoadFace(); //���ؽ���

	int flag, nflag = 0;
	do {
		flag = 0;
		if (nflag)cout << "���벻�Ϸ����������룺";
		op_char = Face_student.ReadFromFileFace();
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
			sub_op_char = Face_student.AfterReadFromFileFace();
			if (sub_op_char != 'Y'&&sub_op_char != 'y'&&sub_op_char != 'N'&&sub_op_char != 'n')
				flag = 1;
		} while (flag);

		if (sub_op_char == 'Y' || sub_op_char == 'y') { AllStuShow();	Face_student.StuSubLoadFace(); }
	}
	else if (op_char == 'N' || op_char == 'n')
	{
		Face_student.StuSubLoadFace2();
	}

	while (1)				//����ִ�й���
	{
		if (Total_stu != 0) op_num = Face_student.OperateFace();			//��0ʱ������������
		else op_num = Face_student.OperateFace2();							//Ϊ0ʱ��Ҫ��ӣ������ӽ���
		if (op_num == 6) break;
		SwitchFunction(op_num);
		cout << "���������...";
		getchar();
		if (Total_stu != 0) Face_student.StuSubLoadFace();
		else
		{
			cout << endl;
			cout << "ѧ����ĿΪ0��";
			Face_student.StuSubLoadFace2();
		}

	}

	op_char2 = Face_student.WriteIntoFileFace();
	
	if (op_char2 == 'Y' || op_char2 == 'y') { OutStuFile();	cout << "�ѱ��棡" << endl; }	//���浽�ļ�
	system("pause");
}

void StudentInfoManagement::InStuFile()
{
	int i;
	Infile_student.open_in_studentfile();
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

int StudentInfoManagement::SwitchFunction(int op_num)
{
	int i;
	string id;
	string name;
	string age;
	string cls;
	string major;
	string phone;

	if (op_num == 1)							//���
	{
		int num = Face_student.AddFace();
		if (num == 0) { cout << "���˳�."; getchar(); getchar(); return 0; }
		for (i = 0; i < num; i++)
		{
			cout << "�����" << (i + 1) << "��ѧ������Ϣ��" << endl;
			cout << "����ѧ����ţ�";
			cin >> id;
			cout << "����ѧ��������";
			cin >> name;
			cout << "����ѧ�����䣺";
			cin >> age;
			cout << "����ѧ���༶��";
			cin >> cls;
			cout << "����ѧ��רҵ��";
			cin >> major;
			cout << "����ѧ����ϵ��ʽ��";
			cin >> phone;
			cout << endl;
			Total_stu++;
			student[Total_stu - 1].SetIndex(Total_stu);
			student[Total_stu - 1].SetInfo(id, name, age, cls, major, phone,0);
		}
		if (i == num)cout << "�����ɣ�" << endl;

	}
	else if(op_num==2)
	{
		int no;
		no = Face_student.DelFace();
		if (no == 0) { cout << "���˳�."; getchar(); getchar(); return 0; }
		for (i = no; i < Total_stu; i++) { student[i].SetIndex(i); student[i - 1] = student[i]; }	//�����Ԫ�ظ���ǰ���Ԫ�� 
		cout << endl << "ɾ��ѧ����Ϣ�ɹ���" << endl;
		cout << "���������...";
		getchar(); getchar();
		Total_stu--;
	}
	else if (op_num == 3)							//�޸�
	{
		int no;					//Ҫ�޸ĵ�ѧ�����,Ϊ0ʱ�˳�
		int item;				//Ҫ�޸ĵ���Ŀ
		int flag = 0;
		no = Face_student.StuSetFace();
		if (0 == no) { cout << "���˳�."; getchar(); getchar(); return 0; }
		cin >> item;
		switch (item)
		{
		case 0:
			cout << "���˳�"; getchar(); getchar(); return 0;
			break;
		case 1:
			cout << "����ѧ����ţ�";
			student[no - 1].SetStuId();
			break;
		case 2:
			cout << "����ѧ��������";
			student[no - 1].SetStuName();
			break;
		case 3:
			cout << "����ѧ�����䣺";
			student[no - 1].SetStuAge();
			break;
		case 4:
			cout << "����ѧ���༶��";
			student[no - 1].SetStuClass();
			break;
		case 5:
			cout << "����ѧ��רҵ��";
			student[no - 1].SetStuMajor();
			break;
		case 6:
			cout << "������ϵ��ʽ��";
			student[no - 1].SetStuPhone();
			break;
		case 7:
			cout << "����ѧ����ţ�";
			cin >> id;
			cout << "����ѧ��������";
			cin >> name;
			cout << "����ѧ�����䣺";
			cin >> age;
			cout << "����ѧ���༶��";
			cin >> cls;
			cout << "����ѧ��רҵ��";
			cin >> major;
			cout << "������ϵ��ʽ��";
			cin >> phone;
			cout << endl;
			student[no - 1].SetInfo(id, name, age, cls, major, phone,0);
			break;
		}

		cout << endl << endl << "������޸ģ����Ϊ��" << endl;
		for (i = 0; i < 110; i++) cout << "-";
		cout << endl;
		student[no - 1].Show();
		for (i = 0; i < 110; i++) cout << "-";
		cout << endl;
		getchar(); getchar();

	}
	else if (op_num == 4)							//��ѯ
	{
		int no;
		int Begin, End;							//��ʼ����λ��
		int res = 0;							//������������

		string temp;

		no = Face_student.StuSearchFace();
		//if (0 == no) { cout << "���˳������������..."; getchar(); getchar(); return 0; }
		int flag = 0;
		switch (no)
		{
		case 0:
		{
			cout << "���˳������������..."; getchar(); getchar(); return 0;
		}
		case 1:																		//��ѧ������
		{
			cout << "������ѧ�ţ�";
			cin >> id;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuId();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		}
		case 2:																		//����������
			cout << "������������";
			cin >> name;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuName();
				Begin = temp.find(name, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 3:																		//����������
			cout << "���������䣺";
			cin >> age;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuAge();
				Begin = temp.find(age, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 4:																//���༶����
			cout << "������༶��";
			cin >> cls;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuClass();
				Begin = temp.find(cls, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 5:																//��רҵ����
			cout << "������רҵ��";
			cin >> major;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuMajor();
				Begin = temp.find(major, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
					res++;
				}
			}
			if (!flag) cout << "û����Ϣ!!!" << endl;
			else
			{
				cout << endl << "����" << res << "����¼��" << endl;
				res = 0;						//��0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		}

	}
	else if (op_num == 5)							//��ʾ
	{
		AllStuShow();
	}

	return 1;
}

string StudentInfoManagement::GetNameById(string sid)
{
	string name;
	int i = 0;
	for (;i<Total_stu;i++)
	{
		if (student[i].GetStuId() == sid)
			name = student[i].GetStuName();
	}
	return name;
}

int StudentInfoManagement::GetNumById(string sid)
{
	int res;
	int i = 0;
	for (; i<Total_stu; i++)
	{
		if (student[i].GetStuId() == sid)
			res = student[i].GetStuBrwAmt();
	}
	return res;
}

void StudentInfoManagement::AfterReturn(string sid)
{
	int i = 0;
	for (; i<Total_stu; i++)
	{
		if (student[i].GetStuId() == sid)
			student[i].UpdateBrwAmt();
	}
}

