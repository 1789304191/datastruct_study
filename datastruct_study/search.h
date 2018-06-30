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

//����������
typedef struct LBTNode {

	//�ؼ���
	int key;

	//�����ӵ�lsize��
	int lsize;

	struct LBTNode * lchild;

	struct LBTNode * rchild;

} LBTNode;

typedef struct BTNodeWithCount {

	//�ؼ���
	int key;

	//��ͬ�ؼ��ֵĸ���
	int count;

	struct BTNodeWithCount * lchild;

	struct BTNodeWithCount * rchild;

} BTNodeWithCount;

//˳����ҷ�
int search(int a[], int n, int k);

//�۰���ҷ�
int Bsearch(int R[], int low, int high, int k);

//�����������Ļ����㷨
BTNode * BSTSearch(BTNode * bt, int key);

//�����������Ĳ���ؼ��ֵ��㷨
int BSTInsert(BTNode *&bt, int key);

//�����������Ĺ���
void CreateBST(BTNode *&bt, int key[], int n);

//�жϸ����Ķ������Ƿ��Ƕ�����������ԭ��Ը����Ķ����������������
//����ܱ�֤ǰһ��ֵ���Ⱥ�һ��ֵ����˵���ö�������һ�Ŷ���������
int judBST(BTNode *bt);

//��ƽ���������ÿ���ڵ�����һ����lsize,�洢�Ѹýڵ�Ϊ�����������ĸ�����1����дһ���㷨����
//���е�k���ڵ��λ��
LBTNode * searchByKey(LBTNode * t, int k);

//������������в���һ���ڵ㣬����ýڵ���������Ѿ����ڣ������н����ͬ�ڵ��count+1,
//���������
int insertBTNodeWithCount(BTNodeWithCount *&p, int key);

#endif
