#include<stdlib.h>
#include<stdio.h>
#include "dArr.h"
//�����迭�� 10���� �׸��� �� �Ҵ��Ѵ�.
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

//�����迭�� �ʱ�ȭ�Ѵ�.
void startDArr(dArr* _darr) 
{
	_darr->ptr = (int*)malloc(sizeof(int) * 10);
	_darr->iMax = 10;
	_darr->iCount = 0;
}

//�����迭�� �����Ѵ�.
void finishDArr(dArr* _darr)
{
	free(_darr->ptr);
	_darr->iMax = 0;
	_darr->iCount = 0;
}

//�����迭�� �������� ������ ���� �߰��Ѵ�.
void pushDArr(dArr* _darr, int _data) 
{
	//�� á���� Ȯ��
	if(_darr->iCount == _darr->iMax)
	{
		moreallocDArr(_darr);
	}
	_darr->ptr[_darr->iCount++] = _data;
}

//�����迭�� ������ �����Ͱ��� ��ȯ�ϰ� �����Ѵ�.
int popDArr(dArr* _darr)
{
	if (_darr->iCount == 0)
	{
		printf("There is no element in Dynamic Array.");
		exit(1);
	}
	return _darr->ptr[--_darr->iCount];
}

//�����迭�� ������ ������ ���� ��ȯ�Ѵ�.
int peekDArr(dArr* _darr) 
{
	if (_darr->iCount == 0)
	{
		printf("There is no element in Dynamic Array.");
		exit(1);
	}
	return _darr->ptr[_darr->iCount - 1];
}

//�����迭�� index�� �ش��ϴ� ������ ���� ��ȯ�Ѵ�.
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
