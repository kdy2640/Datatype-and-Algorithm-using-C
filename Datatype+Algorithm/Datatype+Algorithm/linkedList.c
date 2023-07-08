#include<stdlib.h>
#include<stdio.h>
#include "linkedList.h"

//�� �ڿ� �ϳ� �ֱ�
void addLList(lList* _llist,int _data)
{
	_llist->iCount++;
	iNode* temp = _llist->headPtr;
	if (temp == NULL) // head�� ������ �����
	{
		_llist->headPtr = (iNode*)malloc(sizeof(iNode));
		_llist->headPtr->iData = _data;
		_llist->headPtr->nextPtr = NULL;
		return;
	}
	//head�� ������ NULL�� ����Ű�� �ְ� ���ö����� �ݺ�
	while(temp->nextPtr != NULL)
	{
		temp = temp->nextPtr;
	}

	temp->nextPtr = (iNode*)malloc(sizeof(iNode));
	temp->nextPtr->iData = _data;
	temp->nextPtr->nextPtr = NULL;
	return;
}

//�ʱ�ȭ startLList
void startLList(lList* _llist)
{
	_llist->iCount = 0;
	_llist->headPtr = NULL;
}

//Ư�� index�� ����
void insertLList(lList* _llist, int _index, int _data)
{

	if (_index > _llist->iCount)
	{//����
		printf("out of range");
		return;
	}

	iNode* temp = _llist->headPtr;
	iNode* temp2 = NULL;
	_llist->iCount++;
	if (_index == _llist->iCount)
	{//�� �ڿ� �߰�
		addLList(_llist,_data);
	}
	else if(_index == 0)
	{//�� �տ� �߰�
		_llist->headPtr = (iNode*)malloc(sizeof(iNode));
		_llist->headPtr->iData = _data;
		_llist->headPtr->nextPtr = temp;
		return;
	}else
	{//�߰��� �߰�
		for (int i = 1; i < _index; i++)
		{
			temp = temp->nextPtr;
		}
		//_index��°�� ������ ����� �ּҸ� temp��
		temp2 = temp->nextPtr;
		temp->nextPtr = (iNode*)malloc(sizeof(lList));
		temp->nextPtr->iData = _data;
		temp->nextPtr->nextPtr = temp2;
	}
}

//����Ʈ�� ����
void finishLList(lList* _llist)
{
	iNode* temp = _llist->headPtr;
	while (_llist->iCount != 0)
	{
		_llist->headPtr = temp->nextPtr;
		free(temp);
		temp = _llist->headPtr;
		_llist->iCount--;
	}
}

//�ε����� �����͸� ��ȯ
int getLLIst(lList* _llist, int _index)
{
	if (_index >= _llist->iCount)
	{
		printf("out of range");
		return;
	}
	iNode* temp = _llist->headPtr;
	for (int i = 0; i < _index; i++)
	{
		temp = temp->nextPtr;
	}
	return temp->iData;
}

//���̸� ��ȯ
int lenLList(lList* _llist)
{
	return _llist->iCount;
}

//_index���� ����� ����
void deleteLList(lList* _llist, int _index)
{
	iNode* temp = _llist->headPtr;
	iNode* temp2 = NULL;
	if (_index >= _llist->iCount)
	{
		printf("out of range");
		return;
	}
	_llist->iCount--;
	if (_index == 0)
	{
		_llist->headPtr = _llist->headPtr->nextPtr;
		free(temp);
		return;
	}
	for (int i = 1; i < _index; i++)
	{
		temp = temp->nextPtr;
	}
	//temp�� ������ ��尡 ������ ����� �ּҰ� �־����
	
	temp2 = temp->nextPtr;
	temp->nextPtr = temp->nextPtr->nextPtr;
	free(temp2);


	return;
}