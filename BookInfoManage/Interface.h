#pragma once
#include<string>
#include<iostream>
using namespace std;
class Interface 
{
public:
	void BookLoadface();//������
	void BookSubloadface();//�ӽ���
	void BookSubloadface2();//�ӽ���2
	char BookInputcharface();//��ʾ�����ļ�����
	int BookOperateface();//�����������
	int BookOperateface2();//�����������2
	int BookAddface();//��ӽ���
	int BookDelface();//ɾ������
	int BookSetface();//�޸Ľ���
	int BookSearchface();//��������
	void BookAfterSearchface();//���������ʾ����

	void StuLoadface();//������
	void StuSubloadface();//�ӽ���
	void StuSubloadface2();//�ӽ���2
	char Inputcharface();//��ʾ�����ļ�����
	int Operateface();//�����������
	int Operateface2();//�����������2
	int Addface();//��ӽ���
	int Delface();//ɾ������
	int StuSetface();//�޸Ľ���
	int Searchface();//��������
	void AfterSearchface();//���������ʾ����
};
