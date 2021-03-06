#ifndef _SEARCH_H_

#define _SEARCH_H_

#define  MAXSIZE 30

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

//二叉排序树
typedef struct LBTNode {

	//关键字
	int key;

	//新增加的lsize域
	int lsize;

	struct LBTNode * lchild;

	struct LBTNode * rchild;

} LBTNode;

typedef struct BTNodeWithCount {

	//关键字
	int key;

	//相同关键字的个数
	int count;

	struct BTNodeWithCount * lchild;

	struct BTNodeWithCount * rchild;

} BTNodeWithCount;

//待认定的查找序列结构体定义
typedef struct Sequence{
	
	//查找序列数据存储数组
	int elem[MAXSIZE];
	
	//序列实际数据个数
	int len;
}Sequence;

//顺序查找法
int search(int a[], int n, int k);

//折半查找法
int Bsearch(int R[], int low, int high, int k);

//二叉排序树的基本算法
BTNode * BSTSearch(BTNode * bt, int key);

//二叉排序树的插入关键字的算法
int BSTInsert(BTNode *&bt, int key);

//二叉排序树的构造
void CreateBST(BTNode *&bt, int key[], int n);

//判断给定的二叉树是否是二叉排序树，原理对给定的二叉树进行中序遍历
//如果能保证前一个值不比后一个值大，则说明该二叉树是一颗二叉排序树
int judBST(BTNode *bt);

//在平衡二叉树的每个节点增设一个域lsize,存储已该节点为根的左子树的个数加1，编写一个算法，求
//树中第k个节点的位置
LBTNode * searchByKey(LBTNode * t, int k);

//向二叉排序树中插入一个节点，如果该节点的在树中已经存在，则树中结点相同节点的count+1,
//否则将其插入
int insertBTNodeWithCount(BTNodeWithCount *&p, int key);

//判断给定的关键字值序列是否是二叉排序树的查找序列
//将序列s压缩并分解为s1和s2
void reduce(Sequence &s, Sequence &s1, Sequence &s2);

//判断是是否单调递增，s2是否单调递增，s2是否单调递减，且s1的元素值不必x大
//s2的元素值不比x小
int judge(Sequence &s1, Sequence &s2, int x);

//判断s是否是查找序列
int isSearch(Sequence &s,Sequence &s1, Sequence &s2, int x);

#endif
