#include <iostream>
#include "Student.h"

int main() {
	printf("第一个链表\n");
	Student * p1 = createWithHead();
	//不能改变p的指，但是可以改变p的指向的值
	insertionSortByAscWithHead(p1);
	print_(p1);
	printf("第二个链表\n");
	Student * p2 = createWithHead();
	insertionSortByAscWithHead(p2);
	print_(p2);
	printf("去重之后\n");
	distinct(p1, p2);
	print_(p1);
	return 0;
}