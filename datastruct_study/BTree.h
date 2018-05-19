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

//线索二叉树的定义
typedef struct TBTNode {
	char data;
	//线索标记，如果ltag=0，lchild是指向左孩子的指针
	//如果ltag=1,则lchild为线索，指向前驱结点
	//线索标记，如果rtag=0，rchild是指向右孩子的指针
	//如果rtag=1,则rchild为线索，指向前驱结点
	int ltag, rtag;
	struct TBTNode * lchild;
	struct TBTNode * rchild;
}TBTNode;

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

//访问节点信息
void visit(BTNode * p);

void visit(TBTNode * p);

//二叉树优化遍历的非递归实现（先序）
void preOrderNonRecurision(BTNode * p);

//二叉树优化遍历的非递归实现（中序）
void inOrderNonRecurision(BTNode * p);

//二叉树优化遍历的非递归实现（后序）
void postOrderNonRecurision(BTNode * p);

//线索二叉树（中序） 如果要改变pre的值，需要使用&引用，p是改变指向所以不需要
void InThread(TBTNode * p, TBTNode * &pre);

//通过中序遍历建立中序线索二叉树
void creatInThread(TBTNode * root);

//求中序下的第一个节点的算法（以p为根的中序线索二叉树）
TBTNode * First(TBTNode *p);

//在中序线索二叉树中，节点p在中序下的后继节点
TBTNode * Next(TBTNode *p);

//遍历中序线索二叉树
void InOder(TBTNode * root);

//前序线索二叉树，因为是前序，所以访问节点放在最前面
void preThread(TBTNode *p, TBTNode *&pre);

//前序线索二叉树的遍历
void preOrder(TBTNode * root);

//后续线索二叉树
void postThread(TBTNode *p, TBTNode *&pre);

#endif
