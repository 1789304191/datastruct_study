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


//选择排序
void selectSort(int R[], int n) {
	
	int i, j, k;
	
	int temp;

	for (i = 0; i < n; ++i) {
		
		k = i;

		//从无序序列中挑选最小关键字
		for (j = i + 1; j < n; ++j) {
			
			if (R[k] > R[j]) {
				
				k = j;
			}
		}

		//最小关键字与无序序列第一个关键字交换
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	
	}

	printArray(8, R);
}


/*
该函数功能是将序列调整为大顶堆。low为第一个非叶子节点的顶点
high为数组元素总数，将每一个非叶子节点循环结束，则可以获得大顶堆
第一个非叶子节点为n/2-1 其左子树为数组序号2i+1,右子树为2i+2
*/
void sift(int R[], int i, int high) {

	//先取出当前元素i
	int temp = R[i];

	//从i结点的左子结点开始，也就是2i+1处开始
	for (int k = i * 2 + 1; k<high; k = k * 2 + 1) {

		//如果左子结点小于右子结点，k指向右子结点
		if (k + 1<high && R[k]<R[k + 1]) {
			k++;
		}

		//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
		if (R[k] >temp) {
			R[i] = R[k];
			i = k;
		}
		else {
			break;
		}
	}
	//将temp值放到最终的位置
	R[i] = temp;

}

//堆排序函数
void heapSort(int R[], int n) {
	
	int i;
	int temp;

	//建立大顶堆
	for (i = n / 2 - 1; i >= 0; i--) {
		
		//循环非叶子节点
		sift(R, i, n);
	}

	for (i = n-1; i > 0; i--) {
		
		//换成根节点的关键字，将其放入最终位置
		temp = R[0];
		R[0] = R[i];

		//R[n]为数组最大的元素
		R[i] = temp;

		//在减少了一个关键字的无序序列中进行调整
		//因为值根节点不符合大顶堆的规则，所以只需要对根节点进行调整
		sift(R, 0, i);
	}

}