#include<stdio.h>
#include<stdlib.h>
#include"linkedStack.h"


// ���ο� ��带 �Ҵ� �Ҵ� ���н� NULL ���(���λ��)
sNode* createNode(int _data, sNode* _nextPtr)
{
	sNode* temp = (sNode*)malloc(sizeof(sNode));
	//�޸� ��ȿ�� �˻�
	if (temp == NULL)
	{
		printf("ERROR : Memory Allocation Failed. \n");
		return NULL;
	}
	temp->data = _data; temp->nextPtr = _nextPtr;
	return temp;
}
// ���� �ʱ�ȭ
void startLStack(lStack* _stack)
{
	_stack->top = NULL;
	_stack->sCount = 0;
}
// ���� ���� 
void finishLStack(lStack* _stack)
{
	if (_stack->sCount == 0)
	{
		return;
	}
	sNode* temp = _stack->top;
	while (_stack->top != NULL)
	{
		temp = _stack->top->nextPtr;
		free(_stack->top);
		_stack->top = temp;
	}
}
// ���ÿ� ������ �ֱ� push
void pushLStack(lStack* _stack, int _data)
{
	sNode* temp = createNode(_data, _stack->top); // ž�� �������� �ϴ� ��� ����
	_stack->top = temp; //ž�� temp�� ����
	_stack->sCount += 1;
}
// ������ ������ ������ ��ȯ peek, ������ ������� �� �ƹ��͵� ��ȯ���� ����.
int peekLStack(lStack* _stack)
{
	if (_stack->sCount == 0)
	{
		printf("ERROR : Stack Is Empty. \n");
		return;
	}
	return _stack->top->data;

}
// ������ ������ ������ ��ȯ�ϰ� ���� pop, ������ ������� �� �ƹ��͵� ��ȯ���� ����.
int popLStack(lStack* _stack)
{
	if (_stack->sCount == 0)
	{
		printf("ERROR : Stack Is Empty. \n");
		return;
	}
	int pop = _stack->top->data;
	sNode* temp = _stack->top;
	_stack->top = _stack->top->nextPtr;
	free(temp); temp = NULL;
	_stack->sCount--;
	return pop;
}
// Ư�� �ε��� �� ��ȯ, �ε��� ����� �ƹ��͵� ��ȯ���� ����
int getIndexOfLStack(lStack* _stack, int _index)
{
	//�ε��� ��ȿ�� �˻�
	if (_stack->sCount <= _index|| _index < 0)
	{
		printf("ERROR : Index Out Of Range. \n");
		return;
	}
	sNode* temp = _stack->top;
	for (int i = 0; i < _index; i++)
	{
		temp = temp->nextPtr;
	}
	return temp->data;
} 
// ���� ��ȯ
int getCountLStack(lStack* _stack)
{
	return _stack->sCount;
}
