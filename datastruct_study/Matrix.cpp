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
