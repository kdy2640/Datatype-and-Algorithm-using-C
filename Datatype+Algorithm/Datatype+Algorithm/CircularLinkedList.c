#include<stdio.h>
#include<stdlib.h>
#include"CircularLinkedList.h"

//노드를 할당받고 주소를 반환(내부사용)
iNode* createCNode(int _data, iNode* _prevPtr, iNode* _nextPtr)
{
	iNode* temp = (iNode*)malloc(sizeof(iNode));
	//메모리 유효성 검사
	if (temp == NULL)
	{
		printf("ERROR : Memory Allocation Failed.");
		return NULL;
	}
	temp->iData = _data; temp->prevPtr = _prevPtr; temp->nextPtr = _nextPtr;
	return temp;
}

//맨 뒤에 노드 한 개 추가
void addTailCList(cList* _clist, int _data)
{
	insertCList(_clist, _clist->iCount, _data);
}
//맨 앞에 노드 한 개 추가
void addHeadCList(cList* _clist, int _data)
{
	insertCList(_clist, 0, _data);
}
//초기화 startCList
void startCList(cList* _clist)
{
	_clist->iCount = 0;
	_clist->headPtr = NULL;
	_clist->tailPtr = NULL;
}
//추가 addHeadCList 정상 0 오류 -1
int insertCList(cList* _clist, int _index, int _data)
{	

	//인덱스 유효성 검사
	if (_clist->iCount < _index || _index < 0)
	{
		printf("ERROR : Index Out Of Value.");
		return -1;
	}
	iNode* temp;
	iNode* temp2;
	//노드가 없을 때
	if (_clist->iCount == 0)
	{
		temp = createCNode(_data,NULL,NULL);  // temp에 새로운 노드를 할당
		temp->nextPtr = temp; temp->prevPtr = temp; // temp의 전후로 자신을 할당
		_clist->headPtr = temp; _clist->tailPtr = temp; // head와 tail이 노드를 가리키게 수정
	}
	//노드가 1개 이상일 떄
	else 
	{
		// 앞에 넣을 떄
		if (_index == 0)
		{
			temp = createCNode(_data, _clist->tailPtr, _clist->headPtr); // head를 다음으로, tail을 이전으로 하는 노드 생성
			_clist->headPtr->prevPtr = temp; // 기존의 head의 이전포인터를 temp로 수정
			_clist->tailPtr->nextPtr = temp; // tail의 다음 포인터를 temp로 수정
			_clist->headPtr = temp; // head를 temp로 변경;

		}
		// 뒤에 넣을 떄
		else if (_index == _clist->iCount)
		{
			temp = createCNode(_data, _clist->tailPtr, _clist->headPtr); // head를 다음으로, tail을 이전으로 하는 노드 생성
			_clist->tailPtr->nextPtr = temp; // 기존이 tail의 다음포인터를 temp로 수정
			_clist->headPtr->prevPtr = temp; // head의 이전 포인터를 temp로 수정
			_clist->tailPtr = temp; // tail을 temp로 변경
		}
		// 중간에 넣을 때
		else
		{	
			temp2 = _clist->headPtr;
			//temp2에 삽입 바로 이전 노드가 올 수 있게 조정
			{
				// 앞에서 순회
				if (_index < _clist->iCount / 2)
				{
					//index 번째니까 index-1 번 반복하면 index-1 번쨰 노드의 주소가 나옴
					for (int i = 1; i < _index; i++)
					{
						temp2 = temp2->nextPtr;
					}
				}
				// 뒤에서 순회
				else
				{
					//index 번쨰니까 뒤에서 iCount - index번 반복하면 index-1 번쨰 노드의 주소가 나옴
					temp2 = _clist->tailPtr;
					int count = _clist->iCount - _index;
					for (int i = 0; i < count; i++)
					{
						temp2 = temp2->prevPtr;
					}
				}
			}

			temp = createCNode(_data, temp2, temp2->nextPtr); // index-1번쨰 노드를 이전으로, index번쨰 노드를 다음으로 하는 노드 temp를 생성
			temp2->nextPtr->prevPtr = temp; // index번쨰 노드의 이전포인터를 temp로 수정
			temp2->nextPtr = temp; // index-1번쨰 노드의 다음포인터를 temp로 수정
		}

	}

	_clist->iCount++;
	return 0;

}
//해제 finishCList
void finishCList(cList* _clist)
{
	//개수가 0개인지 확인
	if (_clist->iCount == 0)
	{
		return;
	}
	else
	{
		iNode* temp = _clist->headPtr;
		iNode* temp2 = NULL;
		int count = _clist->iCount;
		while (temp2 != _clist->headPtr)
		{
			temp2 = temp->nextPtr;  // temp2에 temp 다음 노드의 주소를 할당
			free(temp);  // temp의 현재 노드를 해제
			temp = temp2; //temp에 temp 다음 노드의 주소를 할당
			count--;
		}
		_clist->headPtr = NULL;
		_clist->tailPtr = NULL;
		_clist->iCount = 0;

	}
}
//인덱스 접근 getCList 정상 0 오류 -1
int getCList(cList* _clist, int _index)
{
	//인덱스 유효성검사
	if (_clist->iCount <= _index || _index < 0)
	{
		printf("ERROR : Index Out Of Value.");
		return -1;
	}
	iNode* temp2 = _clist->headPtr;
	//temp2에 목적노드 바로 이전 노드가 올 수 있게 조정
	{
		// 앞에서 순회
		if (_index < _clist->iCount / 2)
		{
			//index 번째니까 index-1 번 반복하면 index-1 번쨰 노드의 주소가 나옴
			for (int i = 1; i < _index; i++)
			{
				temp2 = temp2->nextPtr;
			}
		}
		// 뒤에서 순회
		else
		{
			//index 번쨰니까 뒤에서 iCount - index번 반복하면 index-1 번쨰 노드의 주소가 나옴
			temp2 = _clist->tailPtr;
			int count = _clist->iCount - _index;
			for (int i = 0; i < count; i++)
			{
				temp2 = temp2->prevPtr;
			}
		}
	}
	return temp2->nextPtr->iData;
}

//iCount를 반환, 맨 마지막 index+1 
int countCList(cList* _clist) 
{ 
	return _clist->iCount; }

//노드 삭제 deleteCList 정상 0 오류 -1
int deleteCList(cList* _clist, int _index)
{
	//인덱스 유효성검사
	if (_clist->iCount <= _index || _index < 0)
	{
		printf("ERROR : Index Out Of Value.");
		return -1;
	}
	//노드가 없을 때
	if (_clist->iCount == 0)
	{
		printf("ERROR : List is Empty.");
		return -1;
	}
	iNode* temp = _clist->headPtr;
	//노드가 1개 있을 때
	if (_clist->iCount == 1)
	{
		free(temp);
		_clist->headPtr = NULL; _clist->tailPtr = NULL;
	}
	//노드가 2개 이상 있을때
	else
	{
		//앞에서 뺄 떄
		if (_index == 0)
		{
			_clist->headPtr->nextPtr->prevPtr = _clist->tailPtr; // 헤드 다음노드의 이전포인터를 테일노드로 수정
			_clist->tailPtr->nextPtr = _clist->headPtr->nextPtr;// 테일노드의 다음포인터를 헤드 다음노드로 수정
			_clist->headPtr = _clist->headPtr->nextPtr; // 헤드를 기존의 헤드 다음 노드로 수정
			free(temp);
			temp = NULL;
		}
		//뒤에서 뺼 때
		else if (_index == _clist->iCount - 1)
		{
			temp = _clist->tailPtr;
			_clist->tailPtr->prevPtr->nextPtr = _clist->headPtr; // 테일 이전노드의 다음포인터를 헤드노드로 수정
			_clist->headPtr->prevPtr = _clist->tailPtr->prevPtr; // 헤드노드의 이전포인터를 꼬리 이전노드로 수정
			_clist->tailPtr = _clist->tailPtr->prevPtr; //테일을 기존의 헤드 이전 노드로 수정
			free(temp);
			temp = NULL;
		}
		//중간에서 뺼 때
		else
		{
			iNode* temp2 = _clist->headPtr;
			//temp2에 목적노드 바로 이전 노드가 올 수 있게 조정
			{
				// 앞에서 순회
				if (_index < _clist->iCount / 2)
				{
					//index 번째니까 index-1 번 반복하면 index-1 번쨰 노드의 주소가 나옴
					for (int i = 1; i < _index; i++)
					{
						temp2 = temp2->nextPtr;
					}
				}
				// 뒤에서 순회
				else
				{
					//index 번쨰니까 뒤에서 iCount - index번 반복하면 index-1 번쨰 노드의 주소가 나옴
					temp2 = _clist->tailPtr;
					int count = _clist->iCount - _index;
					for (int i = 0; i < count; i++)
					{
						temp2 = temp2->prevPtr;
					}
				}
			}
			temp = temp2->nextPtr; //목적노드의 주소를 저장
			temp2->nextPtr->nextPtr->prevPtr = temp2; // 목적노드 다음노드의 이전포인터를 목적노드 이전노드로 수정
			temp2->nextPtr = temp2->nextPtr->nextPtr; // 목적노드 이전노드의 다음포인터를 목적노드 다음노드로 수정
			free(temp);
			temp = NULL;
		}
	}

	_clist->iCount--;
	return 0;
}
