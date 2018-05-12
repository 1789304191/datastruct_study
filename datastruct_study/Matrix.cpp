#include <iostream>
#include "Matrix.h"

//建立三元组 a为稀疏矩阵 b为三元组
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
	//有多少非零元素
	b[0][0] = k - 1;
	//行数
	b[0][1] = m;
	//列数
	b[0][2] = n;
}

//3元组的打印
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
	//1.赋值头节点的列行和非0数据
	M.m = m;
	M.n = n;
	M.k = k;

	//2.申请头节点数组空间所有要乘m和n,返回的是数组0的位置的地址
	M.rhead = (OLNode *)malloc(sizeof(OLNode)*m);
	M.chead = (OLNode *)malloc(sizeof(OLNode)*n);

	//3.将头节点数组的right和down指针置空
	for (int i = 0; i < m; i++) {
		M.rhead[i].right = NULL;
		M.rhead[i].down = NULL;
	}

	for (int j = 0; j < n; j++) {
		M.chead[j].right = NULL;
		M.chead[j].down = NULL;
	}

	//4.判断稀疏矩阵中的值是否为0，如果不为0则创建普通节点
	OLNode * temp_r;
	OLNode * temp_c;
	for (int i = 0; i < m; i++) {
		//临时指针
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
				//行指向p
				temp_r->right = p;
				temp_r = p;
				//列指向p
				temp_c = &(M.chead[j]);
				temp_c->down = p;
				temp_c = p;
			}
		}
	}
}