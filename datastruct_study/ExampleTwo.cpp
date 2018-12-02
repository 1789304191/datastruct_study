#include <iostream>
#include "Student.h"

//int main() {
//	printf("第一个链表\n");
//	Student * p1 = createWithHead();
//	//不能改变p的指，但是可以改变p的指向的值
//	insertionSortByAscWithHead(p1);
//	print_(p1);
//	printf("第二个链表\n");
//	Student * p2 = createWithHead();
//	insertionSortByAscWithHead(p2);
//	print_(p2);
//	printf("去重之后\n");
//	distinct(p1, p2);
//	print_(p1);
//	return 0;
//}

//int main() {
//
//	//带头节点
//	struct Node * head,* p1,* p2;
//	head = (struct Node *)malloc(NodeLENS);
//	p1 = (struct Node *)malloc(NodeLENS);
//	p1->data = 1;
//	p2 = (struct Node *)malloc(NodeLENS);
//	p2->data = 2;
//	p1->next = p2;
//	p2->next = NULL;
//	head->data = NULL;
//	head->next = p1;
//	return 0;
//}