#include <iostream>
//#include "childsiblings.h"


typedef struct TNode {
	char data;
	struct TNode * firstchild, *nextsibling;
}TNode;

typedef struct LTNode {

	//当前结点
	TNode * node;
	//层号
	int level;

}LTNode;

/* 找出叶子节点 */
int countLeaves(TNode * root) {

	if (root == NULL) {
		return 0;
	}
	//此时说明是叶子节点
	if (root->firstchild == NULL) {
		printf("叶子节点为：%c\n", root->data);
		return 1 + countLeaves(root->nextsibling);
	}
	else {
		return countLeaves(root->firstchild) + countLeaves(root->nextsibling);
	}
}



//输出叶子节点和所在层数
void seekLeaves(TNode * root) {

	if (root == NULL) {
		return;
	}
	if (root->firstchild == NULL) {
		printf("叶子节点为：%c\n", root->data);
		seekLeaves(root->nextsibling);
	}
	else {
		seekLeaves(root->firstchild);
		seekLeaves(root->nextsibling);
	}

}


//计算高度
int height(TNode * root) {
	
	int fh, hs;

	if (root == NULL) {
		return 0;
	}
	//树不空计算孩子节点高度
	fh = height(root->firstchild);
	//计算兄弟节点的高度
	hs = height(root->nextsibling);
	return (fh + 1) > hs ? fh + 1 : hs;
}

//输出并统计指定层的结点数(二叉树)
int printNodeAtLevel(TNode * root, int level) {

	if (!root || level <0)
		return 0;
	//如果第一层则返回1因为是根结点
	if (1 == level) {
		printf("%c ", root->data);
		return 1;

	}
	//然后分别计算其他层的结点数
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

	//最高成绩
	float max = NULL;
	//最低成绩
	float min = NULL;
	//平均成绩
	float average = 0;
	//人数
	int num = 0;

	if (grade == NULL) {
		return;
	}
	//因为带头节点
	while (grade->next != NULL)
	{
		num++;
		//平均成绩
		average += grade->next->score;
		//最高成绩
		if (grade->next->score > max || max == NULL) {
			max = grade->next->score;
		}
		//最低成绩
		if (grade->next->score < min || min == NULL) {
			min = grade->next->score;
		}
		grade = grade->next;
	}
	printf("平均成绩：%.2f\n", average / num);
	printf("最高成绩：%.2f\n", max);
	printf("最低成绩：%.2f\n", min);
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
	//分别计算左子树和右子数的高度最后高的加1
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

	//头节点
	Node2017 * head = node2017;
	//第一个节点
	Node2017 * p = head->next;

	//需要删除的结点
	Node2017 * q = NULL;

	while (p != NULL) {
		if (p->data < -1) {
			head->next = p->next;
			q = p;
			//将p指向下一个结点然后删除q
			p = p->next;
			free(q);
		}
		else
		{
			//作用是循环每一个节点
			p = p->next;
		}
		//记住要判断大小的前一个节点以便于删除
		head = head->next;
		
		
	}
	return node2017;
}

int num = 1;
void nodedepth(TNode * tree) {

	//如果没有孩子结点就是叶子节点
	if (!tree->firstchild) {
		printf("结点值：%c,结点层数：%d\n", tree->data, num);
	}
	else
	{
		//取孩子节点      相当于层次遍历 或者说是广度优先遍历   //取兄弟节点
		for (tree = tree->firstchild; tree; tree = tree->nextsibling) {
			//到下一层加一
			num++;
			nodedepth(tree);
			//回上一次减一
			num--;
		}
	}
}

/*****************************2016******************************/
////计算阶乘
int factorial(int n) {

	int sum = n;

	while (n > 1) {

		sum = sum * (n - 1);
		n--;
	}
	return sum;
}
//一个三位数abc等于其每位数字的阶乘之和，即abc=a!+b!+c! 打印出这样的数
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

//直接插入法（从头比较开始插入2016倒数第二题）
void insert(LinkList *head) {

	LinkList *p, *s, *q;
	p = head->next;//p指向待插入结点
	while (p != NULL) {
		s = head;//s指向q结点的前驱结点
		q = head->prior;//q指向由prior域构成的链表中待比较的结点，即头结点之后的第一个结点
		while ((q != NULL) && (p->data > q->data)) {
			s = q;//记录前一个结点
			q = q->prior;//因为当前q<p所以将q后移(头插法从大到小)
		}
		s->prior = p;//第一趟直接插入待插入的结点p
		p->prior = q;//将p插入待比较结点之前（因为头插法p<q）
		p = p->next;
	}

}

//计算每一层节点的个数(2016)
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

//删除某一个等于指定值的结点
void remove(Node2015 * first, int n) {

	Node2015 * head = first;

	Node2015 * p = first->next;

	Node2015 * q = NULL;

	while (p != NULL) {

		if (p->data == n) {
			//如果当前结点使要删除的结点，那么head不用移动
			//p往后移
			head->next = p->next;
			q = p;
			p = p->next;
			free(q);
		}else{
			//如果当前结点不是要删除的结点，则head往后移，p也往后移
			//循环每一个结点
			p = p->next;
			//记录p的前一个结点
			head = head->next;
		}
	}
	return;
}


void distinct(Node2015 * first) {

	Node2015 * head = first->next;

	Node2015 * p0 = first->next;

	//表示已经去重完毕
	if (p0 == NULL) {
		return;
	}

	//根据第一个值查找后面的值是否有重复的，有重复的则删除
	Node2015 * p = head->next;

	Node2015 * q;

	//第一个值
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
		printf("%c的度是:%d\n", tnode->data, sum);
	}
	else {
		printf("%c的度是:%d\n", tnode->data, sum);
	}
	countDu(tnode->firstchild);
	countDu(tnode->nextsibling);
}

int main() {

	//2018
	/*1.	试编写一个函数 sum( n ) 计算满足下式的最大 m： 
			1 * 2 + 2 * 3 + 3 * 4 + ... + (m - 1)*m <= n*/
	//printf("m=%d\n", sum(2));
	/*2.	有一个带头结点的链表存储学生成绩 score，试编写函数计算链表所有记
		录中的最高成绩 max、最低成绩 min 和平均成绩 aver，链表的存储结构为：*/

	//grade(initGrade());
	/*3.    编写函数 exchange() 计算二叉树的高度并将其每一个结点的左孩子与右
		孩子对调，设二叉树采用二叉链表存储*/
	//printf("高度为：%d", exchange(initBTNode()));

	//2017
	/*1．编写一个函数 sum()计算：
		S = 1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) 
		+ ... + (1 + 2 + 3 + ... + 100)*/
	//sum2017();

	/*2. 编写函数 delneg 将链表中 data 域值小于 1 的
		所有结点删除。*/
	//delneg(initNode2017());

	/*3. 编写函数 nodedepth()计算并输出树中每个叶子结点的 data 域值与所在的层数（根结点
		所在的层数为 1）*/
	//nodedepth(inita());

	//2016
	//1. 一个三位数abc等于其每位数字的阶乘之和，即abc=a!+b!+c! 打印出这样的数
	//total(145);
	//2. 头插法将链表排序insert（）
	//3. 孩子兄弟表示法计算第i层结点的个数
	//printf("该层结点数:%d\n", countlayer(inita(), 3));

	//2015
	/*
	  1.给定一个m,编写一个函数求满足1*2+2*(3+4)+3*(4+5+6)+..+
	  n*((n+1)+(n+2)+...+(n+n))>=m的最小n
	  minN(2)
	*/
	/*
	  2.试设计一个算法，在带头结点的单链表中去重，即使data域值重复
	  的结点只留下一个，其他的都删除。表头指针为first.
	  Node2015 * a = init2015();
	  distinct(a);
	*/

	/*
	  3.孩子兄弟表示法计算每一个结点的度
	*/
	countDu(inita());
	
	return 0;
}