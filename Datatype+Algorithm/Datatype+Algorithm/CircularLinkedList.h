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

//�� �ڿ� ��� �� �� �߰�
void addTailCList(cList* _clist, int _data);
//�� �տ� ��� �� �� �߰�
void addHeadCList(cList* _clist, int _data);
//�ʱ�ȭ startCList
void startCList(cList* _clist);
//�߰� addHeadCList ���� 0 ���� -1
int insertCList(cList* _clist, int _index, int _data);
//���� finishCList
void finishCList(cList* _clist);
//�ε��� ���� getCList ���� 0 ���� -1
int getCList(cList* _clist, int _index);

//iCount�� ��ȯ, �� ������ index+1 
int countCList(cList* _clist);

//��� ���� deleteCList ���� 0 ���� -1
int deleteCList(cList* _clist, int _index);

#endif 
