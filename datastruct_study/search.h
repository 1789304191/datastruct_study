#ifndef _SEARCH_H_

#define _SEARCH_H_

//分块查找，索引表定义
typedef struct indexElem{

	//假设表内元素为int(该块中最大关键字)
	int key;

	//记录某块中第一个和最后一个元素的位置
	int low, high;

}indexElem;

//indexElem index[100];

//二叉排序树
typedef struct BTNode {

	//关键字
	int key;

	struct BTNode * lchild;

	struct BTNode * rchild;

} BTNode;

//顺序查找法
int search(int a[], int n, int k);

//折半查找法
int Bsearch(int R[], int low, int high, int k);

//二叉排序树的基本算法
BTNode * BSTSearch(BTNode * bt, int key);

//二叉排序树的插入关键字的算法
int BSTInsert(BTNode *&bt, int key);

#endif
