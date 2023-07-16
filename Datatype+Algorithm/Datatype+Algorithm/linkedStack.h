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

// ���� �ʱ�ȭ
void startLStack(lStack* _stack);
// ���� ���� 
void finishLStack(lStack* _stack);
// ���ÿ� ������ �ֱ� push
void pushLStack(lStack* _stack, int _data);
// ������ ������ ������ ��ȯ peek, ������ ������� �� �ƹ��͵� ��ȯ���� ����.
int peekLStack(lStack* _stack);
// ������ ������ ������ ��ȯ�ϰ� ���� pop, ������ ������� �� �ƹ��͵� ��ȯ���� ����.
int popLStack(lStack* _stack);
// Ư�� �ε��� �� ��ȯ, �ε��� ����� �ƹ��͵� ��ȯ���� ����
int getIndexOfLStack(lStack* _stack, int _index);
// ���� ��ȯ
int getCountLStack(lStack* _stack);


#endif // !__LINKEDSTACK__
