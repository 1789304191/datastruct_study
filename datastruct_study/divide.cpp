#include <iostream>
#include "divide.h"
#include "print.h"

//�÷��η���ӡ����
void print(int a[], int L, int R) {
	
	if (L > R) {
		
		//˵���ǿ����У�ʲôҲ����
		return;
	}
	else if(L==R)
	{
		printInt(a[L]);
	}
	else
	{
		printInt(a[L]);
		print(a, L + 1, R);
	}


}

//�������һ������divid()�����Խ�a[L.....R]�ֳ������֣�Ԫ��a[L]Ϊ�ֽ���
//С��a[L]��Ԫ������ߣ�����a[L]�����ұ�
int divid(int a[], int L, int R) {
	
}



//����divid������a[L....R]���п�������
void Qsort(int a[], int L, int R) {
	
	int mid;

	//������Ϊ�ջ��߳���Ϊ1ʱ��Ĭ������ʲôҲ����
	if (L >= R) {
		
		return;
	}
	else {
		
		//�ҷֽ��
		mid = divid(a, L, R);
		//��������м������δ���
		Qsort(a, L, mid - 1);
		//���ұ����м������δ���
		Qsort(a, mid + 1, R);
	}


}