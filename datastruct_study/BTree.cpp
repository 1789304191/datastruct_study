#include <iostream>
#include "BTree.h"
#include "StackAndQueue.h"

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