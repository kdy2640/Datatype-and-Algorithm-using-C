#include<stdlib.h>
#include<stdio.h>
#include "DoubleLinkedList.h"


//노드 하나를 만듬 (내부에서만 사용)
iNode* createNode(int _data, iNode* _prevPtr,  iNode* _nextPtr )
{
	iNode* newNode = (iNode*)malloc(sizeof(iNode));
	// 할당 실패 검사
	if (newNode == NULL) 
	{
		printf("Error : Memory Allocation Failed");
		return NULL;
	}
	newNode->iData = _data;
	newNode->nextPtr = _nextPtr;
	newNode->prevPtr = _prevPtr;
	return newNode;
}
//맨 뒤에 노드 한 개 추가
void addTailDList(dList* _dlist, int _data)
{
	insertDList(_dlist, countDList(_dlist), _data);
}
//맨 앞에 노드 한 개 추가
void addHeadDList(dList* _dlist, int _data)
{
	insertDList(_dlist, 0, _data);
}
//초기화 startDList
void startDList(dList* _dlist)
{
	_dlist->iCount = 0;
	_dlist->headPtr = NULL;
	_dlist->tailPtr = NULL;
}
//추가 addHeadDList
int insertDList(dList* _dlist, int _index, int _data)
{
	//인덱스 유효성 검사
	if (_index > _dlist->iCount)
	{
		printf("Error : Index Out Of Range.");
		return -1;
	}
	// 아무 노드도 없을 떄
	if (_dlist->iCount == 0)
	{
		iNode* newNode = createNode(_data, NULL, NULL);
		_dlist->headPtr = newNode;
		_dlist->tailPtr = newNode;
	} 
	//노드가 있을때
	else
	{
		//앞에 넣을 떄
		if (_index == 0)
		{
			iNode* newNode = createNode(_data, NULL, _dlist->headPtr);//head(0번쨰 노드)를 다음으로 하는 노드 생성
			_dlist->headPtr->prevPtr = newNode; // 0번쨰 노드의 이전포인터가 newNode가 되도록 수정
			_dlist->headPtr = newNode; //headptr이 newNode를 가리키도록 수정
		}
		// 뒤에 넣을 떄
		else if (_index == _dlist->iCount)
		{
			iNode* newNode = createNode(_data, _dlist->tailPtr, NULL);//tail(iCount-1번쨰 노드)를 이전으로 하는 노드 생성
			_dlist->tailPtr->nextPtr = newNode;// iCount-1번쨰 노드의 다음포인터가 newNode가 도도록 수정
			_dlist->tailPtr = newNode; // tailptr이 newNode를 가리키도록 수정
		}
		// 중간에 넣을 떄
		else
		{
			iNode* temp;

			if (_index > _dlist->iCount / 2) //뒤에서 순회
			{
				temp = _dlist->tailPtr;
				int indexdiff = _dlist->iCount - _index;
				for (int i = 0; i < indexdiff; i++)
				{
					temp = temp->prevPtr;
				} // temp =  _index-1번쨰 노드의 포인터
			}
			else // 앞에서 순회
			{
				temp = _dlist->headPtr;
				for (int i = 1; i < _index; i++)
				{
					temp = temp->nextPtr;
				} // temp =  _index-1번쨰 노드의 포인터
			}

			iNode* newNode = createNode(_data, temp, temp->nextPtr); // _index-1 번째 노드를 이전으로, _index번쨰 노드를 다음으로 하는 노드를 생성
			temp->nextPtr->prevPtr = newNode; // _index번쨰 노드가 newNode를 이전으로 하게 수정
			temp->nextPtr = newNode; // _index-1번쨰 노드가 newNode를 다음으로 하게 수정

		}
	} 
	_dlist->iCount++;
	return 0;

}
//해제 finishDList
void finishDList(dList* _dlist)
{
	iNode* temp = _dlist->headPtr;
	iNode* next;
	//노드가 아무것도 없을 떄
	if (temp != NULL)
	{
		//NULL이 나올떄까지 해제
		while (temp->nextPtr != NULL)
		{
			next = temp->nextPtr;
			free(temp);
			temp = next;
		}
		free(temp);
	}
	_dlist->iCount = 0;
	_dlist->headPtr = NULL;
	_dlist->tailPtr = NULL;
}
//인덱스 접근 getDList
int getDList(dList* _dlist, int _index)
{
	//index 유효성 검사
	if (_index >= _dlist->iCount) 
	{
		printf("Error : Index Out Of Range.");
		return -1;
	}
	// 맨 앞에거일떄
	if (_index == 0)
	{
		return _dlist->headPtr->iData;
	}
	iNode* temp;
	// 뒤로 순회
	if (_index > _dlist->iCount / 2) //뒤에서 순회
	{
		temp = _dlist->tailPtr;
		int indexdiff = _dlist->iCount - _index;
		for (int i = 0; i < indexdiff; i++)
		{
			temp = temp->prevPtr;
		} // temp =  _index-1번쨰 노드의 포인터
	}
	//앞으로 순회
	else // 앞에서 순회
	{
		temp = _dlist->headPtr;
		for (int i = 1; i < _index; i++)
		{
			temp = temp->nextPtr;
		} // temp =  _index-1번쨰 노드의 포인터
	}
	return temp->nextPtr->iData;
}
//iCount를 반환, 맨 마지막 index+1 
int countDList(dList* _dlist)
{
	return _dlist->iCount;
}
//노드 삭제 deleteDList
int deleteDList(dList* _dlist, int _index)
{

	//index 유효성 검사
	if (_index >= _dlist->iCount)
	{
		printf("Error : Index Out Of Range.");
		return -1;
	}

	iNode* temp;
	// 노드가 1개일때
	if(_dlist->iCount==1) 
	{
		free(_dlist->headPtr);
		_dlist->headPtr = NULL;
		_dlist->tailPtr = NULL;

	}
	else
	{
		// 노드가 2개 이상이고 head를 지울때
		if (_index == 0) 
		{
			temp = _dlist->headPtr; 
			_dlist->headPtr->nextPtr->prevPtr = NULL; // 1번째 노드의 이전 포이너를 NULL로 전환
			_dlist->headPtr = _dlist->headPtr->nextPtr; //headptr을 1번째 노드를 가리키게 수정
			free(temp); temp = NULL;

		}
		// 노드가 2개 이상이고 tail을 지울 떄
		else if (_index == _dlist->iCount - 1) 
		{
			temp = _dlist->tailPtr;
			_dlist->tailPtr->prevPtr->nextPtr = NULL; // iCount -2 번쨰 노드의 다음 포인터를 NULL로 전환
			_dlist->tailPtr = _dlist->tailPtr->prevPtr; //tailptr을 iCount - 2 번째 노드를 가리키게 수정
			free(temp); temp = NULL;
		}
		// 노드가 2개 이상이고 중간을 지울 때
		else 
		{

			if (_index > _dlist->iCount / 2) //뒤에서 순회
			{
				temp = _dlist->tailPtr;
				int indexdiff = _dlist->iCount - _index;
				for (int i = 0; i < indexdiff; i++)
				{
					temp = temp->prevPtr;
				} // temp =  _index-1번쨰 노드의 포인터
			}
			else // 앞에서 순회
			{
				temp = _dlist->headPtr;
				for (int i = 1; i < _index; i++)
				{
					temp = temp->nextPtr;
				} // temp =  _index-1번쨰 노드의 포인터
			}
			iNode* temp2 = temp->nextPtr; //temp2 = _index번쨰 노드의 포인터
			temp->nextPtr->nextPtr->prevPtr = temp; //_index+1 번쨰 노드의 이전 포인터를 temp(_index-1번쨰 노드)로 수정
			temp->nextPtr = temp->nextPtr->nextPtr; //_index-1 번쨰 노드의 다음 포인터를 _index+1번째 노드로 수정
			free(temp2); temp2 = NULL;
		}
	}
	_dlist--;
	return 0;
}
