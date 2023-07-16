#include<stdio.h>
#include<stdlib.h>
#include"arrayStack.h"

// 동적배열의 크기를 10 늘림(내부사용) 0 정상 -1 오류
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
// 스택 초기화 - 최초크기 10
void startAStack(aStack* _stack)
{
	_stack->sCapacity = 10;  _stack->sCount = 0;
	_stack->dArr = (int*)malloc(sizeof(int) * 10);
}
// 스택 종료 
void finishAStack(aStack* _stack)
{
	free(_stack->dArr);
	_stack->sCapacity = 0;
	_stack->sCount = 0;
}
// 스택에 데이터 넣기 push
void pushAStack(aStack* _stack, int _data)
{
	// 배열의 여백이 있는지 확인
	if (_stack->sCapacity >= _stack->sCount)
	{
		increaseCapacity(_stack);
	}
	_stack->dArr[_stack->sCount] = _data;
	_stack->sCount += 1;
}
// 스택의 마지막 데이터 반환 peek, 스택이 비어있을 떄 아무것도 반환하지 않음.
int peekAStack(aStack* _stack)
{
	if (_stack->sCount == 0)
	{
		printf("ERROR : Stack Is Empty.");
		return;
	}
	return _stack->dArr[_stack->sCount - 1];
}
// 스택의 마지막 데이터 반환하고 삭제 pop, 스택이 비어있을 떄 아무것도 반환하지 않음.
int popAStack(aStack* _stack)
{
	if (_stack->sCount == 0)
	{
		printf("ERROR : Stack Is Empty.\n");
		return;
	}
	return _stack->dArr[(_stack->sCount--) - 1];
}
// 특정 인덱스 값 반환, 인덱스 벗어나면 아무것도 반환하지 않음
int getIndexOfAStack(aStack* _stack, int _index)
{
	if (_stack->sCount <= _index || _index < 0)
	{
		printf("ERROR : Index Out Of Range.");
		return;
	}

	return _stack->dArr[_index];
}
// 길이 반환
int getCountAStack(aStack* _stack)
{
	return _stack->sCount;
}
