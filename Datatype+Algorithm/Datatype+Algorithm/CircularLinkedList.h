#ifndef _CIRCULARLINKECLIST_H_
#define _CIRCULARLINKECLIST_H_

typedef struct oneNode {
	int iData;
	struct oneNode* nextPtr;
	struct oneNode* prevPtr;
}iNode;

typedef struct CircularlinkeCList {
	int iCount;
	iNode* headPtr;
	iNode* tailPtr;
}cList;

//맨 뒤에 노드 한 개 추가
void addTailCList(cList* _clist, int _data);
//맨 앞에 노드 한 개 추가
void addHeadCList(cList* _clist, int _data);
//초기화 startCList
void startCList(cList* _clist);
//추가 addHeadCList 정상 0 오류 -1
int insertCList(cList* _clist, int _index, int _data);
//해제 finishCList
void finishCList(cList* _clist);
//인덱스 접근 getCList 정상 0 오류 -1
int getCList(cList* _clist, int _index);

//iCount를 반환, 맨 마지막 index+1 
int countCList(cList* _clist);

//노드 삭제 deleteCList 정상 0 오류 -1
int deleteCList(cList* _clist, int _index);

#endif 
