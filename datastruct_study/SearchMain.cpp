#include <iostream>
#include "search.h"
#include "print.h"
#include "SearchTestCase.h"

int main() {
	
	int array[6] = { 2,1,0,3,4,5 };

	//1.折半查找法
	//printInt(Bsearch(array, 0, 4, 3));

	//2.二叉排序树
	//printInt(BSTSearch(initBTNode(), 3)->key);

	//3.二叉排序树的插入算法
	//BTNode * bt = initBTNode();
	//printInt(BSTInsert(bt, 6));

	//4.二叉树的构造
	//BTNode * bt = NULL;
	//CreateBST(bt, array, 6);

	//5.判断一个二叉树是否是二叉排序树
	printInt(judBST(initBTNode()));

}