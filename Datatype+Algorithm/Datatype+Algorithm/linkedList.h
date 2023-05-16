#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct oneNode {
	int iData;
	struct oneNode* nextPtr;
}iNode;

typedef struct linkedList {
	int iCount;
	struct iNode* headPtr;
}lList;

//��� 1�� �ø��� addNode * ����
void addNode(lList* _llist);
//�ʱ�ȭ startLList
void startLList(lList* _llist);
//�߰� addHeadLList
void addHeadList(lList* _llist, int _index);
//���� finishLList
void finishLList(lList* _llist);
//�ε��� ���� getLList
int getLLIst(lList* _llist, int _index);
//���� lenLList 
int lenLList(lList* _llist);
//��� ���� deleteLList
void deleteLList(lList* _llist,int _index);

#endif 
