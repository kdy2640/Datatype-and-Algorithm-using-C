#include<stdlib.h>
#include<stdio.h>
#include "DoubleLinkedList.h"


//��� �ϳ��� ���� (���ο����� ���)
iNode* createNode(int _data, iNode* _prevPtr,  iNode* _nextPtr )
{
	iNode* newNode = (iNode*)malloc(sizeof(iNode));
	// �Ҵ� ���� �˻�
	if (newNode == NULL) 
	{
		printf("Error : Memory Allocation Failed");
		return NULL;
	}
	newNode->iData = _data;
	newNode->nextPtr = _nextPtr;
	newNode->prevPtr = _prevPtr;
	return newNode;
}
//�� �ڿ� ��� �� �� �߰�
void addTailDList(dList* _dlist, int _data)
{
	insertDList(_dlist, countDList(_dlist), _data);
}
//�� �տ� ��� �� �� �߰�
void addHeadDList(dList* _dlist, int _data)
{
	insertDList(_dlist, 0, _data);
}
//�ʱ�ȭ startDList
void startDList(dList* _dlist)
{
	_dlist->iCount = 0;
	_dlist->headPtr = NULL;
	_dlist->tailPtr = NULL;
}
//�߰� addHeadDList
int insertDList(dList* _dlist, int _index, int _data)
{
	//�ε��� ��ȿ�� �˻�
	if (_index > _dlist->iCount)
	{
		printf("Error : Index Out Of Range.");
		return -1;
	}
	// �ƹ� ��嵵 ���� ��
	if (_dlist->iCount == 0)
	{
		iNode* newNode = createNode(_data, NULL, NULL);
		_dlist->headPtr = newNode;
		_dlist->tailPtr = newNode;
	} 
	//��尡 ������
	else
	{
		//�տ� ���� ��
		if (_index == 0)
		{
			iNode* newNode = createNode(_data, NULL, _dlist->headPtr);//head(0���� ���)�� �������� �ϴ� ��� ����
			_dlist->headPtr->prevPtr = newNode; // 0���� ����� ���������Ͱ� newNode�� �ǵ��� ����
			_dlist->headPtr = newNode; //headptr�� newNode�� ����Ű���� ����
		}
		// �ڿ� ���� ��
		else if (_index == _dlist->iCount)
		{
			iNode* newNode = createNode(_data, _dlist->tailPtr, NULL);//tail(iCount-1���� ���)�� �������� �ϴ� ��� ����
			_dlist->tailPtr->nextPtr = newNode;// iCount-1���� ����� ���������Ͱ� newNode�� ������ ����
			_dlist->tailPtr = newNode; // tailptr�� newNode�� ����Ű���� ����
		}
		// �߰��� ���� ��
		else
		{
			iNode* temp;

			if (_index > _dlist->iCount / 2) //�ڿ��� ��ȸ
			{
				temp = _dlist->tailPtr;
				int indexdiff = _dlist->iCount - _index;
				for (int i = 0; i < indexdiff; i++)
				{
					temp = temp->prevPtr;
				} // temp =  _index-1���� ����� ������
			}
			else // �տ��� ��ȸ
			{
				temp = _dlist->headPtr;
				for (int i = 1; i < _index; i++)
				{
					temp = temp->nextPtr;
				} // temp =  _index-1���� ����� ������
			}

			iNode* newNode = createNode(_data, temp, temp->nextPtr); // _index-1 ��° ��带 ��������, _index���� ��带 �������� �ϴ� ��带 ����
			temp->nextPtr->prevPtr = newNode; // _index���� ��尡 newNode�� �������� �ϰ� ����
			temp->nextPtr = newNode; // _index-1���� ��尡 newNode�� �������� �ϰ� ����

		}
	} 
	_dlist->iCount++;
	return 0;

}
//���� finishDList
void finishDList(dList* _dlist)
{
	iNode* temp = _dlist->headPtr;
	iNode* next;
	//��尡 �ƹ��͵� ���� ��
	if (temp != NULL)
	{
		//NULL�� ���Ë����� ����
		while (temp->nextPtr != NULL)
		{
			next = temp->nextPtr;
			free(temp);
			temp = next;
		}
		free(temp);
	}
	_dlist->iCount = 0;
	_dlist->headPtr = NULL;
	_dlist->tailPtr = NULL;
}
//�ε��� ���� getDList
int getDList(dList* _dlist, int _index)
{
	//index ��ȿ�� �˻�
	if (_index >= _dlist->iCount) 
	{
		printf("Error : Index Out Of Range.");
		return -1;
	}
	// �� �տ����ϋ�
	if (_index == 0)
	{
		return _dlist->headPtr->iData;
	}
	iNode* temp;
	// �ڷ� ��ȸ
	if (_index > _dlist->iCount / 2) //�ڿ��� ��ȸ
	{
		temp = _dlist->tailPtr;
		int indexdiff = _dlist->iCount - _index;
		for (int i = 0; i < indexdiff; i++)
		{
			temp = temp->prevPtr;
		} // temp =  _index-1���� ����� ������
	}
	//������ ��ȸ
	else // �տ��� ��ȸ
	{
		temp = _dlist->headPtr;
		for (int i = 1; i < _index; i++)
		{
			temp = temp->nextPtr;
		} // temp =  _index-1���� ����� ������
	}
	return temp->nextPtr->iData;
}
//iCount�� ��ȯ, �� ������ index+1 
int countDList(dList* _dlist)
{
	return _dlist->iCount;
}
//��� ���� deleteDList
int deleteDList(dList* _dlist, int _index)
{

	//index ��ȿ�� �˻�
	if (_index >= _dlist->iCount)
	{
		printf("Error : Index Out Of Range.");
		return -1;
	}

	iNode* temp;
	// ��尡 1���϶�
	if(_dlist->iCount==1) 
	{
		free(_dlist->headPtr);
		_dlist->headPtr = NULL;
		_dlist->tailPtr = NULL;

	}
	else
	{
		// ��尡 2�� �̻��̰� head�� ���ﶧ
		if (_index == 0) 
		{
			temp = _dlist->headPtr; 
			_dlist->headPtr->nextPtr->prevPtr = NULL; // 1��° ����� ���� ���̳ʸ� NULL�� ��ȯ
			_dlist->headPtr = _dlist->headPtr->nextPtr; //headptr�� 1��° ��带 ����Ű�� ����
			free(temp); temp = NULL;

		}
		// ��尡 2�� �̻��̰� tail�� ���� ��
		else if (_index == _dlist->iCount - 1) 
		{
			temp = _dlist->tailPtr;
			_dlist->tailPtr->prevPtr->nextPtr = NULL; // iCount -2 ���� ����� ���� �����͸� NULL�� ��ȯ
			_dlist->tailPtr = _dlist->tailPtr->prevPtr; //tailptr�� iCount - 2 ��° ��带 ����Ű�� ����
			free(temp); temp = NULL;
		}
		// ��尡 2�� �̻��̰� �߰��� ���� ��
		else 
		{

			if (_index > _dlist->iCount / 2) //�ڿ��� ��ȸ
			{
				temp = _dlist->tailPtr;
				int indexdiff = _dlist->iCount - _index;
				for (int i = 0; i < indexdiff; i++)
				{
					temp = temp->prevPtr;
				} // temp =  _index-1���� ����� ������
			}
			else // �տ��� ��ȸ
			{
				temp = _dlist->headPtr;
				for (int i = 1; i < _index; i++)
				{
					temp = temp->nextPtr;
				} // temp =  _index-1���� ����� ������
			}
			iNode* temp2 = temp->nextPtr; //temp2 = _index���� ����� ������
			temp->nextPtr->nextPtr->prevPtr = temp; //_index+1 ���� ����� ���� �����͸� temp(_index-1���� ���)�� ����
			temp->nextPtr = temp->nextPtr->nextPtr; //_index-1 ���� ����� ���� �����͸� _index+1��° ���� ����
			free(temp2); temp2 = NULL;
		}
	}
	_dlist--;
	return 0;
}
