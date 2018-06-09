#ifndef _SEARCH_H_

#define _SEARCH_H_

//�ֿ���ң���������
typedef struct indexElem{

	//�������Ԫ��Ϊint(�ÿ������ؼ���)
	int key;

	//��¼ĳ���е�һ�������һ��Ԫ�ص�λ��
	int low, high;

}indexElem;

//indexElem index[100];

//����������
typedef struct BTNode {

	//�ؼ���
	int key;

	struct BTNode * lchild;

	struct BTNode * rchild;

} BTNode;

//˳����ҷ�
int search(int a[], int n, int k);

//�۰���ҷ�
int Bsearch(int R[], int low, int high, int k);

//�����������Ļ����㷨
BTNode * BSTSearch(BTNode * bt, int key);

//�����������Ĳ���ؼ��ֵ��㷨
int BSTInsert(BTNode *&bt, int key);

#endif
