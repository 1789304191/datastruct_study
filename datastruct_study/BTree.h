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

//�����������Ķ���
typedef struct TBTNode {
	char data;
	//������ǣ����ltag=0��lchild��ָ�����ӵ�ָ��
	//���ltag=1,��lchildΪ������ָ��ǰ�����
	//������ǣ����rtag=0��rchild��ָ���Һ��ӵ�ָ��
	//���rtag=1,��rchildΪ������ָ��ǰ�����
	int ltag, rtag;
	struct TBTNode * lchild;
	struct TBTNode * rchild;
}TBTNode;

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

//���ʽڵ���Ϣ
void visit(BTNode * p);

void visit(TBTNode * p);

//�������Ż������ķǵݹ�ʵ�֣�����
void preOrderNonRecurision(BTNode * p);

//�������Ż������ķǵݹ�ʵ�֣�����
void inOrderNonRecurision(BTNode * p);

//�������Ż������ķǵݹ�ʵ�֣�����
void postOrderNonRecurision(BTNode * p);

//���������������� ���Ҫ�ı�pre��ֵ����Ҫʹ��&���ã�p�Ǹı�ָ�����Բ���Ҫ
void InThread(TBTNode * p, TBTNode * &pre);

//ͨ���������������������������
void creatInThread(TBTNode * root);

//�������µĵ�һ���ڵ���㷨����pΪ��������������������
TBTNode * First(TBTNode *p);

//�����������������У��ڵ�p�������µĺ�̽ڵ�
TBTNode * Next(TBTNode *p);

//������������������
void InOder(TBTNode * root);

//ǰ����������������Ϊ��ǰ�����Է��ʽڵ������ǰ��
void preThread(TBTNode *p, TBTNode *&pre);

//ǰ�������������ı���
void preOrder(TBTNode * root);

//��������������
void postThread(TBTNode *p, TBTNode *&pre);

#endif
