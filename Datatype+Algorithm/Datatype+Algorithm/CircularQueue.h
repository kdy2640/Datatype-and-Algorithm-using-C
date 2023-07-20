#ifndef __CIRCULARQUEUE__
#define __CIRCULARQUEUE__

typedef struct CircularQueue
{
	int front; //����
	int rear;  //�Ĵ�
	int capacity; //�ִ�ũ��

	int* dArr; //�ִ�ũ�� +1
}cQue;

// ��ȯť �ʱ�ȭ - ����ũ��� 10
void startCQueue(cQue* _cque);
// ��ȯť ���� 
void finishCQueue(cQue* _cque);
// �ϳ� �߰� 0 �������� -1 �޸��Ҵ� ����
int pushbackCQueue(cQue* _cque, int _data);
// �ϳ� ���� ��ȯ
int popCQueue(cQue* _cque);
// �ϳ� ��ȯ
int peekCQueue(cQue* _cque);
// ����
void clearCQueue(cQue* _cque);
// ���� ��ȯ
int countCQueue(cQue* _cque);
// ������
void showmeCQueue(cQue* _cque);
#endif // !__CIRCULARQUEUE__
