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
	˫����Ĵ���
	����nΪ�������ٸ��ڵ��˫����������ͷ�ڵ�
*/
void createDouLinedList(DStudent *&p,int n) {
	printf("\n˫����Ĵ�����\n");
	DStudent * start=NULL;
	DStudent * head;
	//�ȴ���һ��ͷ�ڵ�
	p = (DStudent *)malloc(LEN);
	//startΪͷ�ڵ�
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

//˫��������
void print_d(DStudent *p) {
	while (p!=NULL) {
		printf_s("\np=%d,num=%d,score=%f,prior=%d,next=%d\n", p, p->num, p->score, p->prior, p->next);
		p = p->next;
	}

}