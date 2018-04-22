#include <iostream>
#include "Student.h"

//��������
void print_array(int num[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", num[i]);
	}
	printf("\n");
}

/*
���temp����һ��Ԫ��С�����ƶ�һλ��Ȼ���������һ��Ԫ�رȽϲ����ƶ���ֱ������
ʱ�ͽ���ʱ��Ԫ�ص���һ��ֵ��ֵ��temp
*/
void merge_sequence(int a[], int m, int n) {
	int i;
	int j;
	for (i = m; i < m + n; i++) {
		int temp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (temp < a[j]) {
				//�����temp��������ƶ�һλ
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j + 1] = temp;
	}
}
