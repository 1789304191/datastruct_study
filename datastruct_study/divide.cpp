#include <iostream>
#include "divide.h"
#include "print.h"

//用分治法打印数组
void print(int a[], int L, int R) {
	
	if (L > R) {
		
		//说明是空序列，什么也不做
		return;
	}
	else if(L==R)
	{
		printInt(a[L]);
	}
	else
	{
		printInt(a[L]);
		print(a, L + 1, R);
	}


}

//假设存在一个函数divid()，可以将a[L.....R]分成两部分，元素a[L]为分界线
//小于a[L]的元素在左边，大于a[L]的在右边
int divid(int a[], int L, int R) {
	
}



//利用divid函数对a[L....R]进行快速排序
void Qsort(int a[], int L, int R) {
	
	int mid;

	//当序列为空或者长度为1时，默认有序，什么也不做
	if (L >= R) {
		
		return;
	}
	else {
		
		//找分界点
		mid = divid(a, L, R);
		//对左边序列继续分治处理
		Qsort(a, L, mid - 1);
		//对右边序列继续分治处理
		Qsort(a, mid + 1, R);
	}


}