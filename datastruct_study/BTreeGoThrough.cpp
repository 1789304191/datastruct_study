#include <iostream>
#include "BTree.h"
#include "print.h"

//typedef struct node {
//
//	int data;
//	struct node *next, *prior;
//}LinkList;
//
//孩子兄弟表示法
typedef struct tnode {
	char data;
	struct tnode * firstchild, *nextsibling;
}tnode;

////直接插入法（从头比较开始插入2016倒数第二题）
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
////计算阶乘
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
////一个三位数abc等于其每位数字的阶乘之和，即abc=a!+b!+c! 打印出这样的数
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
//（2018最后一题）
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
//int count = 1;(2017最后一题)
//void nodedepth(TNode * tree) {
//
//	//如果没有孩子结点就是叶子节点
//	if (!tree->firstchild) {
//		printf("结点值：%c,结点层数：%d\n", tree->data, count);
//	}
//	else
//	{
//		//取孩子节点      相当于层次遍历 或者说是广度优先遍历   //取兄弟节点
//		for (tree = tree->firstchild; tree; tree = tree->nextsibling) {
//			//到下一层加一
//			count++;
//			nodedepth(tree);
//			//回上一次减一
//			count--;
//		}
//	}
//}
//
////计算叶子节点的个数
//int calNum(TNode * tree) {
//	
//	//如果没有孩子结点就是叶子节点
//	if (!tree->firstchild) {
//		return 1;
//	}
//	else
//	{
//		count = 0;
//		//相当于层次遍历 或者说是广度优先遍历
//		for (tree = tree->firstchild; tree; tree = tree->nextsibling) {
//			count += calNum(tree);
//			return count;//各子树叶节点之和
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
//		////计算高度
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
//	//计算叶子节点
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
//	//1.后序遍历
//	//printInt(comp(p1));
//
//	//2.后续遍历求深度
//	//printInt(getDepth(p1));
//
//	//3.先序遍历查找
//	//BTNode * q = NULL;
//	//search(p1, q, '+');
//
//	//4.先序遍历输出指定节点的值
//	//searchBykeyIndexPre(p1,9);
//
//	//5.中序遍历输出指定节点的值
//	//searchBykeyIndexCenter(p1,6);
//
//	//6.层次遍历
//	//level(p1);
//
//	//7.根据层次遍历求宽度
//	//printInt(maxNode(p1));
//
//	//8.深度优化二叉树遍历，非递归实现，先序
//	//preOrderNonRecurision(p1);
//
//	//9.深度优化二叉树遍历，非递归实现，中序
//	//inOrderNonRecurision(p1);
//
//	//10.深度优化二叉树遍历，非递归实现，后续
//	//postOrderNonRecurision(p1);
//
//	//11.线索二叉树
//	//creatInThread(t1);
//	//visit(First(t1));
//
//	//12.遍历线索二叉树通过first函数和next函数
//	//creatInThread(t1);
//	//InOder(t1);
//
//	//13.遍历先序线索二叉树
//	//TBTNode *pre = NULL;
//	//preThread(t1, pre);
//	//preOrder(t1);
//	return 0;
//}
