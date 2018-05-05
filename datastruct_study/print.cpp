#include <iostream>
#include "print.h"

//输出整数
void printInt(int a) {
	printf("\n结果为：%d\n", a);
}

//输出字符串
void printStr(char *p) {
	printf("\n结果为：%s\n", p);
}

//输出数组
void printArray(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		printf("%d,",a[i]);
	}
}
