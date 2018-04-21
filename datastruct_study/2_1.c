#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAXSIZE 100
typedef struct Student{
	int num[MAXSIZE];
	int length;
} SqlList;


//int main() {
//	void print_array(int num[], int n);
//	void sort_array(SqlList * L);
//	int findElem(SqlList *L, int num);
//	void insertArray(SqlList *L, int num, int i);
//	void  deleteElment(SqlList *L, int p, int *e);
//	SqlList sqlList;
//	SqlList *p=&sqlList;
//	p->length = 10;
//	//�������
//	srand((int)time(0));
//	for (int i = 0; i <= 10; i++) {
//		p->num[i] = rand() % 100;
//	}
//	printf("ԭ���飺\n");
//	print_array(p->num, p->length);
//	sort_array(p);
//	printf("����֮��\n");
//	print_array(p->num, p->length);
//	int p1;
//	int e;
//	scanf_s("\n%d", &p1);
//	deleteElment(p, p1, &e);
//	printf("\nɾ��֮��%d\n",e);
//	print_array(p->num, p->length);
//	/*int a = rand() % 100;
//	printf("\n�����Ϊ:%d\n", a);
//	printf("\n��Ҫ�����λ��:%d\n", findElem(p,a));
//	insertArray(p, a, findElem(p, a));
//	printf("\n����֮��:\n");
//	print_array(p->num, p->length);*/
//}

/*
	����Ĳ���
*/
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

/*
	����Ĳ���
*/
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
	����Ĵ�ӡ
*/
void print_array(int num[],int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", num[i]);
	}
	printf("\n");
}

/*
	���������
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

/*
	�����ɾ������ֵ��ֵ��e
*/
void  deleteElment(SqlList *L,int p,int *e) {
	*e = L->num[p];
	for (int i = p; i < L->length; i++) {
		 L->num[i]=L->num[i + 1];
	}
	L->length = L->length - 1;
}