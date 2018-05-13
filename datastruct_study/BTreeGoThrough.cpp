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

	printInt(comp(p1));
}