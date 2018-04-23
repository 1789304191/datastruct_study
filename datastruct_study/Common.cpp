#include <iostream>
#include "Student.h"


//数组的输出
void print_array(int num[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", num[i]);
	}
	printf("\n");
}

/*
如果temp比上一个元素小，则移动一位，然后继续和下一个元素比较并且移动，直到大于
时就将此时的元素的下一个值赋值给temp
*/
void merge_sequence(int a[], int m, int n) {
	void print_array(int num[], int n);
	int i;
	int j;
	for (i = m; i < m + n; i++) {
		int temp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (temp < a[j]) {
				//如果比temp大，则向后移动一位
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j + 1] = temp;
	}
}

struct Student * create() {

	struct Student * head, *p1, *p2;

	//先分配一个结构体的大小的空间 该方法返回空间的地址，但是不指向任何类型，所以需要强转

	head = (struct Student *)malloc(LENS);

	p2 = head;

	//当输入的参数不为0时

	scanf_s("%d,%f", &head->num, &head->score);

	head->next = NULL;

	//*p2.num p2->num

	while (p2->num != 0) {

		p1 = (struct Student *)malloc(LENS);

		//将p2的next赋值给新的空间p1

		scanf_s("%d,%f", &p1->num, &p1->score);

		p2->next = p1;

		p1->next = NULL;

		p2 = p1;

	}

	return head;

}

//输出链表

void print_(struct Student * p) {

	while (p != NULL) {

		printf("p=%d,num=%d,score=%2.1f,next=%d\n", p, p->num, p->score, p->next);

		p = p->next;
	}

}


//链表插入排序（从小到大）
struct Student * insertionSortByAsc(struct Student * head) {

	struct Student * p;

	struct Student * p0 = NULL;

	struct Student * p1;

	struct Student * p2;

	p1 = head;

	p2 = head->next;

	p = head->next;

	head->next = NULL;

	while (p != NULL) {

		p = p->next;

		while (p1 != NULL && p2->score > p1->score) {

			p0 = p1;

			p1 = p1->next;

		}

		//说明p2比p1小

		if (p1 == head) {

			head = p2;

			p2->next = p1;

		}

		else {

			p0->next = p2;

			p2->next = NULL;

		}

		p1 = head;

		p2 = p;

	}

	return head;

}

//将两个链表用尾插法合并并按原来的顺序
void merge(struct Student * a, struct Student * b, struct Student *&c) {
	struct Student * p = NULL;
	struct Student * p0 = NULL;
	while (a != NULL && b != NULL)
	{
		if (a->score <= b->score) {
			p = a;
			a = a->next;
		}
		else {
			p = b;
			b = b->next;
		}
		//赋值头节点
		if (c == NULL) {
			c = p;
		}
		if (p0 != NULL) {
			//把较小的节点放在p0后面，即c后面
			p0->next = p;
			//p0为c下一个节点 这里相当于p0指向新添的节点
			p0 = p0->next;
		}
		else {
			p0 = c;
		}
		//保证终端都是新添的节点
		p->next = NULL;
	}
	if (a == NULL && b != NULL) {
		p0->next = b;
	}
	else if (a != NULL && b == NULL) {
		p0->next = a;
	}
}

//创建带头节点的单链表
struct Student * createWithHead() {

	struct Student * head, *p1, *p2;

	head = (struct Student *)malloc(LENS);

	p2 = head;

	head->next = NULL;

	do {
		p1 = (struct Student *)malloc(LENS);
		//当输入的参数不为0时
		scanf_s("%d,%f", &p1->num, &p1->score);
		p2->next = p1;
		p1->next = NULL;
		p2 = p2->next;
	} while (p1->num != 0);

	return head;

}


//带头节点链表插入排序（从小到大）
void insertionSortByAscWithHead(Student * head) {

	Student * p;
	//第一个节点
	p = head->next;
	//保留头节点
	head->next = NULL;

	Student * p0;
	Student * p1;
	Student * p2 = NULL;
	//头节点之后的第一个节点
	Student * p3 = p;
	//第二个节点
	p1= p0 = p->next;
	p->next = NULL;
	while (p1 != NULL) {
		p1 = p1->next;
		while (p != NULL && p0->num > p->num) {
			p2 = p;
			p = p->next;
		}
		if (p == p3) {
			p3 = p0;
			p0->next = p;
		}
		else {
			p0->next = p2->next;
			p2->next = p0;
		}
		p = p3;
		p0 = p1;
	}
	head->next = p3;
}