#include <iostream>
#include "print.h"

//�������
void printInt(int a) {
	printf("\n���Ϊ��%d\n", a);
}

//����ַ���
void printStr(char *p) {
	printf("\n���Ϊ��%s\n", p);
}

//�������
void printArray(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		printf("%d,",a[i]);
	}
}
