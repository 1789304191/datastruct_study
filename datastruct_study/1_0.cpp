#include <stdio.h>

int main() {
	void f(int &x);
	void f1(int *&x);
	int a = 0;
	int * p = &a;
	//f(a);
	f1(p);
	printf("%d", p);
}

//��ͨ�����������Ϳ��Ըı�ʵ�ε�ֵ
void f(int &x) {
	x++;
}

//�������ı�����ָ���б��������ں�������Ҫ�Դ����ֵ���иı�
//��Ҫ����д��(ָ���������)
void f1(int *&x) {
	x++;
}

