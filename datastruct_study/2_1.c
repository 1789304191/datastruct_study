#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAXSIZE 100
typedef struct {
	int num[MAXSIZE];
	int length;
} SqlList;


int main() {
	void print_array(int num[], int n);
	void sort_array(SqlList * L);
	int findElem(SqlList *L, int num);
	void insertArray(SqlList *L, int num, int i);
	SqlList sqlList;
	SqlList *p=&sqlList;
	p->length = 10;
	//随机因子
	srand((int)time(0));
	for (int i = 0; i <= 10; i++) {
		p->num[i] = rand() % 100;
	}
	printf("原数组：\n");
	print_array(p->num, p->length);
	sort_array(p);
	printf("排序之后：\n");
	print_array(p->num, p->length);
	int a = rand() % 100;
	printf("\n随机数为:%d\n", a);
	printf("\n将要插入的位置:%d\n", findElem(p,a));
	insertArray(p, a, findElem(p, a));
	printf("\n插入之后:\n");
	print_array(p->num, p->length);
}


void insertArray(SqlList *L,int num,int i) {
	if (i == -1) {
		L->num[L->length] = num;
	}
	else {
		for (int j= L->length-1; j >= i; j--) {
			L->num[j + 1] = L->num[j];
		}
		L->num[i] = num;
	}
	L->length = L->length + 1;
}

int findElem(SqlList *L,int num) {
	int i=0;
	for (i = 0; i < L->length; i++) {
		if (L->num[i] > num) {
			return i;
		}
	}
	return -1;
}

/*
	数组的打印
*/
void print_array(int num[],int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", num[i]);
	}
	printf("\n");
}

/*
	数组的排序
*/
void sort_array(SqlList *L) {
	for (int i = 0; i < L->length; i++) {
		for (int j = 0;j<= L->length -i-1; j++) {
			if (L->num[j] > L->num[j+1]) {
				int temp=L->num[j+1];
				L->num[j+1] = L->num[j];
				L->num[j] = temp;
				print_array(L->num, L->length);
			}
		}
	}
}