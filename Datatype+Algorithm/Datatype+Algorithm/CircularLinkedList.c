#include<stdio.h>
#include<stdlib.h>
#include"CircularLinkedList.h"

//��带 �Ҵ�ް� �ּҸ� ��ȯ(���λ��)
iNode* createCNode(int _data, iNode* _prevPtr, iNode* _nextPtr)
{
	iNode* temp = (iNode*)malloc(sizeof(iNode));
	//�޸� ��ȿ�� �˻�
	if (temp == NULL)
	{
		printf("ERROR : Memory Allocation Failed.");
		return NULL;
	}
	temp->iData = _data; temp->prevPtr = _prevPtr; temp->nextPtr = _nextPtr;
	return temp;
}

//�� �ڿ� ��� �� �� �߰�
void addTailCList(cList* _clist, int _data)
{
	insertCList(_clist, _clist->iCount, _data);
}
//�� �տ� ��� �� �� �߰�
void addHeadCList(cList* _clist, int _data)
{
	insertCList(_clist, 0, _data);
}
//�ʱ�ȭ startCList
void startCList(cList* _clist)
{
	_clist->iCount = 0;
	_clist->headPtr = NULL;
	_clist->tailPtr = NULL;
}
//�߰� addHeadCList ���� 0 ���� -1
int insertCList(cList* _clist, int _index, int _data)
{	

	//�ε��� ��ȿ�� �˻�
	if (_clist->iCount < _index || _index < 0)
	{
		printf("ERROR : Index Out Of Value.");
		return -1;
	}
	iNode* temp;
	iNode* temp2;
	//��尡 ���� ��
	if (_clist->iCount == 0)
	{
		temp = createCNode(_data,NULL,NULL);  // temp�� ���ο� ��带 �Ҵ�
		temp->nextPtr = temp; temp->prevPtr = temp; // temp�� ���ķ� �ڽ��� �Ҵ�
		_clist->headPtr = temp; _clist->tailPtr = temp; // head�� tail�� ��带 ����Ű�� ����
	}
	//��尡 1�� �̻��� ��
	else 
	{
		// �տ� ���� ��
		if (_index == 0)
		{
			temp = createCNode(_data, _clist->tailPtr, _clist->headPtr); // head�� ��������, tail�� �������� �ϴ� ��� ����
			_clist->headPtr->prevPtr = temp; // ������ head�� ���������͸� temp�� ����
			_clist->tailPtr->nextPtr = temp; // tail�� ���� �����͸� temp�� ����
			_clist->headPtr = temp; // head�� temp�� ����;

		}
		// �ڿ� ���� ��
		else if (_index == _clist->iCount)
		{
			temp = createCNode(_data, _clist->tailPtr, _clist->headPtr); // head�� ��������, tail�� �������� �ϴ� ��� ����
			_clist->tailPtr->nextPtr = temp; // ������ tail�� ���������͸� temp�� ����
			_clist->headPtr->prevPtr = temp; // head�� ���� �����͸� temp�� ����
			_clist->tailPtr = temp; // tail�� temp�� ����
		}
		// �߰��� ���� ��
		else
		{	
			temp2 = _clist->headPtr;
			//temp2�� ���� �ٷ� ���� ��尡 �� �� �ְ� ����
			{
				// �տ��� ��ȸ
				if (_index < _clist->iCount / 2)
				{
					//index ��°�ϱ� index-1 �� �ݺ��ϸ� index-1 ���� ����� �ּҰ� ����
					for (int i = 1; i < _index; i++)
					{
						temp2 = temp2->nextPtr;
					}
				}
				// �ڿ��� ��ȸ
				else
				{
					//index �����ϱ� �ڿ��� iCount - index�� �ݺ��ϸ� index-1 ���� ����� �ּҰ� ����
					temp2 = _clist->tailPtr;
					int count = _clist->iCount - _index;
					for (int i = 0; i < count; i++)
					{
						temp2 = temp2->prevPtr;
					}
				}
			}

			temp = createCNode(_data, temp2, temp2->nextPtr); // index-1���� ��带 ��������, index���� ��带 �������� �ϴ� ��� temp�� ����
			temp2->nextPtr->prevPtr = temp; // index���� ����� ���������͸� temp�� ����
			temp2->nextPtr = temp; // index-1���� ����� ���������͸� temp�� ����
		}

	}

	_clist->iCount++;
	return 0;

}
//���� finishCList
void finishCList(cList* _clist)
{
	//������ 0������ Ȯ��
	if (_clist->iCount == 0)
	{
		return;
	}
	else
	{
		iNode* temp = _clist->headPtr;
		iNode* temp2 = NULL;
		int count = _clist->iCount;
		while (temp2 != _clist->headPtr)
		{
			temp2 = temp->nextPtr;  // temp2�� temp ���� ����� �ּҸ� �Ҵ�
			free(temp);  // temp�� ���� ��带 ����
			temp = temp2; //temp�� temp ���� ����� �ּҸ� �Ҵ�
			count--;
		}
		_clist->headPtr = NULL;
		_clist->tailPtr = NULL;
		_clist->iCount = 0;

	}
}
//�ε��� ���� getCList ���� 0 ���� -1
int getCList(cList* _clist, int _index)
{
	//�ε��� ��ȿ���˻�
	if (_clist->iCount <= _index || _index < 0)
	{
		printf("ERROR : Index Out Of Value.");
		return -1;
	}
	iNode* temp2 = _clist->headPtr;
	//temp2�� ������� �ٷ� ���� ��尡 �� �� �ְ� ����
	{
		// �տ��� ��ȸ
		if (_index < _clist->iCount / 2)
		{
			//index ��°�ϱ� index-1 �� �ݺ��ϸ� index-1 ���� ����� �ּҰ� ����
			for (int i = 1; i < _index; i++)
			{
				temp2 = temp2->nextPtr;
			}
		}
		// �ڿ��� ��ȸ
		else
		{
			//index �����ϱ� �ڿ��� iCount - index�� �ݺ��ϸ� index-1 ���� ����� �ּҰ� ����
			temp2 = _clist->tailPtr;
			int count = _clist->iCount - _index;
			for (int i = 0; i < count; i++)
			{
				temp2 = temp2->prevPtr;
			}
		}
	}
	return temp2->nextPtr->iData;
}

//iCount�� ��ȯ, �� ������ index+1 
int countCList(cList* _clist) 
{ 
	return _clist->iCount; }

//��� ���� deleteCList ���� 0 ���� -1
int deleteCList(cList* _clist, int _index)
{
	//�ε��� ��ȿ���˻�
	if (_clist->iCount <= _index || _index < 0)
	{
		printf("ERROR : Index Out Of Value.");
		return -1;
	}
	//��尡 ���� ��
	if (_clist->iCount == 0)
	{
		printf("ERROR : List is Empty.");
		return -1;
	}
	iNode* temp = _clist->headPtr;
	//��尡 1�� ���� ��
	if (_clist->iCount == 1)
	{
		free(temp);
		_clist->headPtr = NULL; _clist->tailPtr = NULL;
	}
	//��尡 2�� �̻� ������
	else
	{
		//�տ��� �� ��
		if (_index == 0)
		{
			_clist->headPtr->nextPtr->prevPtr = _clist->tailPtr; // ��� ��������� ���������͸� ���ϳ��� ����
			_clist->tailPtr->nextPtr = _clist->headPtr->nextPtr;// ���ϳ���� ���������͸� ��� �������� ����
			_clist->headPtr = _clist->headPtr->nextPtr; // ��带 ������ ��� ���� ���� ����
			free(temp);
			temp = NULL;
		}
		//�ڿ��� �E ��
		else if (_index == _clist->iCount - 1)
		{
			temp = _clist->tailPtr;
			_clist->tailPtr->prevPtr->nextPtr = _clist->headPtr; // ���� ��������� ���������͸� ������ ����
			_clist->headPtr->prevPtr = _clist->tailPtr->prevPtr; // ������� ���������͸� ���� �������� ����
			_clist->tailPtr = _clist->tailPtr->prevPtr; //������ ������ ��� ���� ���� ����
			free(temp);
			temp = NULL;
		}
		//�߰����� �E ��
		else
		{
			iNode* temp2 = _clist->headPtr;
			//temp2�� ������� �ٷ� ���� ��尡 �� �� �ְ� ����
			{
				// �տ��� ��ȸ
				if (_index < _clist->iCount / 2)
				{
					//index ��°�ϱ� index-1 �� �ݺ��ϸ� index-1 ���� ����� �ּҰ� ����
					for (int i = 1; i < _index; i++)
					{
						temp2 = temp2->nextPtr;
					}
				}
				// �ڿ��� ��ȸ
				else
				{
					//index �����ϱ� �ڿ��� iCount - index�� �ݺ��ϸ� index-1 ���� ����� �ּҰ� ����
					temp2 = _clist->tailPtr;
					int count = _clist->iCount - _index;
					for (int i = 0; i < count; i++)
					{
						temp2 = temp2->prevPtr;
					}
				}
			}
			temp = temp2->nextPtr; //��������� �ּҸ� ����
			temp2->nextPtr->nextPtr->prevPtr = temp2; // ������� ��������� ���������͸� ������� �������� ����
			temp2->nextPtr = temp2->nextPtr->nextPtr; // ������� ��������� ���������͸� ������� �������� ����
			free(temp);
			temp = NULL;
		}
	}

	_clist->iCount--;
	return 0;
}
