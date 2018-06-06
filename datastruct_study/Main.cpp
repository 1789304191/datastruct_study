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
	//selectSort(array, 8);

	//4.建立初始堆
	//for (int i = 3; i >= 0; --i) {
	//	sift(array, i, 8);
	//}
	//printArray(8,array);

	//5.堆排序
	//heapSort(array, 8);
	//printArray(8,array);

	//6.利用快速排序原则将数组正数和负数归类
	//int R[8] = { 49,-38,-65,-97,-76,13,27,49 };
	//ReSort(R, 8);
	//printArray(8, R);
}