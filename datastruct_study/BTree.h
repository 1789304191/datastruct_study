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

//二叉树结构体定义
typedef struct St {

	//层号
	int lno;

	//二叉树节点
	BTNode *p;

} St;

//后续遍历运算
int comp(BTNode * p);

//后续遍历求二叉树的深度
int getDepth(BTNode * p);

//通过先序遍历查找节点
void search(BTNode * p, BTNode * &q, char key);

//通过先序遍历查找第k个节点
void searchBykeyIndexPre(BTNode * p, int num);

//通过中序遍历查找第k个节点
void searchBykeyIndexCenter(BTNode * p, int num);

//通过后序遍历查找第k个节点
void searchBykeyIndexAfter(BTNode * p, int num);

//层次遍历
void level(BTNode *p);

//求二叉树的宽度
int maxNode(BTNode *p);

#endif
