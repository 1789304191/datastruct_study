#include <iostream>
using namespace std;

//int main() {
//	void f(int &x);
//	void f1(int *&x);
//	void swap1(int *p1, int *p2);
//	int a = 0;
//	int b = 1;
//	int * a1 = &a;
//	int * b1 = &b;
//	swap(a1, b1);
//	printf("%d,%d",*a1,*b1);
//}

//��ͨ�����������Ϳ��Ըı�ʵ�ε�ֵ
void f(int &x) {
	x++;
}

//�������ı�����ָ���б��������ں�������Ҫ�Դ����ֵ���иı�
//��Ҫ����д��(ָ���������)
void f1(int *&x) {
	int c = 3;
	x = &c;
}

/*
	�÷����޷��ı�p1��p2��ʵ��,���ǿ����޸�
*/
void swap1(int *p1, int *p2) {
	int *p;
	p = p1;
	p1 = p2;
	p2 = p;
	
}

/*
	�÷������Ըı�ʵ��p1��p2
*/
void swap2(int *&p1, int *&p2) {
	int *p;
	p = p1;
	p1 = p2;
	p2 = p;

}

