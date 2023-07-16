#include<stdio.h>
#include<stdlib.h>
#include"linkedStack.h"


// 새로운 노드를 할당 할당 실패시 NULL 출력(내부사용)
sNode* createNode(int _data, sNode* _nextPtr)
{
	sNode* temp = (sNode*)malloc(sizeof(sNode));
	//메모리 유효성 검사
	if (temp == NULL)
	{
		printf("ERROR : Memory Allocation Failed. \n");
		return NULL;
	}
	temp->data = _data; temp->nextPtr = _nextPtr;
	return temp;
}
// 스택 초기화
void startLStack(lStack* _stack)
{
	_stack->top = NULL;
	_stack->sCount = 0;
}
// 스택 종료 
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
// 스택에 데이터 넣기 push
void pushLStack(lStack* _stack, int _data)
{
	sNode* temp = createNode(_data, _stack->top); // 탑을 다음으로 하는 노드 생성
	_stack->top = temp; //탑을 temp로 수정
	_stack->sCount += 1;
}
// 스택의 마지막 데이터 반환 peek, 스택이 비어있을 떄 아무것도 반환하지 않음.
int peekLStack(lStack* _stack)
{
	if (_stack->sCount == 0)
	{
		printf("ERROR : Stack Is Empty. \n");
		return;
	}
	return _stack->top->data;

}
// 스택의 마지막 데이터 반환하고 삭제 pop, 스택이 비어있을 떄 아무것도 반환하지 않음.
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
// 특정 인덱스 값 반환, 인덱스 벗어나면 아무것도 반환하지 않음
int getIndexOfLStack(lStack* _stack, int _index)
{
	//인덱스 유효성 검사
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
// 길이 반환
int getCountLStack(lStack* _stack)
{
	return _stack->sCount;
}
