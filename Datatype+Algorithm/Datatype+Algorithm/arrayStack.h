#ifndef __ARRAY_STACK__
#define __ARRAY_STACK__

typedef struct ArrayStack
{
	int* dArr;
	int sCapacity;
	int sCount;
}aStack;

// 동적배열의 크기를 10 늘림(내부사용)
// 스택 초기화 - 최초크기 10
void startAStack(aStack* _stack);
// 스택 종료 
void finishAStack(aStack* _stack);
// 스택에 데이터 넣기 push
void pushAStack(aStack* _stack, int _data);
// 스택의 마지막 데이터 반환 peek
int peekAStack(aStack* _stack);
// 스택의 마지막 데이터 반환하고 삭제 pop
int popAStack(aStack* _stack);
// 특정 인덱스 값 반환
int getIndexOfAStack(aStack* _stack, int _index);
// 길이 반환
int getCountAStack(aStack* _stack);

#endif // !
