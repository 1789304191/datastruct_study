#include <iostream>
#include "search.h"
#include "print.h"
#include "SearchTestCase.h"

int main() {
//	
//	int array[6] = { 2,1,0,3,4,5 };
//
//	//1.�۰���ҷ�
//	//printInt(Bsearch(array, 0, 4, 3));
//
//	//2.����������
//	//printInt(BSTSearch(initBTNode(), 3)->key);
//
//	//3.�����������Ĳ����㷨
//	//BTNode * bt = initBTNode();
//	//printInt(BSTInsert(bt, 6));
//
//	//4.�������Ĺ���
//	//BTNode * bt = NULL;
//	//CreateBST(bt, array, 6);
//
//	//5.�ж�һ���������Ƿ��Ƕ���������
//	printInt(judBST(initBTNode()));
//
	//6.��ƽ���������ÿ���ڵ����һ��lleft��ֵ��
	//�洢�Ѹýڵ�Ϊ�����������ĸ�����1�����k���ڵ��λ��
	//LBTNode * lbt = initLBTNode();
	//printInt(searchByKey(lbt, 4)->key); 

	//7.�ڶ����������в���һ���ڵ㣬����Ѵ�����ͬ�ؼ��ֽ��
	//��ôcount���ֵ��1
	//BTNodeWithCount * bt = initBTNodeWithCount();
	//printInt(insertBTNodeWithCount(bt, 5));

	//8.�ж��Ƿ��Ƕ����������Ĳ�������
	Sequence * s = (Sequence *)malloc(sizeof(Sequence));
	Sequence * s1 = (Sequence *)malloc(sizeof(Sequence));
	Sequence * s2 = (Sequence *)malloc(sizeof(Sequence));
	s->elem[0] = 20;
	s->elem[1] = 30;
	s->elem[2] = 90;
	s->elem[3] = 80;
	s->elem[4] = 40;
	s->elem[5] = 50;
	s->elem[6] = 70;
	s->elem[7] = 60;
	s->len = 8;
	printInt(isSearch(*s, *s1, *s2, 60));
}