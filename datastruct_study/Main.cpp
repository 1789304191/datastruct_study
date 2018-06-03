#include <iostream>
#include "sort.h"
#include "print.h"

int main() {
	int array[8] = { 49,38,65,97,76,13,27,49 };

	//1.直接插入排序
	//insetSort(array, 8);

	//2.快速排序
	//quickSort(array, 0, 7);
	//printArray(8, array);

	//3.选择排序法
	selectSort(array, 8);

}