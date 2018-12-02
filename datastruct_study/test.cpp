#include <iostream>
//#include "childsiblings.h"


typedef struct TNode {
	char data;
	struct TNode * firstchild, *nextsibling;
}TNode;

typedef struct LTNode {

	//��ǰ���
	TNode * node;
	//���
	int level;

}LTNode;

/* �ҳ�Ҷ�ӽڵ� */
int countLeaves(TNode * root) {

	if (root == NULL) {
		return 0;
	}
	//��ʱ˵����Ҷ�ӽڵ�
	if (root->firstchild == NULL) {
		printf("Ҷ�ӽڵ�Ϊ��%c\n", root->data);
		return 1 + countLeaves(root->nextsibling);
	}
	else {
		return countLeaves(root->firstchild) + countLeaves(root->nextsibling);
	}
}



//���Ҷ�ӽڵ�����ڲ���
void seekLeaves(TNode * root) {

	if (root == NULL) {
		return;
	}
	if (root->firstchild == NULL) {
		printf("Ҷ�ӽڵ�Ϊ��%c\n", root->data);
		seekLeaves(root->nextsibling);
	}
	else {
		seekLeaves(root->firstchild);
		seekLeaves(root->nextsibling);
	}

}


//����߶�
int height(TNode * root) {
	
	int fh, hs;

	if (root == NULL) {
		return 0;
	}
	//�����ռ��㺢�ӽڵ�߶�
	fh = height(root->firstchild);
	//�����ֵܽڵ�ĸ߶�
	hs = height(root->nextsibling);
	return (fh + 1) > hs ? fh + 1 : hs;
}

//�����ͳ��ָ����Ľ����(������)
int printNodeAtLevel(TNode * root, int level) {

	if (!root || level <0)
		return 0;
	//�����һ���򷵻�1��Ϊ�Ǹ����
	if (1 == level) {
		printf("%c ", root->data);
		return 1;

	}
	//Ȼ��ֱ����������Ľ����
	return printNodeAtLevel(root->firstchild, level - 1) +
		printNodeAtLevel(root->nextsibling, level - 1);

}

TNode * inita() {
	TNode * a = (TNode *)malloc(sizeof(TNode));
	a->data = 'a';
	TNode * b = (TNode *)malloc(sizeof(TNode));
	b->data = 'b';
	TNode * c = (TNode *)malloc(sizeof(TNode));
	c->data = 'c';
	TNode * d = (TNode *)malloc(sizeof(TNode));
	d->data = 'd';
	TNode * e = (TNode *)malloc(sizeof(TNode));
	e->data = 'e';
	TNode * f = (TNode *)malloc(sizeof(TNode));
	f->data = 'f';
	TNode * g = (TNode *)malloc(sizeof(TNode));
	g->data = 'g';
	TNode * h = (TNode *)malloc(sizeof(TNode));
	h->data = 'h';
	a->firstchild = b;
	a->nextsibling = NULL;
	b->firstchild = e;
	b->nextsibling = c;
	c->firstchild = h;
	c->nextsibling = d;
	d->firstchild = g;
	d->nextsibling = NULL;
	e->firstchild = NULL;
	e->nextsibling = f;
	f->firstchild = NULL;
	f->nextsibling = NULL;
	g->firstchild = NULL;
	g->nextsibling = NULL;
	h->firstchild = NULL;
	h->nextsibling = NULL;
	return a;
}

TNode * inita1() {

	TNode * a1 = (TNode *)malloc(sizeof(TNode));
	a1->data = 'a';
	TNode * b1 = (TNode *)malloc(sizeof(TNode));
	b1->data = 'b';
	TNode * c1 = (TNode *)malloc(sizeof(TNode));
	c1->data = 'c';
	TNode * d1 = (TNode *)malloc(sizeof(TNode));
	d1->data = 'd';
	TNode * e1 = (TNode *)malloc(sizeof(TNode));
	e1->data = 'e';
	TNode * f1 = (TNode *)malloc(sizeof(TNode));
	f1->data = 'f';
	TNode * g1 = (TNode *)malloc(sizeof(TNode));
	g1->data = 'g';
	a1->firstchild = b1;
	a1->nextsibling = c1;
	c1->firstchild = f1;
	c1->nextsibling = g1;
	b1->firstchild = d1;
	b1->nextsibling = e1;
	d1->firstchild = NULL;
	d1->nextsibling = NULL;
	e1->firstchild = NULL;
	e1->nextsibling = NULL;
	return a1;
}

/**********************2018**********************/
int sum(int n) {
	
	int i = 1;
	int total = 0;
	while (total <= n) {
		total += i * (i + 1);
		i++;
	}
	return i - 2;
}

typedef struct GradeNode {
	char name;
	float score;
	struct GradeNode *next;
} GradeNode;

GradeNode * initGrade() {

	GradeNode * grade0 = (GradeNode *)malloc(sizeof(GradeNode));
	GradeNode * grade1 = (GradeNode *)malloc(sizeof(GradeNode));
	GradeNode * grade2 = (GradeNode *)malloc(sizeof(GradeNode));
	GradeNode * grade3 = (GradeNode *)malloc(sizeof(GradeNode));
	grade0->next = grade1;
	grade0->name = NULL;
	grade0->score = NULL;
	grade1->name = 'A';
	grade1->score = 1;
	grade2->name = 'B';
	grade2->score = 2;
	grade3->name = 'C';
	grade3->score = 3;
	grade1->next = grade2;
	grade2->next = grade3;
	grade3->next = NULL;
	return grade0;
}

void grade(GradeNode * grade) {

	//��߳ɼ�
	float max = NULL;
	//��ͳɼ�
	float min = NULL;
	//ƽ���ɼ�
	float average = 0;
	//����
	int num = 0;

	if (grade == NULL) {
		return;
	}
	//��Ϊ��ͷ�ڵ�
	while (grade->next != NULL)
	{
		num++;
		//ƽ���ɼ�
		average += grade->next->score;
		//��߳ɼ�
		if (grade->next->score > max || max == NULL) {
			max = grade->next->score;
		}
		//��ͳɼ�
		if (grade->next->score < min || min == NULL) {
			min = grade->next->score;
		}
		grade = grade->next;
	}
	printf("ƽ���ɼ���%.2f\n", average / num);
	printf("��߳ɼ���%.2f\n", max);
	printf("��ͳɼ���%.2f\n", min);
}


typedef struct ExchangeNode {
	char data;
	struct ExchangeNode *lchild, *rchild;
}ExchangeNode;

int exchange(ExchangeNode * t) {

	int ldepth = 0;
	int rdepth = 0;
	if (t->lchild == NULL && t->rchild == NULL)
		return 1;
	else {
		ExchangeNode * temp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = temp;
	}
	//�ֱ�������������������ĸ߶����ߵļ�1
	if (t->lchild)
		ldepth = exchange(t->lchild);
	if (t->rchild) {
		rdepth = exchange(t->rchild);
	}
	return (ldepth > rdepth ? ldepth : rdepth) + 1;
}

ExchangeNode * initBTNode() {
	ExchangeNode * a = (ExchangeNode *)malloc(sizeof(ExchangeNode));
	ExchangeNode * b = (ExchangeNode *)malloc(sizeof(ExchangeNode));
	ExchangeNode * c = (ExchangeNode *)malloc(sizeof(ExchangeNode));
	ExchangeNode * d = (ExchangeNode *)malloc(sizeof(ExchangeNode));
	a->data = 'a';
	b->data = 'b';
	c->data = 'c';
	a->lchild = b;
	a->rchild = d;
	b->lchild = c;
	b->rchild = NULL;
	c->lchild = NULL;
	c->rchild = NULL;
	d->lchild = NULL;
	d->rchild = NULL;
	return a;
}

/****************************2017******************************/
void sum2017() {

	int i = 1, sum = 0, t = 0;
	while (i <= 100) {
		t = t + i;
		sum = sum + t;
		i++;
	}
	printf("sum=%d\n", sum);
}

typedef struct Node2017 {
	int data;
	struct Node2017 *next;
} Node2017;

Node2017 * initNode2017() {

	Node2017 * a0 = (Node2017 *)malloc(sizeof(Node2017));
	Node2017 * a = (Node2017 *)malloc(sizeof(Node2017));
	Node2017 * b = (Node2017 *)malloc(sizeof(Node2017));
	Node2017 * c = (Node2017 *)malloc(sizeof(Node2017));
	a0->data = NULL;
	a0->next = a;
	a->data = -1;
	b->data = -2;
	c->data = 1;
	a->next = b;
	b->next = c;
	c->next = NULL;
	return a0;
}

Node2017 * delneg(Node2017 * node2017) {

	//ͷ�ڵ�
	Node2017 * head = node2017;
	//��һ���ڵ�
	Node2017 * p = head->next;

	//��Ҫɾ���Ľ��
	Node2017 * q = NULL;

	while (p != NULL) {
		if (p->data < -1) {
			head->next = p->next;
			q = p;
			//��pָ����һ�����Ȼ��ɾ��q
			p = p->next;
			free(q);
		}
		else
		{
			//������ѭ��ÿһ���ڵ�
			p = p->next;
		}
		//��סҪ�жϴ�С��ǰһ���ڵ��Ա���ɾ��
		head = head->next;
		
		
	}
	return node2017;
}

int num = 1;
void nodedepth(TNode * tree) {

	//���û�к��ӽ�����Ҷ�ӽڵ�
	if (!tree->firstchild) {
		printf("���ֵ��%c,��������%d\n", tree->data, num);
	}
	else
	{
		//ȡ���ӽڵ�      �൱�ڲ�α��� ����˵�ǹ�����ȱ���   //ȡ�ֵܽڵ�
		for (tree = tree->firstchild; tree; tree = tree->nextsibling) {
			//����һ���һ
			num++;
			nodedepth(tree);
			//����һ�μ�һ
			num--;
		}
	}
}

/*****************************2016******************************/
////����׳�
int factorial(int n) {

	int sum = n;

	while (n > 1) {

		sum = sum * (n - 1);
		n--;
	}
	return sum;
}
//һ����λ��abc������ÿλ���ֵĽ׳�֮�ͣ���abc=a!+b!+c! ��ӡ����������
int total(int n) {
	
	int a = n / 100;
	int b = (n - a * 100) / 10;
	int c = n - a * 100 - b * 10;
	int sum = 0;
	sum += factorial(a);
	sum += factorial(b);
	sum += factorial(c);
	if (sum == n) {
		printf("%d\n", n);
	}
	return 0;
}

typedef struct node {

	int data;
	struct node *next, *prior;
}LinkList;

//ֱ�Ӳ��뷨����ͷ�ȽϿ�ʼ����2016�����ڶ��⣩
void insert(LinkList *head) {

	LinkList *p, *s, *q;
	p = head->next;//pָ���������
	while (p != NULL) {
		s = head;//sָ��q����ǰ�����
		q = head->prior;//qָ����prior�򹹳ɵ������д��ȽϵĽ�㣬��ͷ���֮��ĵ�һ�����
		while ((q != NULL) && (p->data > q->data)) {
			s = q;//��¼ǰһ�����
			q = q->prior;//��Ϊ��ǰq<p���Խ�q����(ͷ�巨�Ӵ�С)
		}
		s->prior = p;//��һ��ֱ�Ӳ��������Ľ��p
		p->prior = q;//��p������ȽϽ��֮ǰ����Ϊͷ�巨p<q��
		p = p->next;
	}

}

//����ÿһ��ڵ�ĸ���(2016)
int countlayer(TNode * root, int level) {

	if (root == NULL || level < 0) {
		return 0;
	}
	if (1 == level) {
		printf("%c ", root->data);
		return 1;
	}
	int count = countlayer(root->firstchild, level - 1);
	if (root->firstchild != NULL) {
		root = root->firstchild;
		while (root->nextsibling != NULL) {
			count += countlayer(root->nextsibling, level - 1);
			root = root->nextsibling;
		}
	}
	return count;
}


/***********************************2015***********************************/
void minN(int m) {
	int n = 1;
	int sum = 0;
	while (sum < m) {
		for (int i = 1; i <=n; i++) {
			sum += n * (n + i);
			if (sum >= m) {
				printf("%d", n);
				break;
			}
		}
		n++;
	}
}

typedef struct Node2015 {
	int data;
	struct Node2015 *next;
}Node2015,*List;

//ɾ��ĳһ������ָ��ֵ�Ľ��
void remove(Node2015 * first, int n) {

	Node2015 * head = first;

	Node2015 * p = first->next;

	Node2015 * q = NULL;

	while (p != NULL) {

		if (p->data == n) {
			//�����ǰ���ʹҪɾ���Ľ�㣬��ôhead�����ƶ�
			//p������
			head->next = p->next;
			q = p;
			p = p->next;
			free(q);
		}else{
			//�����ǰ��㲻��Ҫɾ���Ľ�㣬��head�����ƣ�pҲ������
			//ѭ��ÿһ�����
			p = p->next;
			//��¼p��ǰһ�����
			head = head->next;
		}
	}
	return;
}


void distinct(Node2015 * first) {

	Node2015 * head = first->next;

	Node2015 * p0 = first->next;

	//��ʾ�Ѿ�ȥ�����
	if (p0 == NULL) {
		return;
	}

	//���ݵ�һ��ֵ���Һ����ֵ�Ƿ����ظ��ģ����ظ�����ɾ��
	Node2015 * p = head->next;

	Node2015 * q;

	//��һ��ֵ
	int n = head->data;

	while (p!= NULL) {
		
		if (p->data == n) {
			head->next = p->next;
			q = p;
			p = p->next;
			free(p);
		}
		else {
			p = p->next;
			head = head->next;
		}
	}
	distinct(p0);
}

Node2015 * init2015() {

	Node2015 * a0 = (Node2015 *)malloc(sizeof(Node2015));
	Node2015 * a = (Node2015 *)malloc(sizeof(Node2015));
	Node2015 * b = (Node2015 *)malloc(sizeof(Node2015));
	Node2015 * c = (Node2015 *)malloc(sizeof(Node2015));
	Node2015 * d = (Node2015 *)malloc(sizeof(Node2015));
	a0->next = a;
	a0->data = NULL;
	a->data = 5;
	b->data = 4;
	c->data = 4;
	d->data = 5;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	return a0;
}

void countDu(TNode * tnode) {
	
	int sum = 0;

	if (tnode == NULL) {
		return;
	}
	if (tnode->firstchild != NULL) {
		
		sum+=1;

		TNode * a = tnode->firstchild;

		while (a->nextsibling != NULL) {
			sum++;
			a = a->nextsibling;
		}
		printf("%c�Ķ���:%d\n", tnode->data, sum);
	}
	else {
		printf("%c�Ķ���:%d\n", tnode->data, sum);
	}
	countDu(tnode->firstchild);
	countDu(tnode->nextsibling);
}

int main() {

	//2018
	/*1.	�Ա�дһ������ sum( n ) ����������ʽ����� m�� 
			1 * 2 + 2 * 3 + 3 * 4 + ... + (m - 1)*m <= n*/
	//printf("m=%d\n", sum(2));
	/*2.	��һ����ͷ��������洢ѧ���ɼ� score���Ա�д���������������м�
		¼�е���߳ɼ� max����ͳɼ� min ��ƽ���ɼ� aver������Ĵ洢�ṹΪ��*/

	//grade(initGrade());
	/*3.    ��д���� exchange() ����������ĸ߶Ȳ�����ÿһ��������������
		���ӶԵ�������������ö�������洢*/
	//printf("�߶�Ϊ��%d", exchange(initBTNode()));

	//2017
	/*1����дһ������ sum()���㣺
		S = 1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) 
		+ ... + (1 + 2 + 3 + ... + 100)*/
	//sum2017();

	/*2. ��д���� delneg �������� data ��ֵС�� 1 ��
		���н��ɾ����*/
	//delneg(initNode2017());

	/*3. ��д���� nodedepth()���㲢�������ÿ��Ҷ�ӽ��� data ��ֵ�����ڵĲ����������
		���ڵĲ���Ϊ 1��*/
	//nodedepth(inita());

	//2016
	//1. һ����λ��abc������ÿλ���ֵĽ׳�֮�ͣ���abc=a!+b!+c! ��ӡ����������
	//total(145);
	//2. ͷ�巨����������insert����
	//3. �����ֵܱ�ʾ�������i����ĸ���
	//printf("�ò�����:%d\n", countlayer(inita(), 3));

	//2015
	/*
	  1.����һ��m,��дһ������������1*2+2*(3+4)+3*(4+5+6)+..+
	  n*((n+1)+(n+2)+...+(n+n))>=m����Сn
	  minN(2)
	*/
	/*
	  2.�����һ���㷨���ڴ�ͷ���ĵ�������ȥ�أ���ʹdata��ֵ�ظ�
	  �Ľ��ֻ����һ���������Ķ�ɾ������ͷָ��Ϊfirst.
	  Node2015 * a = init2015();
	  distinct(a);
	*/

	/*
	  3.�����ֵܱ�ʾ������ÿһ�����Ķ�
	*/
	countDu(inita());
	
	return 0;
}