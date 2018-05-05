#include <iostream>
#include "str.h"
#include "print.h"

int main() {
	char a[] = "abab";
	String str = initAndAssignStr(a);
	int b[5];
	b[0] = -1;
	getNext(str,b);
	printArray(5,b);
	return 0;
}