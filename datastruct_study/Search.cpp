#include <iostream>
#include "search.h"

//顺序查找法
int search(int a[], int n, int k) {
	
	int i;

	for (i = 1; i <= n; i++) {
	
		if (a[i] == k) {
			
			return i;
		}
	}

	return 0;

}


//折半查找法
int Bsearch(int R[], int low, int high, int k) {

	int mid;

	//当子表长度大于等于1是进行循环
	while (low <= high) {
	
		//取当前表的中间位置
		mid = (low + high) / 2;
	
		//找到后返回元素的位置
		if (R[mid] == k) {
			return mid;
		}
		else if(R[mid]>k)
		{
			//说明需要在R[low.....,mid-1]中查找
			high = mid - 1;
		}
		else {
			//说明需要在R[mid+1,....high]中查找
			low = mid + 1;
		}

	}

	return 0;
}

//二叉排序树的基本算法
BTNode * BSTSearch(BTNode * bt, int key) {

	if (bt == NULL) {
	
		return NULL;
	}
	else {
	
		//等于根节点中的关键字，查找成功，返回关键字所在结点指针
		if (bt->key == key) {
			
			return bt;
		}
		else if(key<bt->key)
		{
			//小于根节点中的关键字时就到左子数中查找
			return BSTSearch(bt->lchild, key);
		}
		else {
			
			//大于根节点中的关键字时就到右子数中查找
			return BSTSearch(bt->rchild, key);
		}
	}


}


//二叉排序树的插入关键字的算法
int BSTInsert(BTNode *&bt, int key) {
	
	//当前为空指针说明找到插入位置(空指针)，创建新节点进行插入
	if (bt == NULL) {
	
		bt = (BTNode *)malloc(sizeof(BTNode));

		bt->lchild = bt->rchild = NULL;

		bt->key = key;

		return 1;
	
	}
	else {
		
		//关键字已存在
		if (key == bt->key) {
			
			return 0;
		}
		else if (key < bt->key) {
		
			//左子树寻找插入位置
			return BSTInsert(bt->lchild, key);
		}
		else {
		
			//右子树寻找插入位置
			return BSTInsert(bt->rchild, key);
		}
	
	}

}

//二叉排序树的构造
//二叉排序树构造只需要建一颗空树，然后将关键字逐个插入到空树中即可构造
//一颗二叉排序树
void CreateBST(BTNode *&bt, int key[], int n) {
	
	int i;

	bt = NULL;

	for (i = 0; i < n; i++) {
	
		BSTInsert(bt, key[i]);
	}


}

//假设INF为已定义的常量，它小于树中的任何值
int predt = -1;

//判断给定的二叉树是否是二叉排序树，原理对给定的二叉树进行中序遍历
//如果能保证前一个值不比后一个值大，则说明该二叉树是一颗二叉排序树
int judBST(BTNode *bt) {

	int b1, b2;

	if (bt == NULL) {
		
		//空树是二叉排序树
		return 1;
	}
	else {
	
		//递归判断左子树是否是二叉排序树 先从左子树的最后一位访问
		b1 = judBST(bt->lchild);

		
		//左子树不是二叉排序树或者前一个值predit大于后一个值则不是二叉排序树
		if (b1 == -2 || predt > bt->key) {
			
			return -2;
		}

		printf("%d,", bt->key);

		//将要访问右子树的根的时候，predt记录下当前节点的根的值
		predt = bt->key;

		//中间整个过程可以看作是visit访问

		//递归判断右子树是否为二叉排序树
		b2 = judBST(bt->rchild);



		return b2;
	
	}


}