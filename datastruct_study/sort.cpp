#include <iostream>
#include "sort.h"
#include "print.h"


//插入排序 原理每趟将一个待排序的关键字按照其值的大小插入到
//已经排好的部分有序序列的适当位置上
void insetSort(int R[], int n) {

	int i, j;

	int temp;

	for (i = 1; i < n; i++) {
		
		//将待插入的关键字暂存于temp中
		temp = R[i];

		
		j = i - 1;

		//下面这个循环完成了从待排序关键字之前的关键字开始扫描
		//如果大于待排序关键字，则后移一位
		while (j >= 0 && temp < R[j]) {
			
			R[j + 1] = R[j];

			--j;
		
		}

		//找到插入位置，将temp中暂存的待排序插入
		R[j + 1] = temp;
	
	}
	
	printArray(n,R);
}

//快速排序
void quickSort(int R[], int low,int high) {
	
	int temp;

	int i = low, j = high;

	if (low < high) {
		
		temp = R[low];

		//当i和j相等时说明左边比i小，右边比i大
		while (i < j) {
			
			//从右往左，找到一个小于temp的关键字
			while (j > i&&R[j] >= temp) {
			
				--j;
			}
			if (i < j) {
				
				//放在temp左边
				R[i] = R[j];
				++i;
			}
			
			//从左往右扫描，找到一个大于temp的关键字
			while (i < j && R[i] < temp) {
				
				++i;
			}
			if (i < j) {
				
				R[j] = R[i];
				--j;
			}
		
		}
		//将temp放在最终位置
		R[i] = temp;
		
		//递归的对temp左边的关键字进行排序
		quickSort(R, low, i - 1);

		//递归的对temp右边的关键字进行排序
		quickSort(R, i+1, high);
	}

	
}