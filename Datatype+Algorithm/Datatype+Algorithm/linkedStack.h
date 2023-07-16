#ifndef __LINKED_STACK__
#define __LINKED_STACK__

typedef struct oneNode
{
	int data;
	struct oneNode* nextPtr;
}sNode;

typedef struct LinkedStack
{
	sNode* top;
	int sCount;
}lStack;

// 스택 초기화
void startLStack(lStack* _stack);
// 스택 종료 
void finishLStack(lStack* _stack);
// 스택에 데이터 넣기 push
void pushLStack(lStack* _stack, int _data);
// 스택의 마지막 데이터 반환 peek, 스택이 비어있을 떄 아무것도 반환하지 않음.
int peekLStack(lStack* _stack);
// 스택의 마지막 데이터 반환하고 삭제 pop, 스택이 비어있을 떄 아무것도 반환하지 않음.
int popLStack(lStack* _stack);
// 특정 인덱스 값 반환, 인덱스 벗어나면 아무것도 반환하지 않음
int getIndexOfLStack(lStack* _stack, int _index);
// 길이 반환
int getCountLStack(lStack* _stack);


#endif // !__LINKEDSTACK__
