#include <iostream>
#include "BTree.h"
#include "StackAndQueue.h"

//������������������������������
int comp(BTNode * p) {
	int a, b;
	//�����ǰ����������������ΪNULL��ô��Ϊ���ʽ
	if (p->lchild != NULL && p->rchild != NULL) {
		a = comp(p->lchild);
		b = comp(p->rchild);
		return op(a, p->c, b);
	}
	else {
		return p->c - '0';
	}
}