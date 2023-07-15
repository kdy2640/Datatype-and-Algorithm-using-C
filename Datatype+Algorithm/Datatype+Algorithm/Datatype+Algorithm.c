#include <stdio.h>
#include "CircularLinkedList.h"
int main()
{
	int temp;
	cList a;
	startCList(&a);
	for (int i = 0; i < 20; i++)
	{
		addTailCList(&a,i);
	}

	insertCList(&a, 8, 999);
	deleteCList(&a, 9);
	deleteCList(&a, 0);
	deleteCList(&a, countCList(&a)-1);
	for (int i = 0; i < countCList(&a); i++)
	{
		temp = getCList(&a, i);
		printf("%d\n", temp);
	}
}
