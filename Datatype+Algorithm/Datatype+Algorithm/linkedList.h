#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct oneNode {
	int iData;
	struct oneNode* nextPtr;
}iNode;

typedef struct linkedList {
	int iCount;
	iNode* headPtr;
}lList;

//노드 1개 늘리기 addNode * 내부
void addLList(lList* _llist , int _data);
//초기화 startLList
void startLList(lList* _llist);
//추가 addHeadLList
void insertLList(lList* _llist, int _index , int _data);
//해제 finishLList
void finishLList(lList* _llist);
//인덱스 접근 getLList
int getLLIst(lList* _llist, int _index);
//길이 lenLList 
int lenLList(lList* _llist);
//노드 삭제 deleteLList
void deleteLList(lList* _llist,int _index);

#endif 
