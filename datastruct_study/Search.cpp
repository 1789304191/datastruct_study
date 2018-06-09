#include <iostream>
#include "search.h"

//顺序查找法
int search(int a[], int n, int k) {
	
	int i;

	for (i = 1; i <= n; i++) {
	
		if (a[i] == k) {
			
			return i;
		}
	}

	return 0;

}


//折半查找法
int Bsearch(int R[], int low, int high, int k) {

	int mid;

	//当子表长度大于等于1是进行循环
	while (low <= high) {
	
		//取当前表的中间位置
		mid = (low + high) / 2;
	
		//找到后返回元素的位置
		if (R[mid] == k) {
			return mid;
		}
		else if(R[mid]>k)
		{
			//说明需要在R[low.....,mid-1]中查找
			high = mid - 1;
		}
		else {
			//说明需要在R[mid+1,....high]中查找
			low = mid + 1;
		}

	}

	return 0;
}