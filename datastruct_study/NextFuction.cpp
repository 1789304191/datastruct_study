#include <iostream>
#include "str.h"
#include "print.h"

int main() {
	//�ַ�������Ϊ7����nextֵ��7��
	char a[] = "ABABC";
	String str = initAndAssignStr(a);
	int b[8];
	b[0] = -1;
	getNext(str,b);
	printArray(8,b);
	return 0;
}