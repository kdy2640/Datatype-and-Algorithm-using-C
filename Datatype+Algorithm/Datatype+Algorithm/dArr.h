#ifndef dARR
#define dARR

typedef struct dynamicArray {
	int* ptr;
	int iCount;
	int iMax;
}dArr;

//�ʱ�ȭ
void startDArr(dArr* _darr);

//����
void finishDArr(dArr* _darr);

//pushback
void pushDArr(dArr* _darr, int _data);

//pop
 int popDArr(dArr* _darr);

//peek
 int peekDArr(dArr* _darr);

//index ����
 int getDataDArr(dArr* _darr);

#endif