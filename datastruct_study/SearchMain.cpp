#include <iostream>
#include "search.h"
#include "print.h"
#include "SearchTestCase.h"

int main() {
	
	int array[6] = { 2,1,0,3,4,5 };

	//1.�۰���ҷ�
	//printInt(Bsearch(array, 0, 4, 3));

	//2.����������
	//printInt(BSTSearch(initBTNode(), 3)->key);

	//3.�����������Ĳ����㷨
	//BTNode * bt = initBTNode();
	//printInt(BSTInsert(bt, 6));

	//4.�������Ĺ���
	//BTNode * bt = NULL;
	//CreateBST(bt, array, 6);

	//5.�ж�һ���������Ƿ��Ƕ���������
	printInt(judBST(initBTNode()));

}