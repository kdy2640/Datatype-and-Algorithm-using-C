#include <stdio.h>
#include "linkedList.h"
int main()
{

	int temp;
	lList a;
	startLList(&a);
	for (int i = 1; i < 10; i++)
	{
		addLList(&a,i);
	}
	insertLList(&a, 4, 36);
	deleteLList(&a, 7);
	deleteLList(&a, 0);
	insertLList(&a,0, 125);
	insertLList(&a, lenLList(&a), 999);
	insertLList(&a, lenLList(&a), 999);
	deleteLList(&a, lenLList(&a)-1);

	for (int i = 0; i < lenLList(&a); i++)
	{
		temp = getLLIst(&a, i);
		printf("%d\n", temp);
	}
}
