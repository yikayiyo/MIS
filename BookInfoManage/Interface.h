#pragma once
#include<string>
#include<iostream>
using namespace std;
class Interface 
{
public:

	int AdminMainFace();					//����Ա������

	void BookLoadFace();					//ͼ�����������
	void BookSubLoadFace();					//ͼ������ӽ���
	void BookSubLoadFace2();				//ͼ������ӽ���2
	void StuLoadFace();						//ѧ������������
	void StuSubLoadFace();					//ѧ�������ӽ���
	void StuSubLoadFace2();					//ѧ�������ӽ���2
	
	char ReadFromFileFace();				//��ʾ�����ļ�����
	char AfterReadFromFileFace();			//����֮����ʾ��ʾ����
	char WriteIntoFileFace();				//��ʾ�����ļ�����
	int OperateFace();						//�����������
	int OperateFace2();						//�����������2

	int AddFace();							//��ӽ���
	int DelFace();							//ɾ������

	int BookSetFace();						//ͼ����Ϣ�޸Ľ���
	int BookSearchFace();					//ͼ����Ϣ��������
	int StuSetFace();						//ѧ����Ϣ�޸Ľ���
	int StuSearchFace();					//ѧ����Ϣ��������

	void AfterSearchFace();					//���������ʾ����
};
