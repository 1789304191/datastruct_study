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

//�������ṹ�嶨��
typedef struct St {

	//���
	int lno;

	//�������ڵ�
	BTNode *p;

} St;

//������������
int comp(BTNode * p);

//��������������������
int getDepth(BTNode * p);

//ͨ������������ҽڵ�
void search(BTNode * p, BTNode * &q, char key);

//ͨ������������ҵ�k���ڵ�
void searchBykeyIndexPre(BTNode * p, int num);

//ͨ������������ҵ�k���ڵ�
void searchBykeyIndexCenter(BTNode * p, int num);

//ͨ������������ҵ�k���ڵ�
void searchBykeyIndexAfter(BTNode * p, int num);

//��α���
void level(BTNode *p);

//��������Ŀ��
int maxNode(BTNode *p);

#endif
