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
//	//printf("\n˫�������:\n");
//	//print_d(find_d(p,2));
//	//printf("\n˫�������:\n");
//	//print_d(insert_d(p, create_one_d()));
//	printf("\nɾ���ڵ�֮��\n");
//	delete_d(p, 2);
//	print_d(p);
//	return 0;
//}


/*
	˫����Ĵ���
	����nΪ�������ٸ��ڵ��˫����������ͷ�ڵ�
*/
void createDouLinedList(DStudent *&p,int n) {
	printf("\n˫����Ĵ�����\n");
	DStudent * start=NULL;
	DStudent * head;
	//�ȴ���һ��ͷ�ڵ�
	p = (DStudent *)malloc(LENDS);
	//startΪͷ�ڵ�
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

//˫��������
void print_d(DStudent *p) {
	while (p!=NULL) {
		printf_s("\np=%d,num=%d,score=%f,prior=%d,next=%d\n", p, p->num, p->score, p->prior, p->next);
		p = p->next;
	}

}

//˫����Ĳ���
DStudent * find_d(DStudent *p,int n) {
	while (p != NULL) {
		if (p->num == n) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

//˫����Ĳ���(��˳�����)
DStudent * insert_d(DStudent *p0, DStudent *p1) {
	DStudent * head = p0;
	while (p0 != NULL) {
		if (p0->prior == NULL) {
			p0 = p0->next;
			continue;
		}
		if (p0->num > p1->num) {
			//��ǰ����
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

//˫�����ڵ�Ĵ���
DStudent * create_one_d() {
	DStudent * p = (DStudent *)malloc(LENDS);
	scanf_s("%d,%f", &p->num, &p->score);
	p->next = NULL;
	p->prior = NULL;
	return p;
}

//ɾ��ĳһ���ڵ�
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

