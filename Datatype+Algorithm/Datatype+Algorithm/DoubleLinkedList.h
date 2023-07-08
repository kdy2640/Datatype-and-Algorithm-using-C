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

//�� �ڿ� ��� �� �� �߰�
void addTailDList(dList* _dlist, int _data);
//�� �տ� ��� �� �� �߰�
void addHeadDList(dList* _dlist, int _data);
//�ʱ�ȭ startDList
void startDList(dList* _dlist);
//�߰� addHeadDList ���� 0 ���� -1
int insertDList(dList* _dlist, int _index, int _data);
//���� finishDList
void finishDList(dList* _dlist);
//�ε��� ���� getDList ���� 0 ���� -1
int getDList(dList* _dlist, int _index);

//iCount�� ��ȯ, �� ������ index+1 
int countDList(dList* _dlist);

//��� ���� deleteDList ���� 0 ���� -1
int deleteDList(dList* _dlist, int _index);

#endif 
