#include<stdlib.h>
#include<stdio.h>
#include "dArr.h"
//늘린다
void moreallocDArr(dArr* _darr)
{
	int* ptr2 = (int*)malloc(sizeof(int) * (10 + _darr->iMax));
	_darr->iMax += 10;
	for (int i = 0; i < _darr->iCount; i++)
	{
		ptr2[i] = _darr->ptr[i];
	}
	_darr->ptr = ptr2;
	free(ptr2);
}

//초기화
void startDArr(dArr* _darr) 
{
	_darr->ptr = (int*)malloc(sizeof(int) * 10);
	_darr->iMax = 10;
	_darr->iCount = 0;
}

//해제
void finishDArr(dArr* _darr)
{
	free(_darr->ptr);
	_darr->iMax = 0;
	_darr->iCount = 0;
}

//pushback
void pushDArr(dArr* _darr, int _data) 
{
	if(_darr->iCount == _darr->iMax)
	{
		moreallocDArr(_darr);
	}
	_darr->ptr[_darr->iCount++] = _data;
}

//pop
int popDArr(dArr* _darr)
{
	if (_darr->iCount == 0)
	{
		printf("There is no element in Dynamic Array.");
		exit(1);
	}
	return _darr->ptr[--_darr->iCount];
}


//peek
int peekDArr(dArr* _darr) 
{
	if (_darr->iCount == 0)
	{
		printf("There is no element in Dynamic Array.");
		exit(1);
	}
	return _darr->ptr[_darr->iCount - 1];
}

//index 접근
int getDataDArr(dArr* _darr, int _index) 
{
	if (_index >= _darr->iCount) 
	{
		printf("Out of Range!");
		exit(1);
	}
	return  _darr->ptr[_index];
}

