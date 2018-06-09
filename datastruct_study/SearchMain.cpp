#include <iostream>
#include "search.h"
#include "print.h"
#include "SearchTestCase.h"

int main() {
	
	int array[5] = { 1,2,3,4,5 };

	//1.ÕÛ°ë²éÕÒ·¨
	//printInt(Bsearch(array, 0, 4, 3));

	//2.¶þ²æÅÅÐòÊ÷
	printInt(BSTSearch(initBTNode(), 3)->key);

}