#include<stdlib.h>
#include<stdio.h>
#include "linkedList.h"

//맨 뒤에 하나 넣기
void addLList(lList* _llist,int _data)
{
	_llist->iCount++;
	iNode* temp = _llist->headPtr;
	if (temp == NULL) // head가 없으면 만들기
	{
		_llist->headPtr = (iNode*)malloc(sizeof(iNode));
		_llist->headPtr->iData = _data;
		_llist->headPtr->nextPtr = NULL;
		return;
	}
	//head가 있으면 NULL을 가리키는 애가 나올때까지 반복
	while(temp->nextPtr != NULL)
	{
		temp = temp->nextPtr;
	}

	temp->nextPtr = (iNode*)malloc(sizeof(iNode));
	temp->nextPtr->iData = _data;
	temp->nextPtr->nextPtr = NULL;
	return;
}

//초기화 startLList
void startLList(lList* _llist)
{
	_llist->iCount = 0;
	_llist->headPtr = NULL;
}

//특정 index에 삽입
void insertLList(lList* _llist, int _index, int _data)
{

	if (_index > _llist->iCount)
	{//오류
		printf("out of range");
		return;
	}

	iNode* temp = _llist->headPtr;
	iNode* temp2 = NULL;
	_llist->iCount++;
	if (_index == _llist->iCount)
	{//맨 뒤에 추가
		addLList(_llist,_data);
	}
	else if(_index == 0)
	{//맨 앞에 추가
		_llist->headPtr = (iNode*)malloc(sizeof(iNode));
		_llist->headPtr->iData = _data;
		_llist->headPtr->nextPtr = temp;
		return;
	}else
	{//중간에 추가
		for (int i = 1; i < _index; i++)
		{
			temp = temp->nextPtr;
		}
		//_index번째가 다음인 노드의 주소를 temp에
		temp2 = temp->nextPtr;
		temp->nextPtr = (iNode*)malloc(sizeof(lList));
		temp->nextPtr->iData = _data;
		temp->nextPtr->nextPtr = temp2;
	}
}

//리스트를 해제
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

//인덱스에 데이터를 반환
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

//길이를 반환
int lenLList(lList* _llist)
{
	return _llist->iCount;
}

//_index번쨰 노드의 삭제
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
	//temp에 지워질 노드가 다음인 노드의 주소가 있어야함
	
	temp2 = temp->nextPtr;
	temp->nextPtr = temp->nextPtr->nextPtr;
	free(temp2);


	return;
}