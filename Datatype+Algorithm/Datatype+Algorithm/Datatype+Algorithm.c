#include <stdio.h>
#include "DoubleLinkedList.h"
int main()
{

	int temp;
	dList a;
	startDList(&a);
	for (int i = 0; i < 20; i++)
	{
		addTailDList(&a,i);
	}

	insertDList(&a, 8, 999);
	deleteDList(&a, 9);
	deleteDList(&a, 0);
	deleteDList(&a, countDList(&a)-1);
	for (int i = 0; i < countDList(&a); i++)
	{
		temp = getDList(&a, i);
		printf("%d\n", temp);
	}
}
