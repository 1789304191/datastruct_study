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