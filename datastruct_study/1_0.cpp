#include <iostream>
using namespace std;

//int main() {
//	void f(int &x);
//	void f1(int *&x);
//	int a = 0;
//	int * b = &a;
//	f1(b);
//	printf("%d",a);
//}

//��ͨ�����������Ϳ��Ըı�ʵ�ε�ֵ
void f(int &x) {
	x++;
}

//�������ı�����ָ���б��������ں�������Ҫ�Դ����ֵ���иı�
//��Ҫ����д��(ָ���������)
void f1(int *&x) {
	*x = 2;
}

