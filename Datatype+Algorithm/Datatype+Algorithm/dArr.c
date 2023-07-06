#include<stdlib.h>
#include<stdio.h>
#include "dArr.h"
//동적배열에 10개의 항목을 더 할당한다.
void moreallocDArr(dArr* _darr)
{
	int* ptr2 = (int*)malloc(sizeof(int) * (10 + _darr->iMax));
	_darr->iMax += 10;
	for (int i = 0; i < _darr->iCount; i++)
	{
		ptr2[i] = _darr->ptr[i];
	}
	free(_darr->ptr);
	_darr->ptr = ptr2;
}

//동적배열을 초기화한다.
void startDArr(dArr* _darr) 
{
	_darr->ptr = (int*)malloc(sizeof(int) * 10);
	_darr->iMax = 10;
	_darr->iCount = 0;
}

//동적배열을 해제한다.
void finishDArr(dArr* _darr)
{
	free(_darr->ptr);
	_darr->iMax = 0;
	_darr->iCount = 0;
}

//동적배열의 마지막에 데이터 값을 추가한다.
void pushDArr(dArr* _darr, int _data) 
{
	//다 찼는지 확인
	if(_darr->iCount == _darr->iMax)
	{
		moreallocDArr(_darr);
	}
	_darr->ptr[_darr->iCount++] = _data;
}

//동적배열의 마지막 데이터값을 반환하고 삭제한다.
int popDArr(dArr* _darr)
{
	if (_darr->iCount == 0)
	{
		printf("There is no element in Dynamic Array.");
		exit(1);
	}
	return _darr->ptr[--_darr->iCount];
}

//동적배열의 마지막 데이터 값을 반환한다.
int peekDArr(dArr* _darr) 
{
	if (_darr->iCount == 0)
	{
		printf("There is no element in Dynamic Array.");
		exit(1);
	}
	return _darr->ptr[_darr->iCount - 1];
}

//동적배열의 index에 해당하는 데이터 값을 반환한다.
int getDataDArr(dArr* _darr, int _index) 
{
	if (_index >= _darr->iCount) 
	{
		printf("Out of Range!");
		exit(1);
	}
	return  _darr->ptr[_index];
}

int getLenDArr(dArr* _darr)
{
	return _darr->iCount;
}
