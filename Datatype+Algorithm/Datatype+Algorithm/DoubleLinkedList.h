#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

typedef struct oneNode {
	int iData;
	struct oneNode* nextPtr;
	struct oneNode* prevPtr;
}iNode;

typedef struct DoublelinkedList {
	int iCount;
	iNode* headPtr;
	iNode* tailPtr;
}dList;

//맨 뒤에 노드 한 개 추가
void addTailDList(dList* _dlist, int _data);
//맨 앞에 노드 한 개 추가
void addHeadDList(dList* _dlist, int _data);
//초기화 startDList
void startDList(dList* _dlist);
//추가 addHeadDList 정상 0 오류 -1
int insertDList(dList* _dlist, int _index, int _data);
//해제 finishDList
void finishDList(dList* _dlist);
//인덱스 접근 getDList 정상 0 오류 -1
int getDList(dList* _dlist, int _index);

//iCount를 반환, 맨 마지막 index+1 
int countDList(dList* _dlist);

//노드 삭제 deleteDList 정상 0 오류 -1
int deleteDList(dList* _dlist, int _index);

#endif 
