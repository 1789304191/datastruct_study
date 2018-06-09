#include <iostream>
#include "search.h"

//˳����ҷ�
int search(int a[], int n, int k) {
	
	int i;

	for (i = 1; i <= n; i++) {
	
		if (a[i] == k) {
			
			return i;
		}
	}

	return 0;

}


//�۰���ҷ�
int Bsearch(int R[], int low, int high, int k) {

	int mid;

	//���ӱ��ȴ��ڵ���1�ǽ���ѭ��
	while (low <= high) {
	
		//ȡ��ǰ����м�λ��
		mid = (low + high) / 2;
	
		//�ҵ��󷵻�Ԫ�ص�λ��
		if (R[mid] == k) {
			return mid;
		}
		else if(R[mid]>k)
		{
			//˵����Ҫ��R[low.....,mid-1]�в���
			high = mid - 1;
		}
		else {
			//˵����Ҫ��R[mid+1,....high]�в���
			low = mid + 1;
		}

	}

	return 0;
}

//�����������Ļ����㷨
BTNode * BSTSearch(BTNode * bt, int key) {

	if (bt == NULL) {
	
		return NULL;
	}
	else {
	
		//���ڸ��ڵ��еĹؼ��֣����ҳɹ������عؼ������ڽ��ָ��
		if (bt->key == key) {
			
			return bt;
		}
		else if(key<bt->key)
		{
			//С�ڸ��ڵ��еĹؼ���ʱ�͵��������в���
			return BSTSearch(bt->lchild, key);
		}
		else {
			
			//���ڸ��ڵ��еĹؼ���ʱ�͵��������в���
			return BSTSearch(bt->rchild, key);
		}
	}


}


//�����������Ĳ���ؼ��ֵ��㷨
int BSTInsert(BTNode *&bt, int key) {
	
	//��ǰΪ��ָ��˵���ҵ�����λ��(��ָ��)�������½ڵ���в���
	if (bt == NULL) {
	
		bt = (BTNode *)malloc(sizeof(BTNode));

		bt->lchild = bt->rchild = NULL;

		bt->key = key;

		return 1;
	
	}
	else {
		
		//�ؼ����Ѵ���
		if (key == bt->key) {
			
			return 0;
		}
		else if (key < bt->key) {
		
			//������Ѱ�Ҳ���λ��
			return BSTInsert(bt->lchild, key);
		}
		else {
		
			//������Ѱ�Ҳ���λ��
			return BSTInsert(bt->rchild, key);
		}
	
	}

}

//�����������Ĺ���
//��������������ֻ��Ҫ��һ�ſ�����Ȼ�󽫹ؼ���������뵽�����м��ɹ���
//һ�Ŷ���������
void CreateBST(BTNode *&bt, int key[], int n) {
	
	int i;

	bt = NULL;

	for (i = 0; i < n; i++) {
	
		BSTInsert(bt, key[i]);
	}


}

//����INFΪ�Ѷ���ĳ�������С�����е��κ�ֵ
int predt = -1;

//�жϸ����Ķ������Ƿ��Ƕ�����������ԭ��Ը����Ķ����������������
//����ܱ�֤ǰһ��ֵ���Ⱥ�һ��ֵ����˵���ö�������һ�Ŷ���������
int judBST(BTNode *bt) {

	int b1, b2;

	if (bt == NULL) {
		
		//�����Ƕ���������
		return 1;
	}
	else {
	
		//�ݹ��ж��������Ƿ��Ƕ��������� �ȴ������������һλ����
		b1 = judBST(bt->lchild);

		
		//���������Ƕ�������������ǰһ��ֵpredit���ں�һ��ֵ���Ƕ���������
		if (b1 == -2 || predt > bt->key) {
			
			return -2;
		}

		printf("%d,", bt->key);

		//��Ҫ�����������ĸ���ʱ��predt��¼�µ�ǰ�ڵ�ĸ���ֵ
		predt = bt->key;

		//�м��������̿��Կ�����visit����

		//�ݹ��ж��������Ƿ�Ϊ����������
		b2 = judBST(bt->rchild);



		return b2;
	
	}


}