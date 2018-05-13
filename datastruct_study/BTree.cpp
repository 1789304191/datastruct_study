#include <iostream>
#include "BTree.h"
#include "StackAndQueue.h"

//全局计数变量
int COUNT = 0;

//后续遍历左子树，后续遍历右子数
int comp(BTNode * p) {
	int a, b;
	//如果当前左子树和右子数不为NULL那么则为表达式
	if (p->lchild != NULL && p->rchild != NULL) {
		a = comp(p->lchild);
		b = comp(p->rchild);
		return op(a, p->c, b);
	}
	else {
		return p->c - '0';
	}
}

//后续遍历求二叉树的深度
int getDepth(BTNode * p) {

	if (p == NULL) {
		return 0;
	}
	else {

		int LD = getDepth(p->lchild);

		int RD = getDepth(p->rchild);

		return (LD > RD ? LD : RD) + 1;
	}
	
}

//通过先序遍历查找节点
void search(BTNode * p, BTNode * &q, char key) {
	if (p != NULL) {
		if (p->c == key) {
			q = p;
		}
		else {
			search(p->lchild, q, key);
			//如果在左子树查到了，就不查右子树
			if (q == NULL) {
				search(p->rchild, q, key);
			}
		}
	}
}

//通过先序遍历查找第k个节点
void searchBykeyIndexPre(BTNode * p, int num) {

	if (p != NULL) {
		COUNT++;
		if (COUNT == num) {
			printf("%c", p->c);
		}
		if (COUNT <= num) {
			searchBykeyIndexPre(p->lchild, num);
			searchBykeyIndexPre(p->rchild, num);
		}
	}
}

//通过中序遍历查找第k个节点
void searchBykeyIndexCenter(BTNode * p, int num) {

	if (p != NULL) {

		searchBykeyIndexCenter(p->lchild, num);

		COUNT++;
		if (COUNT == num) {
			printf("%c", p->c);
		}

		searchBykeyIndexCenter(p->rchild, num);
	}
}

//通过后序遍历查找第k个节点
void searchBykeyIndexAfter(BTNode * p, int num) {

	if (p != NULL) {

		searchBykeyIndexAfter(p->lchild, num);

		searchBykeyIndexAfter(p->rchild, num);

		COUNT++;

		if (COUNT == num) {
			printf("%c", p->c);
		}
	}
}


//层次遍历
void level(BTNode *p) {
	//队首，队尾
	int front, rear;

	//定义一个循环队列
	BTNode *que[MAXSIZE];

	//队列为空
	front = rear = 0;

	//出队节点
	BTNode *q;

	if (p != NULL) {

		//根节点入队
		rear = (rear + 1) % MAXSIZE;
		que[rear] = p;

		//当队列不为空
		while (front != rear) {
			
			//头节点出对
			front = (front + 1) % MAXSIZE;
			q = que[front];

			//访问头节点
			printf("%c\n", q->c);

			//如果左子数不为空，则左子树的根节点入队
			if (q->lchild != NULL) {
				rear = (rear + 1) % MAXSIZE;
				que[rear] = q->lchild;
			}

			//如果右子数不为空，则右子树的根节点入队
			if (q->rchild != NULL) {
				rear = (rear + 1) % MAXSIZE;
				que[rear] = q->rchild;
			}
		}
	}
}

//求二叉树的宽度
int maxNode(BTNode *p) {
	
	//1.先定义一个队列，队列中的每一个结构体包含一个节点和该节点的层号
	St que[MAXSIZE];

	//队首，队尾
	int front, rear;

	//当前节点的层号
	int LNO;

	//初始化队列(为空)
	front = rear = 0;

	//出队节点
	BTNode *q;

	if (p != NULL) {

		//入队
		++rear;
		//树根入队
		que[rear].p = p;
		//树根所在层号设置为1
		que[rear].lno = 1;

		//当队列不为空
		while (rear != front) {
			
			//树根出队
			++front;
			q = que[front].p;
			LNO = que[front].lno;

			//如果左孩子不为NULL
			if (q->lchild != NULL) {
				//进栈
				++rear;
				que[rear].p = q->lchild;
				//层号加1 即等于上层
				que[rear].lno = LNO + 1;
			}

			//如果右孩子不为NULL
			if (q->rchild != NULL) {
				++rear;
				que[rear].p = q->rchild;
				que[rear].lno = LNO + 1;
			}
		}

		//记录最大宽度
		int max = 0;

		//循环结束后LNO为最大层数
		//下面求出相同层号最大的元素就是宽度
		for (int i = 1; i < LNO; i++) {
			//记录相同层号的元素
			int n = 0;
			//这里j等于1是因为que是从第一个位置开始入队的
			for (int j = 1; j <= rear; j++) {
				if (que[j].lno == i) {
					n++;
				}
			}
			if (n > max) {
				max = n;
			}
		}
		return max;
	}
	else {
		return 0;
	}


}

void visit(BTNode * p) {
	//访问头节点
	printf("%c\n", p->c);
}

//二叉树优化遍历的非递归实现(先序)
void preOrderNonRecurision(BTNode * p) {
	if (p != NULL) {
		
		//定义一个容纳节点的栈
		BTNode *stack[MAXSIZE];

		//初始化栈
		int top = -1;

		//出栈节点
		BTNode *q;

		//根节点入栈
		stack[++top] = p;

		//当栈中不为空时
		while (top != -1) {

			//出栈
			q = stack[top--];

			//访问节点
			visit(q);

			//如果右孩子存在，右孩子先入栈，因为栈是先进后出，而本方法是先序
			if (q->rchild != NULL) {
				//这里不能是top++
				stack[++top] = q->rchild;
			}

			//如果左孩子存在，左孩子入栈
			if (q->lchild != NULL) {
				stack[++top] = q->lchild;
			}
		}
	
	}
	
}

//二叉树优化遍历的非递归实现（中序）
void inOrderNonRecurision(BTNode * bt) {

	if (bt != NULL) {
		
		//1.初始化栈
		BTNode *stack[MAXSIZE];
		int top = -1;

		//2.出栈元素
		BTNode * p;
		p = bt;

		while (top != -1 || p != NULL) {
			
			//先入栈根节点，如果左孩子存在则左孩子入栈
			while (p != NULL) {
				stack[++top] = p;
				p = p->lchild;
			}

			if (top != -1) {
				//此时没有左孩子则出栈
				p = stack[top--];
				visit(p);
				//检查是否有右孩子，如果有则入栈
				p = p->rchild;

				/*
				举例   1
					2		4
				3		5
				中序输出为 3，2，5，1，4
				因为最后输出1时，栈为空，所以需要判断p是否为空
				来使循环继续

				总结：1.先左孩子入栈
					  2.然后左孩子出栈，判断是否有右孩子，有的话，右孩子进栈
					  3.右孩子出栈，然后根节点出栈 此时栈为空。
					  4.右孩子进栈，右孩子出栈
				*/
			}
		}
	
	}
}

//二叉树优化遍历的非递归实现（后序）
void postOrderNonRecurision(BTNode * bt) {
	if (bt != NULL) {
		//1.初始化两个栈
		
		//先序栈
		BTNode * stack1[MAXSIZE];
		int top1 = -1;

		//逆后续栈
		BTNode * stack2[MAXSIZE];
		int top2 = -1;

		//出栈元素
		BTNode *p = NULL;

		//根节点入栈
		stack1[++top1] = bt;

		//当栈不为空
		while (top1 != -1) {
			
			//先序栈出栈元素
			p = stack1[top1--];
			
			//逆后续栈进栈
			stack2[++top2] = p;

			//如果右孩子不为NULL则进栈，之前先序是右孩子先进，因为栈是先进后出
			//这里是与先序栈的出别，逆后序刚好相反
			if (p->lchild != NULL) {
				stack1[++top1] = p->lchild;
			}
			if (p->rchild != NULL) {
				stack1[++top1] = p->rchild;
			}
			//到此完成了stack1的出栈，和逆后续的进栈
			//而后续与逆后续栈的元素进行出栈操作就可以了
		}

		while (top2 != -1) {
			//出栈的序列即为后序遍历序列
			visit(stack2[top2--]);
		}
	}
	
}