#include <iostream>
#include "Student.h"


//��������
void print_array(int num[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", num[i]);
	}
	printf("\n");
}

/*
���temp����һ��Ԫ��С�����ƶ�һλ��Ȼ���������һ��Ԫ�رȽϲ����ƶ���ֱ������
ʱ�ͽ���ʱ��Ԫ�ص���һ��ֵ��ֵ��temp
*/
void merge_sequence(int a[], int m, int n) {
	void print_array(int num[], int n);
	int i;
	int j;
	for (i = m; i < m + n; i++) {
		int temp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (temp < a[j]) {
				//�����temp��������ƶ�һλ
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

	//�ȷ���һ���ṹ��Ĵ�С�Ŀռ� �÷������ؿռ�ĵ�ַ�����ǲ�ָ���κ����ͣ�������Ҫǿת

	head = (struct Student *)malloc(LENS);

	p2 = head;

	//������Ĳ�����Ϊ0ʱ

	scanf_s("%d,%f", &head->num, &head->score);

	head->next = NULL;

	//*p2.num p2->num

	while (p2->num != 0) {

		p1 = (struct Student *)malloc(LENS);

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

	while (p != NULL) {

		printf("p=%d,num=%d,score=%2.1f,next=%d\n", p, p->num, p->score, p->next);

		p = p->next;
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
		//��ֵͷ�ڵ�
		if (c == NULL) {
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
	else if (a != NULL && b == NULL) {
		p0->next = a;
	}
}

//������ͷ�ڵ�ĵ�����
struct Student * createWithHead() {

	struct Student * head, *p1, *p2;

	head = (struct Student *)malloc(LENS);

	p2 = head;

	head->next = NULL;

	do {
		p1 = (struct Student *)malloc(LENS);
		//������Ĳ�����Ϊ0ʱ
		scanf_s("%d,%f", &p1->num, &p1->score);
		p2->next = p1;
		p1->next = NULL;
		p2 = p2->next;
	} while (p1->num != 0);

	return head;

}


//��ͷ�ڵ�����������򣨴�С����
void insertionSortByAscWithHead(Student * head) {

	Student * p;
	//��һ���ڵ�
	p = head->next;
	//����ͷ�ڵ�
	head->next = NULL;

	Student * p0;
	Student * p1;
	Student * p2 = NULL;
	//ͷ�ڵ�֮��ĵ�һ���ڵ�
	Student * p3 = p;
	//�ڶ����ڵ�
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