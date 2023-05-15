#include "dArr.h"
#include <stdio.h>
int main()
{
	dArr a;
	startDArr(&a);
	pushDArr(&a, 4);
	pushDArr(&a, 125);
	printf("%d %d %d", popDArr(&a), peekDArr(&a), popDArr(&a));

}
