#include <iostream>
#include "sort.h"
#include "print.h"

int main() {
	int array[8] = { 49,38,65,97,76,13,27,49 };

	//1.ֱ�Ӳ�������
	//insetSort(array, 8);

	//2.��������
	//quickSort(array, 0, 7);
	//printArray(8, array);

	//3.ѡ������
	//selectSort(array, 8);

	//4.������ʼ��
	//for (int i = 3; i >= 0; --i) {
	//	sift(array, i, 8);
	//}
	//printArray(8,array);

	//5.������
	heapSort(array, 8);
	printArray(8,array);

}