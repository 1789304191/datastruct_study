#include <iostream>
#include "BTree.h"
#include "print.h"

//typedef struct node {
//
//	int data;
//	struct node *next, *prior;
//}LinkList;
//
//�����ֵܱ�ʾ��
typedef struct tnode {
	char data;
	struct tnode * firstchild, *nextsibling;
}tnode;

////ֱ�Ӳ��뷨����ͷ�ȽϿ�ʼ����2016�����ڶ��⣩
//void insert(LinkList *head) {
//
//	LinkList *p, *s, *q;
//	p = head->next;
//	while (p != NULL) {
//		s = head;
//		q = head->prior;
//		while ((q != NULL) && (p->data > q->data)) {
//			s = q;
//			q = q->prior;
//		}
//		s->prior = p;
//		p->prior = q;
//		p = p->next;
//	}
//
//}
//int main() {
//	BTNode * p1 = (BTNode *)malloc(sizeof(BTNode));
//	p1->c = '*';
//	BTNode * p2 = (BTNode *)malloc(sizeof(BTNode));
//	p2->c = '-';
//	BTNode * p3 = (BTNode *)malloc(sizeof(BTNode));
//	p3->c = '/';
//	BTNode * p4 = (BTNode *)malloc(sizeof(BTNode));
//	p4->c = 'a';
//	BTNode * p5 = (BTNode *)malloc(sizeof(BTNode));
//	p5->c = '+';
//	BTNode * p6 = (BTNode *)malloc(sizeof(BTNode));
//	p6->c = 'e';
//	BTNode * p7 = (BTNode *)malloc(sizeof(BTNode));
//	p7->c = 'e';
//	BTNode * p8 = (BTNode *)malloc(sizeof(BTNode));
//	p8->c = 'b';
//	BTNode * p9 = (BTNode *)malloc(sizeof(BTNode));
//	p9->c = 'c';
//
//	p1->lchild = p2;
//	p1->rchild = p3;
//
//	p2->lchild = p4;
//	p2->rchild = p5;
//	p4->lchild = NULL;
//	p4->rchild = NULL;
//
//	p3->lchild = p6;
//	p3->rchild = p7;
//
//	p6->lchild = NULL;
//	p6->rchild = NULL;
//	p7->lchild = NULL;
//	p7->rchild = NULL;
//
//	p5->lchild = p8;
//	p5->rchild = p9;
//
//	p8->lchild = NULL;
//	p8->rchild = NULL;
//	p9->lchild = NULL;
//	p9->rchild = NULL;
//}
////����׳�
//int factorial(int n) {
//
//	int sum = n;
//
//	while (n > 1) {
//
//		sum = sum * (n - 1);
//		n--;
//	}
//	return sum;
//}
////һ����λ��abc������ÿλ���ֵĽ׳�֮�ͣ���abc=a!+b!+c! ��ӡ����������
//int total(int n) {
//	
//	int a = n / 100;
//	int b = (n - a * 100) / 10;
//	int c = n - a * 100 - b * 10;
//	int sum = 0;
//	sum += factorial(a);
//	sum += factorial(b);
//	sum += factorial(c);
//	if (sum == n) {
//		printf("%d\n", n);
//	}
//	return 0;
//}
//
//��2018���һ�⣩
//int exchange(TBTNode * t) {
//	int ldepth = 0;
//	int rdepth = 0;
//	if (t->lchild == NULL && t->rchild == NULL)
//		return 1;
//	else {
//		TBTNode * temp = t->lchild;
//		t->lchild = t->rchild;
//		t->rchild = temp;
//	}
//	if (t->lchild)
//		ldepth = exchange(t->lchild);
//	if (t->rchild) {
//		rdepth = exchange(t->rchild);
//	}
//	return (ldepth > rdepth ? ldepth : rdepth) + 1;
//}
//
//void cal(TBTNode * t) {
//	if (t->lchild == NULL && t->rchild == NULL)
//		return;
//	else
//	{
//		
//	}
//	if (t->lchild != NULL) {
//		cal(t->lchild);
//	}
//	if (t->rchild != NULL) {
//		cal(t->rchild);
//	}
//}
//
//
//int count = 1;(2017���һ��)
//void nodedepth(TNode * tree) {
//
//	//���û�к��ӽ�����Ҷ�ӽڵ�
//	if (!tree->firstchild) {
//		printf("���ֵ��%c,��������%d\n", tree->data, count);
//	}
//	else
//	{
//		//ȡ���ӽڵ�      �൱�ڲ�α��� ����˵�ǹ�����ȱ���   //ȡ�ֵܽڵ�
//		for (tree = tree->firstchild; tree; tree = tree->nextsibling) {
//			//����һ���һ
//			count++;
//			nodedepth(tree);
//			//����һ�μ�һ
//			count--;
//		}
//	}
//}
//
////����Ҷ�ӽڵ�ĸ���
//int calNum(TNode * tree) {
//	
//	//���û�к��ӽ�����Ҷ�ӽڵ�
//	if (!tree->firstchild) {
//		return 1;
//	}
//	else
//	{
//		count = 0;
//		//�൱�ڲ�α��� ����˵�ǹ�����ȱ���
//		for (tree = tree->firstchild; tree; tree = tree->nextsibling) {
//			count += calNum(tree);
//			return count;//������Ҷ�ڵ�֮��
//		}
//	}
//
//}


//int main() {
//		//TBTNode * t1 = (TBTNode *)malloc(sizeof(TBTNode));
//		//t1->data = 'A';
//		//TBTNode * t2 = (TBTNode *)malloc(sizeof(TBTNode));
//		//t2->data = 'B';
//		//TBTNode * t3 = (TBTNode *)malloc(sizeof(TBTNode));
//		//t3->data = 'C';
//		//TBTNode * t4 = (TBTNode *)malloc(sizeof(TBTNode));
//		//t4->data = 'D';
//		//TBTNode * t5 = (TBTNode *)malloc(sizeof(TBTNode));
//		//t5->data = 'E';
//		//TBTNode * t6 = (TBTNode *)malloc(sizeof(TBTNode));
//		//t6->data = 'F';
//		//TBTNode * t7 = (TBTNode *)malloc(sizeof(TBTNode));
//		//t7->data = 'G';
//
//		//t1->lchild = t2;
//		//t1->rchild = t4;
//		//t2->lchild = t3;
//		//t2->rchild = t5;
//		//t3->lchild = NULL;
//		//t3->rchild = NULL;
//		//t5->lchild = NULL;
//		//t5->rchild = NULL;
//		//t4->lchild = NULL;
//		//t4->rchild = t6;
//		//t6->lchild = NULL;
//		//t6->rchild = t7;
//		//t7->lchild = NULL;
//		//t7->rchild = NULL;
//		////����߶�
//		//printf("%d", exchange(t1));
//	/*int a = 1, *p, **pp;
//	pp = &p;
//	p = &a;
//	a++;
//	printf("%d,%d,%d\n", a, *p, **pp);*/
//	/*for (int i = 0; i < 300; i++) {
//		total(i);
//	}*/
//	/*LinkList * t = (LinkList *)malloc(sizeof(LinkList));
//	LinkList * a = (LinkList *)malloc(sizeof(LinkList));
//	LinkList * b = (LinkList *)malloc(sizeof(LinkList));
//	LinkList * c = (LinkList *)malloc(sizeof(LinkList));
//	LinkList * d = (LinkList *)malloc(sizeof(LinkList));
//	LinkList * e = (LinkList *)malloc(sizeof(LinkList));
//	t->prior = NULL;
//	t->data = NULL;
//	a->prior = NULL;
//	b->prior = NULL;
//	c->prior = NULL;
//	d->prior = NULL;
//	e->prior = NULL;
//	a->data = 1;
//	b->data = 3;
//	c->data = 2;
//	d->data = 5;
//	e->data = 4;
//	a->next = b;
//	t->next = a;
//	a->next = b;
//	b->next = c;
//	c->next = d;
//	d->next = e;
//	insert(t);*/
//
//	TNode * a = (struct TNode *)malloc(sizeof(TNode));
//	a->data = 'a';
//	TNode * b = (struct TNode *)malloc(sizeof(TNode));
//	b->data = 'b';
//	TNode * c = (struct TNode *)malloc(sizeof(TNode));
//	c->data = 'c';
//	TNode * d = (struct TNode *)malloc(sizeof(TNode));
//	d->data = 'd';
//	TNode * e = (struct TNode *)malloc(sizeof(TNode));
//	e->data = 'e';
//	TNode * f = (struct TNode *)malloc(sizeof(TNode));
//	f->data = 'f';
//	TNode * g = (struct TNode *)malloc(sizeof(TNode));
//	g->data = 'g';
//	a->firstchild = b;
//	a->nextsibling = NULL;
//	b->firstchild = e;
//	b->nextsibling = c;
//	c->firstchild = NULL;
//	c->nextsibling = d;
//	d->firstchild = g;
//	d->nextsibling = NULL;
//	e->firstchild = NULL;
//	e->nextsibling = f;
//	f->nextsibling = NULL;
//	f->firstchild = NULL;
//	g->firstchild = NULL;
//	g->nextsibling = NULL;
//
//	//nodedepth(a);
//
//	//����Ҷ�ӽڵ�
//	printf("%d",calNum(a));
//	return 0;
//}


//
//	TBTNode * t1 = (TBTNode *)malloc(sizeof(TBTNode));
//	t1->data = 'A';
//	TBTNode * t2 = (TBTNode *)malloc(sizeof(TBTNode));
//	t2->data = 'B';
//	TBTNode * t3 = (TBTNode *)malloc(sizeof(TBTNode));
//	t3->data = 'C';
//	TBTNode * t4 = (TBTNode *)malloc(sizeof(TBTNode));
//	t4->data = 'D';
//	TBTNode * t5 = (TBTNode *)malloc(sizeof(TBTNode));
//	t5->data = 'E';
//	
//
//	t1->lchild = t2;
//	t1->ltag = 0;
//
//	t1->rchild = t5;
//	t1->rtag = 0;
//
//	t2->lchild = t3;
//	t2->ltag = 0;
//
//	t2->rchild = t4;
//	t2->rtag = 0;
//
//	t3->lchild = NULL;
//	t3->rchild = NULL;
//	
//	t4->lchild = NULL;
//	t4->rchild = NULL;
//
//	t5->lchild = NULL;
//	t5->rchild = NULL;
//	
//
//	//1.�������
//	//printInt(comp(p1));
//
//	//2.�������������
//	//printInt(getDepth(p1));
//
//	//3.�����������
//	//BTNode * q = NULL;
//	//search(p1, q, '+');
//
//	//4.����������ָ���ڵ��ֵ
//	//searchBykeyIndexPre(p1,9);
//
//	//5.����������ָ���ڵ��ֵ
//	//searchBykeyIndexCenter(p1,6);
//
//	//6.��α���
//	//level(p1);
//
//	//7.���ݲ�α�������
//	//printInt(maxNode(p1));
//
//	//8.����Ż��������������ǵݹ�ʵ�֣�����
//	//preOrderNonRecurision(p1);
//
//	//9.����Ż��������������ǵݹ�ʵ�֣�����
//	//inOrderNonRecurision(p1);
//
//	//10.����Ż��������������ǵݹ�ʵ�֣�����
//	//postOrderNonRecurision(p1);
//
//	//11.����������
//	//creatInThread(t1);
//	//visit(First(t1));
//
//	//12.��������������ͨ��first������next����
//	//creatInThread(t1);
//	//InOder(t1);
//
//	//13.������������������
//	//TBTNode *pre = NULL;
//	//preThread(t1, pre);
//	//preOrder(t1);
//	return 0;
//}
