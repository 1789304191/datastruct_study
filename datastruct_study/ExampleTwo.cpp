#include <iostream>
#include "Student.h"

int main() {
	Student * p = createWithHead();
	//���ܸı�p��ָ�����ǿ��Ըı�p��ָ���ֵ
	insertionSortByAscWithHead(p);
	print_(p);
	return 0;
}