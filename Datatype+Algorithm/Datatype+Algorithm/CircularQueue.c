#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>



// 순환큐 초기화 - 시작크기는 10
void startCQueue(cQue* _cque)
{
	_cque->front = 0;	_cque->rear = 0;
	_cque->capacity = 10;
	_cque->dArr = (int*)malloc(sizeof(int) * 11);
	if (_cque->dArr == NULL)
	{
		printf("ERROR : Memory Allocation Failed.\n");
		return -1;
	}
}
// 순환큐 해제 
void finishCQueue(cQue* _cque)
{
	free(_cque->dArr);
	_cque->front = 0;	_cque->rear = 0;
	_cque->capacity = 0;
}
// 하나 추가
int pushbackCQueue(cQue* _cque ,int _data)
{
	//꽉 찼는지 확인하고 찼으면 capacity 두배
	if (_cque->front - _cque->rear == 1|| _cque->rear - _cque->front == _cque->capacity)
	{
		int* temp = _cque->dArr;
		_cque->dArr = (int*)malloc(sizeof(int) * (_cque->capacity * 2 + 1));
		if (_cque->dArr == NULL)
		{
			printf("ERROR : Memory Allocation Failed.\n");
			return -1;
		}
		for (int i = 0; i < _cque->capacity; i++)
		{
			_cque->dArr[i] = temp[(_cque->front + i) % _cque->capacity];
		}
		//기존 배열 해제
		free(temp);
		if (_cque->front - _cque->rear == 1) _cque->rear = _cque->capacity - 1;
		else
		{
			_cque->rear = _cque->capacity;
		}
		_cque->front = 0; 
		_cque->capacity *= 2;
	}
	if (_cque->rear == _cque->capacity)
	{
		_cque->rear = 0;
	}
	

	_cque->dArr[_cque->rear] = _data;
	_cque->rear = _cque->rear + 1;
	return 0;
}
// 하나 뺴고 반환 오류시 0 반환
int popCQueue(cQue* _cque)
{
	if (_cque->front == _cque->rear)
	{
		printf("ERROR : Queue Is Empty. \n");
		return 0;
	}
	int temp = _cque->dArr[_cque->front];
	_cque->dArr[_cque->front] = 0;
	_cque->front = (_cque->front + 1) % _cque->capacity;
	return temp;
}
// 하나 반환 오류시 0 반환
int peekCQueue(cQue* _cque)
{
	if (_cque->front == _cque->rear)
	{
		printf("ERROR : Queue Is Empty. \n");
		return 0;
	}
	return _cque->dArr[_cque->front];
}
// 비우기
void clearCQueue(cQue* _cque)
{
	_cque->front = 0;
	_cque->rear = 0;
}
// 개수 반환
int countCQueue(cQue* _cque)
{
	if (_cque->front < _cque->rear)
	{
		return _cque->rear - _cque->front;
	}
	else if (_cque->rear < _cque->front)
	{
		return _cque->capacity - _cque->front + _cque->rear;
	}
	else
	{
		return 0;
	}
}

void showmeCQueue(cQue* _cque)
{
	for (int i = 0; i <= _cque->capacity; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	for (int i = 0; i <= _cque->capacity; i++)
	{
		if (_cque->dArr[i] < 0) {
			printf("%3d",0);
		}
		else
		{
			printf("%3d", _cque->dArr[i]);
		}
	}
	printf("\n");
	printf("front 는 %d, rear은 %d, capacity는 %d\n\n", _cque->front, _cque->rear,_cque->capacity);

}
