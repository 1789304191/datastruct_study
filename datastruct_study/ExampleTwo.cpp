#include <iostream>
#include "Student.h"

int main() {
	printf("��һ������\n");
	Student * p1 = createWithHead();
	//���ܸı�p��ָ�����ǿ��Ըı�p��ָ���ֵ
	insertionSortByAscWithHead(p1);
	print_(p1);
	printf("�ڶ�������\n");
	Student * p2 = createWithHead();
	insertionSortByAscWithHead(p2);
	print_(p2);
	printf("ȥ��֮��\n");
	distinct(p1, p2);
	print_(p1);
	return 0;
}