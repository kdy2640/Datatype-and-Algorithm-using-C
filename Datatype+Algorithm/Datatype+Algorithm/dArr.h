#ifndef dARR
#define dARR

typedef struct dynamicArray {
	int* ptr;
	int iCount;
	int iMax;
}dArr;

//초기화
void startDArr(dArr* _darr);

//해제
void finishDArr(dArr* _darr);

//pushback
void pushDArr(dArr* _darr, int _data);

//pop
 int popDArr(dArr* _darr);

//peek
 int peekDArr(dArr* _darr);

//index 접근
 int getDataDArr(dArr* _darr);

#endif