#ifndef __ARRAY_STACK__
#define __ARRAY_STACK__

typedef struct ArrayStack
{
	int* dArr;
	int sCapacity;
	int sCount;
}aStack;

// �����迭�� ũ�⸦ 10 �ø�(���λ��)
// ���� �ʱ�ȭ - ����ũ�� 10
void startAStack(aStack* _stack);
// ���� ���� 
void finishAStack(aStack* _stack);
// ���ÿ� ������ �ֱ� push
void pushAStack(aStack* _stack, int _data);
// ������ ������ ������ ��ȯ peek
int peekAStack(aStack* _stack);
// ������ ������ ������ ��ȯ�ϰ� ���� pop
int popAStack(aStack* _stack);
// Ư�� �ε��� �� ��ȯ
int getIndexOfAStack(aStack* _stack, int _index);
// ���� ��ȯ
int getCountAStack(aStack* _stack);

#endif // !
