#include <iostream>
#include "Student.h"

#define LEN sizeof(struct Student)

int main() {
	struct Student * create();
	void print_(struct Student * p);
	struct Student * insertionSortByAsc(struct Student * head);
	void merge(struct Student * a, struct Student * b, struct Student *&c);
	printf("\n����һ��\n");
	struct Student * p1 = create();
	p1= insertionSortByAsc(p1);
	print_(p1);
	printf("\n�������\n");
	struct Student * p2 = create();
	p2 = insertionSortByAsc(p2);
	print_(p2);
	printf("\n����һ�Ͷ���������֮��\n");
	struct Student * c=NULL;
	merge(p1, p2, c);
	print_(c);
	return 0;
}

//����һ��������̬����ķ�������������head

//��̬��������

struct Student * create() {

	struct Student * head, *p1, *p2;

	//�ȷ���һ���ṹ��Ĵ�С�Ŀռ� �÷������ؿռ�ĵ�ַ�����ǲ�ָ���κ����ͣ�������Ҫǿת

	head = (struct Student *)malloc(LEN);

	p2 = head;

	//������Ĳ�����Ϊ0ʱ

	scanf_s("%d,%f", &head->num, &head->score);

	head->next = NULL;

	//*p2.num p2->num

	while (p2->num != 0) {

		p1 = (struct Student *)malloc(LEN);

		//��p2��next��ֵ���µĿռ�p1

		scanf_s("%d,%f", &p1->num, &p1->score);

		p2->next = p1;

		p1->next = NULL;

		p2 = p1;

	}

	return head;

}

//�������

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


//����������򣨴�С����
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

		//˵��p2��p1С

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

//������������β�巨�ϲ�����ԭ����˳��
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
		//��ֵͷ�ڵ�
		if (c==NULL) {
			c = p;
		}
		if (p0 != NULL) {
			//�ѽ�С�Ľڵ����p0���棬��c����
			p0->next = p;
			//p0Ϊc��һ���ڵ� �����൱��p0ָ������Ľڵ�
			p0 = p0->next;
		}
		else {
			p0 = c;
		}
		//��֤�ն˶�������Ľڵ�
		p->next = NULL;
	}
	if (a == NULL && b != NULL) {
		p0->next = b;
	}
	else if(a != NULL && b == NULL){
		p0->next = a;
	}
}