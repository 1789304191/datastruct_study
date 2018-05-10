#ifndef _Matrix_H_

#define _Matrix_H_

#define MAXSIZE 4

//建立三元组 a为稀疏矩阵 b为三元组
void createTrimat(float a[][MAXSIZE], int m, int n, float b[][3]);

//3元组的打印
void print(float b[][3]);

#endif