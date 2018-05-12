#include <iostream>
#include "Matrix.h"

//������Ԫ�� aΪϡ����� bΪ��Ԫ��
void createTrimat(float a[][MAXSIZE], int m, int n, float b[][3]) {
	int k = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0) {
				b[k][0] = a[i][j];
				b[k][1] = i;
				b[k][2] = j;
				k++;
			}
		}
	}
	//�ж��ٷ���Ԫ��
	b[0][0] = k - 1;
	//����
	b[0][1] = m;
	//����
	b[0][2] = n;
}

//3Ԫ��Ĵ�ӡ
void print(float b[][3]) {
	int k = 1;
	for (int i = 0; i < b[0][1]; i++) {
		for (int j = 0; j < b[0][2];j++) {
			if (i == (int)b[k][1] && j == (int)b[k][2]) {
				printf("%d\n", (int)b[k][0]);
				k++;
			}
		}
	}
}


void ArrayToCrossList(float a[][MAXSIZE], int m, int n, int k, CrossList &M) {
	//1.��ֵͷ�ڵ�����кͷ�0����
	M.m = m;
	M.n = n;
	M.k = k;

	//2.����ͷ�ڵ�����ռ�����Ҫ��m��n,���ص�������0��λ�õĵ�ַ
	M.rhead = (OLNode *)malloc(sizeof(OLNode)*m);
	M.chead = (OLNode *)malloc(sizeof(OLNode)*n);

	//3.��ͷ�ڵ������right��downָ���ÿ�
	for (int i = 0; i < m; i++) {
		M.rhead[i].right = NULL;
		M.rhead[i].down = NULL;
	}

	for (int j = 0; j < n; j++) {
		M.chead[j].right = NULL;
		M.chead[j].down = NULL;
	}

	//4.�ж�ϡ������е�ֵ�Ƿ�Ϊ0�������Ϊ0�򴴽���ͨ�ڵ�
	OLNode * temp_r;
	OLNode * temp_c;
	for (int i = 0; i < m; i++) {
		//��ʱָ��
		temp_r = &(M.rhead[i]);
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0) {
				OLNode *p = NULL;
				p = (OLNode *)malloc(sizeof(OLNode));
				p->col = j;
				p->row = i;
				p->val = a[i][j];
				p->down = NULL;
				p->right = NULL;
				//��ָ��p
				temp_r->right = p;
				temp_r = p;
				//��ָ��p
				temp_c = &(M.chead[j]);
				temp_c->down = p;
				temp_c = p;
			}
		}
	}
}