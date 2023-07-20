#ifndef __CIRCULARQUEUE__
#define __CIRCULARQUEUE__

typedef struct CircularQueue
{
	int front; //전단
	int rear;  //후단
	int capacity; //최대크기

	int* dArr; //최대크기 +1
}cQue;

// 순환큐 초기화 - 시작크기는 10
void startCQueue(cQue* _cque);
// 순환큐 해제 
void finishCQueue(cQue* _cque);
// 하나 추가 0 정상종료 -1 메모리할당 실패
int pushbackCQueue(cQue* _cque, int _data);
// 하나 뺴고 반환
int popCQueue(cQue* _cque);
// 하나 반환
int peekCQueue(cQue* _cque);
// 비우기
void clearCQueue(cQue* _cque);
// 개수 반환
int countCQueue(cQue* _cque);
// 디버깅용
void showmeCQueue(cQue* _cque);
#endif // !__CIRCULARQUEUE__
