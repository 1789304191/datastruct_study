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
