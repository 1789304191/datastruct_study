#include <iostream>
#include "BTree.h"
#include "print.h"

int main() {
	BTNode * p1 =(BTNode *)malloc(sizeof(BTNode));
	p1->c = '*';
	BTNode * p2 = (BTNode *)malloc(sizeof(BTNode));
	p2->c = '-';
	BTNode * p3 = (BTNode *)malloc(sizeof(BTNode));
	p3->c = '/';
	BTNode * p4 = (BTNode *)malloc(sizeof(BTNode));
	p4->c = 'a';
	BTNode * p5 = (BTNode *)malloc(sizeof(BTNode));
	p5->c = '+';
	BTNode * p6 = (BTNode *)malloc(sizeof(BTNode));
	p6->c = 'e';
	BTNode * p7 = (BTNode *)malloc(sizeof(BTNode));
	p7->c = 'e';
	BTNode * p8 = (BTNode *)malloc(sizeof(BTNode));
	p8->c = 'b';
	BTNode * p9 = (BTNode *)malloc(sizeof(BTNode));
	p9->c = 'c';

	p1->lchild = p2;
	p1->rchild = p3;

	p2->lchild = p4;
	p2->rchild = p5;
	p4->lchild = NULL;
	p4->rchild = NULL;

	p3->lchild = p6;
	p3->rchild = p7;

	p6->lchild = NULL;
	p6->rchild = NULL;
	p7->lchild = NULL;
	p7->rchild = NULL;

	p5->lchild = p8;
	p5->rchild = p9;

	p8->lchild = NULL;
	p8->rchild = NULL;
	p9->lchild = NULL;
	p9->rchild = NULL;


	TBTNode * t1 = (TBTNode *)malloc(sizeof(TBTNode));
	t1->data = 'A';
	TBTNode * t2 = (TBTNode *)malloc(sizeof(TBTNode));
	t2->data = 'B';
	TBTNode * t3 = (TBTNode *)malloc(sizeof(TBTNode));
	t3->data = 'C';
	TBTNode * t4 = (TBTNode *)malloc(sizeof(TBTNode));
	t4->data = 'D';
	TBTNode * t5 = (TBTNode *)malloc(sizeof(TBTNode));
	t5->data = 'E';
	

	t1->lchild = t2;
	t1->ltag = 0;

	t1->rchild = t5;
	t1->rtag = 0;

	t2->lchild = t3;
	t2->ltag = 0;

	t2->rchild = t4;
	t2->rtag = 0;

	t3->lchild = NULL;
	t3->rchild = NULL;
	
	t4->lchild = NULL;
	t4->rchild = NULL;

	t5->lchild = NULL;
	t5->rchild = NULL;
	

	//1.�������
	//printInt(comp(p1));

	//2.�������������
	//printInt(getDepth(p1));

	//3.�����������
	//BTNode * q = NULL;
	//search(p1, q, '+');

	//4.����������ָ���ڵ��ֵ
	//searchBykeyIndexPre(p1,9);

	//5.����������ָ���ڵ��ֵ
	//searchBykeyIndexCenter(p1,6);

	//6.��α���
	//level(p1);

	//7.���ݲ�α��������
	//printInt(maxNode(p1));

	//8.����Ż��������������ǵݹ�ʵ�֣�����
	//preOrderNonRecurision(p1);

	//9.����Ż��������������ǵݹ�ʵ�֣�����
	//inOrderNonRecurision(p1);

	//10.����Ż��������������ǵݹ�ʵ�֣�����
	//postOrderNonRecurision(p1);

	//11.����������
	//creatInThread(t1);
	//visit(First(t1));

	//12.��������������ͨ��first������next����
	//creatInThread(t1);
	//InOder(t1);

	//13.������������������
	//TBTNode *pre = NULL;
	//preThread(t1, pre);
	//preOrder(t1);
	return 0;
}