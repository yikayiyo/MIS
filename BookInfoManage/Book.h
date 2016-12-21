#pragma once
#ifndef BOOK_H
#define BOOK_H


#include<iostream>
#include<string>
using namespace std;
class Book
{
private:
	int index;
	string mBookId;//���
	string mBookName;//����
	string mBookAuthor;//����
	string mBookPub;//������
	string mBookPubDate;//��������
	int mRemainAmount;//���

public:
	void SetIndex(int i) { index = i; }                       //�����±�
	void SetInfo(string, string, string, string, string, int);//�޸ĺ���
	void SetBookId() { cin >> mBookId; }                      //�޸����
	void SetBookName() { cin >> mBookName; }                  //�޸�����
	void SetBookAuthor() { cin >> mBookAuthor; }              //�޸�����
	void SetBookPub() { cin >> mBookPub; }                    //�޸ĳ�����
	void SetBookPubDate() { cin >> mBookPubDate; }            //�޸ĳ�������
	void SetBookAmount() { cin >> mRemainAmount; }            //�޸�����
	void SetBookAmount1(string stuId) { mRemainAmount ++; }
	void SetBookAmount2(string stuId) { mRemainAmount --; }
	void Show();

	string GetBookId() { return mBookId; }                   //��ȡ���
	string GetBookName() { return mBookName; }				 //��ȡ����
	string GetBookAuthor() { return mBookAuthor; }			 //��ȡ����
	string GetBookPub() { return mBookPub; }				 //��ȡ������ 
	string GetBookPubDate() { return mBookPubDate; }         //��ȡ��������
	int GetBookAmount() { return mRemainAmount; }            //��ȡ����
};
#endif // !BOOK_H
