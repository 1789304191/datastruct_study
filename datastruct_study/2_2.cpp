#include <iostream>
#include "Student.h"

#define LEN sizeof(struct Student)

int main() {
	struct Student * create();
	void print_(struct Student * p);
	struct Student * insertionSortByAsc(struct Student * head);
	void merge(struct Student * a, struct Student * b, struct Student *&c);
	printf("\n链表一：\n");
	struct Student * p1 = create();
	p1= insertionSortByAsc(p1);
	print_(p1);
	printf("\n链表二：\n");
	struct Student * p2 = create();
	p2 = insertionSortByAsc(p2);
	print_(p2);
	printf("\n链表一和二链接连接之后：\n");
	struct Student * c=NULL;
	merge(p1, p2, c);
	print_(c);
	return 0;
}

//定义一个创建动态链表的方法，方法返回head

//动态创建链表

struct Student * create() {

	struct Student * head, *p1, *p2;

	//先分配一个结构体的大小的空间 该方法返回空间的地址，但是不指向任何类型，所以需要强转

	head = (struct Student *)malloc(LEN);

	p2 = head;

	//当输入的参数不为0时

	scanf_s("%d,%f", &head->num, &head->score);

	head->next = NULL;

	//*p2.num p2->num

	while (p2->num != 0) {

		p1 = (struct Student *)malloc(LEN);

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

	if (p->next == NULL)

		printf("p=%d,num=%d,score=%2.1f,next=%d\n", p, p->num, p->score, p->next);

	while (p->next != NULL) {

		printf("p=%d,num=%d,score=%2.1f,next=%d\n", p, p->num, p->score, p->next);

		p = p->next;

		if (p->next == NULL)

			printf("p=%d,num=%d,score=%2.1f,next=%d\n", p, p->num, p->score, p->next);

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
	while (a!=NULL&&b!=NULL)
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
		if (c==NULL) {
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
	else if(a != NULL && b == NULL){
		p0->next = a;
	}
}