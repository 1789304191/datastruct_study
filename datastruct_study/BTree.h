#ifndef _BTREE_H_

#define _BTREE_H_

//�������Ķ���
typedef struct BTNode {
	//������
	char c;

	//����
	BTNode * lchild;

	//�Һ���
	BTNode * rchild;

} BTNode;

//������������
int comp(BTNode * p);

#endif
