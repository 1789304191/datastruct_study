#include <iostream>
#include "str.h"
#include "print.h"

int main() {
	//字符串长度为7所以next值有7个
	char a[] = "ABABC";
	String str = initAndAssignStr(a);
	int b[8];
	b[0] = -1;
	getNext(str,b);
	printArray(8,b);
	return 0;
}