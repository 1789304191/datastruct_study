#ifndef _SORT_H_

#define _SORT_H_

//插入排序 原理每趟将一个待排序的关键字按照其值的大小插入到
//已经排好的部分有序序列的适当位置上
void insetSort(int R[], int n);

//快速排序
void quickSort(int R[], int low, int high);

//选择排序
void selectSort(int R[], int n);


/*
该函数功能是将序列调整为大顶堆。low为第一个非叶子节点的顶点
high为数组元素总数，将每一个非叶子节点循环结束，则可以获得大顶堆
第一个非叶子节点为n/2-1 其左子树为数组序号2i+1,右子树为2i+2
*/
void sift(int R[], int low, int high);

//堆排序函数
void heapSort(int R[], int n);


#endif
