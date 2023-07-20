#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>



// ��ȯť �ʱ�ȭ - ����ũ��� 10
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
// ��ȯť ���� 
void finishCQueue(cQue* _cque)
{
	free(_cque->dArr);
	_cque->front = 0;	_cque->rear = 0;
	_cque->capacity = 0;
}
// �ϳ� �߰�
int pushbackCQueue(cQue* _cque ,int _data)
{
	//�� á���� Ȯ���ϰ� á���� capacity �ι�
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
		//���� �迭 ����
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
// �ϳ� ���� ��ȯ ������ 0 ��ȯ
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
// �ϳ� ��ȯ ������ 0 ��ȯ
int peekCQueue(cQue* _cque)
{
	if (_cque->front == _cque->rear)
	{
		printf("ERROR : Queue Is Empty. \n");
		return 0;
	}
	return _cque->dArr[_cque->front];
}
// ����
void clearCQueue(cQue* _cque)
{
	_cque->front = 0;
	_cque->rear = 0;
}
// ���� ��ȯ
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
	printf("front �� %d, rear�� %d, capacity�� %d\n\n", _cque->front, _cque->rear,_cque->capacity);

}
