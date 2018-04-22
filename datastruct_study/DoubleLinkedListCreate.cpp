#include <iostream>
#include "Student.h"




//int main() {
//	void createDouLinedList(DStudent *&p, int n);
//	DStudent * find_d(DStudent *p, int n);
//	void print_d(DStudent *p);
//	DStudent * create_one_d();
//	DStudent * insert_d(DStudent *p0, DStudent *p1);
//	void delete_d(DStudent *p0, int n);
//	DStudent *p;
//	createDouLinedList(p, 5);
//	print_d(p);
//	//printf("\n双链表查找:\n");
//	//print_d(find_d(p,2));
//	//printf("\n双链表插入:\n");
//	//print_d(insert_d(p, create_one_d()));
//	printf("\n删除节点之后\n");
//	delete_d(p, 2);
//	print_d(p);
//	return 0;
//}


/*
	双链表的创建
	参数n为创建多少个节点的双链表，不包括头节点
*/
void createDouLinedList(DStudent *&p,int n) {
	printf("\n双链表的创建：\n");
	DStudent * start=NULL;
	DStudent * head;
	//先创建一个头节点
	p = (DStudent *)malloc(LENDS);
	//start为头节点
	head = p;
	p->prior = NULL;
	p->next = NULL;
	for (int i = 0; i < n; i++) {
		start=(DStudent *)malloc(LENDS);
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

//双链表的查找
DStudent * find_d(DStudent *p,int n) {
	while (p != NULL) {
		if (p->num == n) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

//双链表的插入(按顺序插入)
DStudent * insert_d(DStudent *p0, DStudent *p1) {
	DStudent * head = p0;
	while (p0 != NULL) {
		if (p0->prior == NULL) {
			p0 = p0->next;
			continue;
		}
		if (p0->num > p1->num) {
			//往前插入
			p1->prior = p0->prior;
			p0->prior->next = p1;
			p1->next = p0;
			p0->prior = p1;
			return head;
		}
		p0 = p0->next;
	}
	return head;
}

//双链表单节点的创建
DStudent * create_one_d() {
	DStudent * p = (DStudent *)malloc(LENDS);
	scanf_s("%d,%f", &p->num, &p->score);
	p->next = NULL;
	p->prior = NULL;
	return p;
}

//删除某一个节点
void delete_d(DStudent *p0, int n) {
	DStudent * head = p0;
	p0 = p0->next;
	while (p0 != NULL) {
		if (p0->num == n) {
			p0->prior->next = p0->next;
			p0->next->prior = p0->prior;
			free(p0);
			p0 = head;
			return;
		}
		p0 = p0->next;
	}
	p0 = head;
}

