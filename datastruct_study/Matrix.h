#ifndef _Matrix_H_

#define _Matrix_H_

#define MAXSIZE 4

//十字链的普通节点
typedef struct OLNode{ 

	//所在行和列
	int row,col;
	//指向右方的节点的指针
	OLNode * right;
	//指向下方节点的指针
	OLNode * down;
	//稀疏矩阵中的值
	float val;

} OLNode ;

typedef struct CrossList {

	//m为稀疏矩阵的行数，n为稀疏矩阵的列数，k为稀疏矩阵中有多少非0元素
	int m, n,k;

	//指向两个头节点数组的指针
	OLNode * rhead, * chead;

} CrossList ;

//建立三元组 a为稀疏矩阵 b为三元组 m为矩阵的行数，n为矩阵的列数
void createTrimat(float a[][MAXSIZE], int m, int n, float b[][3]);

//3元组的打印
void print(float b[][3]);

//稀疏矩阵的十字链表存储结构，a为稀疏矩阵，m为行数，n为列数，k为非0节点的个数 M为头节点
void ArrayToCrossList(float a[][MAXSIZE],int m,int n,int k, CrossList &M);

#endif