#include <iostream>
#include "SearchTestCase.h"

//初始化一个二叉排序树
BTNode * initBTNode() {
	
	BTNode * bt0 = (BTNode *)malloc(sizeof(BTNode));
	bt0->key = 0;
	bt0->lchild = NULL;
	bt0->rchild = NULL;

	BTNode * bt1 = (BTNode *)malloc(sizeof(BTNode));
	bt1->key = 1;
	bt1->lchild = bt0;
	bt1->rchild = NULL;

	BTNode * bt5 = (BTNode *)malloc(sizeof(BTNode));
	bt5->key = 5;
	bt5->lchild = NULL;
	bt5->rchild = NULL;

	BTNode * bt3 = (BTNode *)malloc(sizeof(BTNode));
	bt3->key = 3;
	bt3->lchild = NULL;
	bt3->rchild = NULL;

	BTNode * bt4 = (BTNode *)malloc(sizeof(BTNode));
	bt4->key = 4;
	bt4->lchild = bt3;
	bt4->rchild = bt5;

	

	BTNode * bt2 = (BTNode *)malloc(sizeof(BTNode));
	bt2->key = 2;
	bt2->lchild = bt1;
	bt2->rchild = bt4;
	
	return bt2;
}


//初始化一个带lsize值域的平衡二叉树
LBTNode * initLBTNode() {

	LBTNode * A = (LBTNode *)malloc(sizeof(LBTNode));
	LBTNode * B = (LBTNode *)malloc(sizeof(LBTNode));
	LBTNode * C = (LBTNode *)malloc(sizeof(LBTNode));
	LBTNode * D = (LBTNode *)malloc(sizeof(LBTNode));

	A->key = 1;
	A->lchild = NULL;
	A->rchild = NULL;
	A->lsize = 1;

	D->key = 4;
	D->lchild = NULL;
	D->rchild = NULL;
	D->lsize = 1;

	C->key = 3;
	C->lchild = NULL;
	C->rchild = D;
	C->lsize = 1;

	B->key = 2;
	B->lchild = A;
	B->rchild = C;
	B->lsize = 2;

	return B;

}


//初始化一个带统计相同关键字值节点个数的count
BTNodeWithCount * initBTNodeWithCount() {

	BTNodeWithCount * A = (BTNodeWithCount *)malloc(sizeof(BTNodeWithCount));
	BTNodeWithCount * B = (BTNodeWithCount *)malloc(sizeof(BTNodeWithCount));
	BTNodeWithCount * C = (BTNodeWithCount *)malloc(sizeof(BTNodeWithCount));
	BTNodeWithCount * D = (BTNodeWithCount *)malloc(sizeof(BTNodeWithCount));

	A->key = 1;
	A->lchild = NULL;
	A->rchild = NULL;
	A->count= 1;

	D->key = 4;
	D->lchild = NULL;
	D->rchild = NULL;
	D->count = 1;

	C->key = 3;
	C->lchild = NULL;
	C->rchild = D;
	C->count = 1;

	B->key = 2;
	B->lchild = A;
	B->rchild = C;
	B->count = 1;

	return B;

}