#include <iostream>
#include "Student.h"

//数组的输出
void print_array(int num[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", num[i]);
	}
	printf("\n");
}

/*
如果temp比上一个元素小，则移动一位，然后继续和下一个元素比较并且移动，直到大于
时就将此时的元素的下一个值赋值给temp
*/
void merge_sequence(int a[], int m, int n) {
	int i;
	int j;
	for (i = m; i < m + n; i++) {
		int temp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (temp < a[j]) {
				//如果比temp大，则向后移动一位
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j + 1] = temp;
	}
}
