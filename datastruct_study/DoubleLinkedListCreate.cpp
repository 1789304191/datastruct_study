#include <iostream>
#include "Student.h"

#define LEN sizeof(struct DStudent)

typedef struct DStudent DStudent;

int main() {
	void createDouLinedList(DStudent *&p, int n);
	void print_d(DStudent *p);
	DStudent *p;
	createDouLinedList(p, 5);
	print_d(p);
	return 0;
}


/*
	双链表的创建
	参数n为创建多少个节点的双链表，不包括头节点
*/
void createDouLinedList(DStudent *&p,int n) {
	printf("\n双链表的创建：\n");
	DStudent * start=NULL;
	DStudent * head;
	//先创建一个头节点
	p = (DStudent *)malloc(LEN);
	//start为头节点
	head = p;
	p->prior = NULL;
	p->next = NULL;
	for (int i = 0; i < n; i++) {
		start=(DStudent *)malloc(LEN);
		scanf_s("%d,%f", &start->num, &start->score);
		p->next = start;
		start->prior = p;
		p = p->next;
	}
	start->next = NULL;
	p = head;
}

//双链表的输出
void print_d(DStudent *p) {
	while (p!=NULL) {
		printf_s("\np=%d,num=%d,score=%f,prior=%d,next=%d\n", p, p->num, p->score, p->prior, p->next);
		p = p->next;
	}

}