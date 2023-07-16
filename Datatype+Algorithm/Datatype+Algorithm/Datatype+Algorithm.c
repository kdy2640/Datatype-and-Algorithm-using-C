#include <stdio.h>
#include"linkedStack.h"

int main()
{
	lStack ls;
	startLStack(&ls);
	for (int i = 0; i < 20; i++)
	{
		pushLStack(&ls, i);
	}
	pushLStack(&ls, 200);
	popLStack(&ls);
	
	popLStack(&ls);
	
	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", popLStack(&ls));
	}

}
