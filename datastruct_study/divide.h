#ifndef _divide_H_

#define _divide_H_

//用分治法打印数组
void print(int a[], int L, int R);

//假设存在一个函数divid()，可以将a[L.....R]分成两部分，元素a[L]为分界线
//小于a[L]的元素在左边，大于a[L]的在右边
int divid(int a[], int L, int R);

//利用divid函数对a[L....R]进行快速排序
void Qsort(int a[], int L, int R);

#endif
#pragma once
