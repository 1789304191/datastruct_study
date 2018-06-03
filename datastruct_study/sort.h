#ifndef _SORT_H_

#define _SORT_H_

//插入排序 原理每趟将一个待排序的关键字按照其值的大小插入到
//已经排好的部分有序序列的适当位置上
void insetSort(int R[], int n);

//快速排序
void quickSort(int R[], int low, int high);

//选择排序
void selectSort(int R[], int n);


#endif
