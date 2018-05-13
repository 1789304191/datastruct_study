#ifndef _BTREE_H_

#define _BTREE_H_

//二叉树的定义
typedef struct BTNode {
	//数据域
	char c;

	//左孩子
	BTNode * lchild;

	//右孩子
	BTNode * rchild;

} BTNode;

//后续遍历运算
int comp(BTNode * p);

#endif
