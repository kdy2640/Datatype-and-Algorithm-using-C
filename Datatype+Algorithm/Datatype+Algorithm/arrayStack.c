#include<stdio.h>
#include<stdlib.h>
#include"arrayStack.h"

// �����迭�� ũ�⸦ 10 �ø�(���λ��) 0 ���� -1 ����
int increaseCapacity(aStack* _stack)
{
	int* temp = (int*)malloc(sizeof(int) * (_stack->sCapacity + 10));
	if (temp == NULL)
	{
		printf("ERROR : Memory Allocation Failed.");
		return -1;
	}
	_stack->sCapacity += 10;
	for (int i = 0; i < _stack->sCount; i++)
	{
		temp[i] = (_stack->dArr)[i];
	}
	free(_stack->dArr);
	_stack->dArr = temp;
	return 0;
}
// ���� �ʱ�ȭ - ����ũ�� 10
void startAStack(aStack* _stack)
{
	_stack->sCapacity = 10;  _stack->sCount = 0;
	_stack->dArr = (int*)malloc(sizeof(int) * 10);
}
// ���� ���� 
void finishAStack(aStack* _stack)
{
	free(_stack->dArr);
	_stack->sCapacity = 0;
	_stack->sCount = 0;
}
// ���ÿ� ������ �ֱ� push
void pushAStack(aStack* _stack, int _data)
{
	// �迭�� ������ �ִ��� Ȯ��
	if (_stack->sCapacity >= _stack->sCount)
	{
		increaseCapacity(_stack);
	}
	_stack->dArr[_stack->sCount] = _data;
	_stack->sCount += 1;
}
// ������ ������ ������ ��ȯ peek, ������ ������� �� �ƹ��͵� ��ȯ���� ����.
int peekAStack(aStack* _stack)
{
	if (_stack->sCount == 0)
	{
		printf("ERROR : Stack Is Empty.");
		return;
	}
	return _stack->dArr[_stack->sCount - 1];
}
// ������ ������ ������ ��ȯ�ϰ� ���� pop, ������ ������� �� �ƹ��͵� ��ȯ���� ����.
int popAStack(aStack* _stack)
{
	if (_stack->sCount == 0)
	{
		printf("ERROR : Stack Is Empty.\n");
		return;
	}
	return _stack->dArr[(_stack->sCount--) - 1];
}
// Ư�� �ε��� �� ��ȯ, �ε��� ����� �ƹ��͵� ��ȯ���� ����
int getIndexOfAStack(aStack* _stack, int _index)
{
	if (_stack->sCount <= _index || _index < 0)
	{
		printf("ERROR : Index Out Of Range.");
		return;
	}

	return _stack->dArr[_index];
}
// ���� ��ȯ
int getCountAStack(aStack* _stack)
{
	return _stack->sCount;
}
