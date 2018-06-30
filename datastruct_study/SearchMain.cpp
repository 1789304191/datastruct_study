#include <iostream>
#include "search.h"
#include "print.h"
#include "SearchTestCase.h"

int main() {
//	
//	int array[6] = { 2,1,0,3,4,5 };
//
//	//1.折半查找法
//	//printInt(Bsearch(array, 0, 4, 3));
//
//	//2.二叉排序树
//	//printInt(BSTSearch(initBTNode(), 3)->key);
//
//	//3.二叉排序树的插入算法
//	//BTNode * bt = initBTNode();
//	//printInt(BSTInsert(bt, 6));
//
//	//4.二叉树的构造
//	//BTNode * bt = NULL;
//	//CreateBST(bt, array, 6);
//
//	//5.判断一个二叉树是否是二叉排序树
//	printInt(judBST(initBTNode()));
//
	//6.在平衡二叉树中每个节点添加一个lleft的值域，
	//存储已该节点为根的左子树的个数加1，求第k个节点的位置
	//LBTNode * lbt = initLBTNode();
	//printInt(searchByKey(lbt, 4)->key); 

	//7.在二叉排序树中插入一个节点，如果已存在相同关键字结点
	//那么count域的值加1
	//BTNodeWithCount * bt = initBTNodeWithCount();
	//printInt(insertBTNodeWithCount(bt, 5));

	//8.判断是否是二叉排序树的查找序列
	Sequence * s = (Sequence *)malloc(sizeof(Sequence));
	Sequence * s1 = (Sequence *)malloc(sizeof(Sequence));
	Sequence * s2 = (Sequence *)malloc(sizeof(Sequence));
	s->elem[0] = 20;
	s->elem[1] = 30;
	s->elem[2] = 90;
	s->elem[3] = 80;
	s->elem[4] = 40;
	s->elem[5] = 50;
	s->elem[6] = 70;
	s->elem[7] = 60;
	s->len = 8;
	printInt(isSearch(*s, *s1, *s2, 60));
}