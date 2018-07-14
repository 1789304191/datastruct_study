#ifndef _SORT_H_

#define _SORT_H_

typedef struct OrderLink {

	int num;

	OrderLink * next;

}OrderLink;

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

//将数组里所有取值为负的关键字放在所有取非负值的关键字之前(类似于快速排序)
void ReSort(int R[], int n);

//计数算法page262
void countSort(int a[], int b[],int al,int bl);

//冒泡排序
void bubbleSort(int a[], int al);

//双向冒泡算法
void bubbleSortTwoSide(int a[], int al);

//链表的直接插入法
void linkDirectInsert(int array[],int n, OrderLink *&orderLink);

#endif
